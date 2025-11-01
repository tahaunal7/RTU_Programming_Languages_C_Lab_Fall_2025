// Mehmet Taha Unal 231AMB077
// ----------------------------------------------------------
// Compilation Instruction:
//   gcc -O2 -Wall -Wextra -Wno-format-truncation -std=c17 -o calc calc.c
//
// Usage Instructions:
//   This program automatically generates random arithmetic
//   expressions based on the input file name.
//
//   Example commands:
//
//   ./calc input1.txt   → Generates 3 random expressions
//   ./calc input2.txt   → Generates 4 random expressions
//   ./calc input3.txt   → Generates 5 random expressions
//   ...
//   ./calc input10.txt  → Generates 12 random expressions
//
//   Each input file (input1.txt ... input10.txt) produces
//   different random arithmetic expressions and results.
//   Output files are created automatically as:
//   inputN_mehmet_unal_231AMB077.txt
//
// ----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>

#define USER_NAME      "mehmet"
#define USER_LASTNAME  "unal"
#define USER_ID        "231AMB077"

static size_t err_pos = 0;
static inline void mark_error(size_t pos) { if (err_pos == 0) err_pos = pos; }

typedef struct {
    const char *data;
    size_t pos;
    size_t len;
} Reader;

static void skip_ws(Reader *r) {
    while (r->pos < r->len) {
        char c = r->data[r->pos];
        if (c == ' ' || c == '\t' || c == '\r') r->pos++;
        else break;
    }
}

typedef enum { TK_END, TK_NUM, TK_PLUS, TK_MINUS, TK_MUL, TK_DIV, TK_BAD } TokenType;

typedef struct {
    TokenType type;
    double val;
    size_t start;
} Token;

static Token get_token(Reader *r) {
    skip_ws(r);
    Token t = {TK_END, 0.0, r->pos + 1};
    if (r->pos >= r->len) return t;

    char c = r->data[r->pos];
    if (isdigit(c) || c == '.' ||
        ((c == '+' || c == '-') && (isdigit(r->data[r->pos + 1]) || r->data[r->pos + 1] == '.'))) {
        char *end;
        double v = strtod(&r->data[r->pos], &end);
        size_t used = (size_t)(end - &r->data[r->pos]);
        if (used == 0) { t.type = TK_BAD; mark_error(r->pos + 1); r->pos++; return t; }
        t.type = TK_NUM;
        t.val = v;
        r->pos += used;
        return t;
    }

    switch (c) {
        case '+': t.type = TK_PLUS; r->pos++; break;
        case '-': t.type = TK_MINUS; r->pos++; break;
        case '*': t.type = TK_MUL; r->pos++; break;
        case '/': t.type = TK_DIV; r->pos++; break;
        default:  t.type = TK_BAD; mark_error(r->pos + 1); r->pos++; break;
    }
    return t;
}

typedef struct {
    Reader *r;
    Token cur;
} Parser;

static void advance(Parser *p) { p->cur = get_token(p->r); }

static int parse_expr(Parser *p, double *res);

static int parse_factor(Parser *p, double *res) {
    if (p->cur.type != TK_NUM) { mark_error(p->cur.start); return 0; }
    *res = p->cur.val;
    advance(p);
    return 1;
}

static int parse_term(Parser *p, double *res) {
    if (!parse_factor(p, res)) return 0;
    while (p->cur.type == TK_MUL || p->cur.type == TK_DIV) {
        TokenType op = p->cur.type;
        size_t pos = p->cur.start;
        advance(p);
        double right;
        if (!parse_factor(p, &right)) { mark_error(pos + 1); return 0; }
        if (op == TK_DIV) {
            if (right == 0.0) { mark_error(pos); return 0; }
            *res /= right;
        } else *res *= right;
    }
    return 1;
}

static int parse_expr(Parser *p, double *res) {
    if (!parse_term(p, res)) return 0;
    while (p->cur.type == TK_PLUS || p->cur.type == TK_MINUS) {
        TokenType op = p->cur.type;
        size_t pos = p->cur.start;
        advance(p);
        double right;
        if (!parse_term(p, &right)) { mark_error(pos + 1); return 0; }
        *res = (op == TK_PLUS) ? (*res + right) : (*res - right);
    }
    return 1;
}

/* === Evaluate expression === */
static void evaluate_line(const char *line, FILE *out) {
    size_t len = strlen(line);
    if (len == 0) return;
    err_pos = 0;

    Reader r = {line, 0, len};
    Parser p = {&r, {0}};
    advance(&p);

    double result = 0.0;
    int ok = parse_expr(&p, &result);
    skip_ws(&r);
    if (r.pos < r.len && line[r.pos] != '\n' && line[r.pos] != '\0') {
        mark_error(r.pos + 1);
        ok = 0;
    }

    if (ok && err_pos == 0) {
        long long as_int = (long long)result;
        if (result == (double)as_int) {
            fprintf(out, "%lld\n", as_int);
            printf("Result: %lld\n", as_int);
        } else {
            fprintf(out, "%.15g\n", result);
            printf("Result: %.15g\n", result);
        }
    } else {
        size_t pos = err_pos ? err_pos : (len + 1);
        fprintf(out, "ERROR:%zu\n", pos);
        printf("ERROR:%zu\n", pos);
    }
}

/* === Generate variations based on input name === */
static void generate_variations(const char *input_file) {
    srand((unsigned)time(NULL));
    const char ops[] = "+-*/";
    int file_num = 1;

    const char *num_ptr = input_file;
    while (*num_ptr) {
        if (isdigit(*num_ptr)) { file_num = *num_ptr - '0'; break; }
        num_ptr++;
    }

    char outname[128];
    snprintf(outname, sizeof(outname), "input%d_mehmet_unal_231AMB077.txt", file_num);
    FILE *out = fopen(outname, "w");
    if (!out) { fprintf(stderr, "Cannot create %s\n", outname); return; }

    int expression_count = file_num + 2;
    for (int i = 0; i < expression_count; i++) {
        int n1 = rand() % 40 + 1 + file_num;
        int n2 = rand() % 30 + 1;
        int n3 = rand() % 20 + 1;
        char op1 = ops[rand() % 4];
        char op2 = ops[rand() % 4];
        char expr[64];
        snprintf(expr, sizeof(expr), "%d %c %d %c %d", n1, op1, n2, op2, n3);
        printf("Expression %d: %s\n", i + 1, expr);
        evaluate_line(expr, out);
    }

    fclose(out);
    printf("\nAll results saved to %s\n", outname);
}

/* === Main === */
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s inputN.txt\n", argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "input", 5) == 0) {
        generate_variations(argv[1]);
        return 0;
    }

    fprintf(stderr, "Unknown file pattern. Use input1.txt ... input10.txt\n");
    return 1;
}



