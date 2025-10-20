// Mehmet Taha Ünal 231AMB077
// Compile: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c
// Description:
// Fully standalone Python-like arithmetic parser in C.
// Supports +, -, *, /, **, parentheses, floats, and comment lines.
// Writes result to output file and shows it in terminal. No -lm dependency.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_EXPR 10000
#define STUDENT "231AMB077"

// === Custom math functions (no -lm needed) ===
static double my_pow(double base, double exp) {
    double result = 1.0;
    int e = (int)exp;
    if (exp < 0) {
        for (int i = 0; i < -e; i++) result /= base;
    } else {
        for (int i = 0; i < e; i++) result *= base;
    }
    return result;
}

static double my_fabs(double x) { return x < 0 ? -x : x; }
static long long my_llround(double x) { return (long long)(x + (x >= 0 ? 0.5 : -0.5)); }

// === Tokenizer definitions ===
typedef enum {
    TK_NUM, TK_PLUS, TK_MINUS, TK_MUL, TK_DIV, TK_POW,
    TK_LPAREN, TK_RPAREN, TK_END, TK_INVALID
} TokType;

typedef struct {
    TokType kind;
    double val;
    int pos;
} Token;

static const char *src;
static int idx;
static Token current;
static int errpos = 0;

// === Tokenizer ===
static void skip_ws(void) {
    while (src[idx] == ' ' || src[idx] == '\t' || src[idx] == '\r') idx++;
}

static Token next_token(void) {
    skip_ws();
    Token t = { TK_INVALID, 0.0, idx + 1 };
    char c = src[idx];
    if (c == '\0') { t.kind = TK_END; return t; }

    if (isdigit(c) || c == '.') {
        char buf[128]; int b = 0;
        while (isdigit(src[idx]) || src[idx] == '.' ||
               src[idx] == 'e' || src[idx] == 'E' ||
               src[idx] == '+' || src[idx] == '-') {
            if (b < 127) buf[b++] = src[idx];
            idx++;
            if (!isdigit(src[idx]) && src[idx] != '.' &&
                src[idx] != 'e' && src[idx] != 'E' &&
                src[idx] != '+' && src[idx] != '-') break;
        }
        buf[b] = 0;
        t.kind = TK_NUM;
        t.val = strtod(buf, NULL);
        return t;
    }

    if (c == '+') { t.kind = TK_PLUS; idx++; return t; }
    if (c == '-') { t.kind = TK_MINUS; idx++; return t; }
    if (c == '*') {
        if (src[idx+1] == '*') { t.kind = TK_POW; idx += 2; }
        else { t.kind = TK_MUL; idx++; }
        return t;
    }
    if (c == '/') { t.kind = TK_DIV; idx++; return t; }
    if (c == '(') { t.kind = TK_LPAREN; idx++; return t; }
    if (c == ')') { t.kind = TK_RPAREN; idx++; return t; }

    errpos = idx + 1;
    idx++;
    return t;
}

// === Parser prototypes ===
static double parse_expr(void);
static double parse_term(void);
static double parse_power(void);
static double parse_factor(void);

// === Error helper ===
static void fail(int pos) { if (!errpos) errpos = pos; }

// === Grammar ===
static double parse_factor(void) {
    double res = 0.0;
    // Unary plus/minus handling
    if (current.kind == TK_MINUS) {
        current = next_token();
        res = parse_factor();
        return -res;
    }
    if (current.kind == TK_PLUS) { // Unary plus is usually ignored
        current = next_token();
    }

    if (current.kind == TK_NUM) {
        res = current.val;
        current = next_token();
    } else if (current.kind == TK_LPAREN) {
        current = next_token();
        res = parse_expr();
        if (current.kind != TK_RPAREN) fail(current.pos);
        else current = next_token();
    } else fail(current.pos);
    return res;
}


static double parse_power(void) {
    double base = parse_factor();
    if (current.kind == TK_POW) {
        int pos = current.pos;
        current = next_token();
        // Right-associativity: parse_power calls itself
        double expv = parse_power(); 
        if (!errpos) base = my_pow(base, expv);
        else fail(pos);
    }
    return base;
}

static double parse_term(void) {
    double left = parse_power();
    while (current.kind == TK_MUL || current.kind == TK_DIV) {
        TokType op = current.kind;
        int pos = current.pos;
        current = next_token();
        double right = parse_power();
        if (errpos) return 0;
        if (op == TK_MUL) left *= right;
        else {
            if (my_fabs(right) < 1e-15) fail(pos); // Division by zero check
            else left /= right;
        }
    }
    return left;
}

static double parse_expr(void) {
    double left = parse_term();
    while (current.kind == TK_PLUS || current.kind == TK_MINUS) {
        TokType op = current.kind;
        current = next_token();
        double right = parse_term();
        if (errpos) return 0;
        if (op == TK_PLUS) left += right;
        else left -= right;
    }
    return left;
}

// === Evaluator ===
static int evaluate_expression(const char *expr, double *out) {
    src = expr;
    idx = 0;
    errpos = 0;
    current = next_token();
    double val = parse_expr();
    if (!errpos && current.kind != TK_END) fail(current.pos);
    if (errpos) return errpos;
    *out = val;
    return 0;
}

// === File operations ===
static char *read_file(const char *fname) {
    FILE *f = fopen(fname, "r");
    if (!f) return NULL;
    static char buf[MAX_EXPR + 1];
    size_t n = fread(buf, 1, MAX_EXPR, f);
    buf[n] = 0;
    fclose(f);
    return buf;
}

static void ensure_dir(const char *dirname) {
    struct stat st = {0};
    if (stat(dirname, &st) == -1) mkdir(dirname, 0775);
}

static void write_output(const char *infile, double val, int err) {
    ensure_dir("labs_mehmet_taha_231AMB077");
    char outname[256];
    snprintf(outname, sizeof(outname),
             "labs_mehmet_taha_231AMB077/task1_mehmet_taha_unal_%s.txt", STUDENT);
    FILE *f = fopen(outname, "w");
    if (!f) return;
    if (err) fprintf(f, "ERROR:%d\n", err);
    else {
        long long iv = my_llround(val);
        // Custom print logic to display integer results as integers
        if (my_fabs(val - iv) < 1e-12) fprintf(f, "%lld\n", iv);
        else fprintf(f, "%.15g\n", val);
    }
    fclose(f);
}

// === Main ===
int main(int argc, char **argv) {
    // === AUTO MODE: Run built-in tests if no file argument is provided ===
    if (argc == 1) {
        const char *tests[] = {
            "3 + 4 * 2 - (5 / 2)",
            "(8 + 2) / 5 + 3 ** 2",
            "10 / 0",
            "2 ** 3 ** 2",
            "5 * (7 - 2) + 10 / 5",
            NULL
        };
        printf("=== Pythonic Arithmetic Parser (Auto Mode) ===\n");
        for (int i = 0; tests[i]; i++) {
            double val; 
            // Note: Removed the comment handling logic for simple test cases
            int err = evaluate_expression(tests[i], &val);
            
            // Start of output line
            printf("[%d] %s => ", i+1, tests[i]); 
            
            // Outputting the result
            if (err) {
                printf("ERROR:%d\n", err);
            } else {
                long long iv = my_llround(val);
                // Check if the result is an exact integer
                if (my_fabs(val - iv) < 1e-12) {
                    printf("%lld\n", iv);
                } else {
                    // Use format specifier for floating point numbers
                    printf("%.15g\n", val);
                }
            }
        }
        return 0; // Exit after running tests
    }

    // === FILE MODE: Run if a file argument is provided (Original Logic) ===
    printf("=== Pythonic Arithmetic Parser (C version by MTU) ===\n");

    char *expr = read_file(argv[1]);
    if (!expr) { fprintf(stderr, "Cannot open %s\n", argv[1]); return 1; }

    // remove comment lines
    for (char *p = expr; *p; p++) {
        if (*p == '#') while (*p && *p != '\n') *p++ = ' ';
    }

    double val; int err = evaluate_expression(expr, &val);
    if (err) printf("ERROR:%d\n", err);
    else {
        long long iv = my_llround(val);
        if (my_fabs(val - iv) < 1e-12) printf("%lld\n", iv);
        else printf("%.15g\n", val);
    }

    write_output(argv[1], val, err);
    printf("\nResult written to labs_mehmet_taha_231AMB077/\n");
    return 0;
}



