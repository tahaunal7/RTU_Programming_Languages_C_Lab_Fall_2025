/*
<<<<<<< HEAD
 * Lab 3 - Task 3
 * Student: Mehmet Taha Ünal
 * Student ID: 231AMB077
 *
 * Topic: Manual String Functions
 * ----------------------------------
 * Implementations:
 *   → my_strlen - calculates the number of visible characters
 *   → my_strcpy - copies text from one string to another
 *
 * Restrictions:
 *   - Do NOT use <string.h> functions
 *   - Work manually with loops or pointers
=======
 * Lab 3, Task 3
 * Student Name, Student ID
 *
 * Implement basic string handling functions.
 * Write your own versions of:
 *   - my_strlen (finds string length)
 *   - my_strcpy (copies string from src to dest)
 *
 * Rules:
 *   - Do not use <string.h> functions for strlen/strcpy.
 *   - Use loops and manual pointer/array access.
 *
 * Example:
 *   char s[] = "hello";
 *   int len = my_strlen(s);   // should return 5
 *
 *   char buffer[100];
 *   my_strcpy(buffer, s);     // buffer now contains "hello"
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>

<<<<<<< HEAD
// Function declarations
int my_strlen(const char *text);
void my_strcpy(char *target, const char *source);

int main(void) {
    char sentence[] = "Programming in C";
    char duplicate[100];

    int length = my_strlen(sentence);
    printf("String length: %d\n", length);

    my_strcpy(duplicate, sentence);
    printf("Copied string: %s\n", duplicate);
=======
// Function prototypes
int my_strlen(const char *str);
void my_strcpy(char *dest, const char *src);

int main(void) {
    // TODO: Test your functions here
    char test[] = "Programming in C";
    char copy[100];

    int len = my_strlen(test);
    printf("Length: %d\n", len);

    my_strcpy(copy, test);
    printf("Copy: %s\n", copy);
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4

    return 0;
}

<<<<<<< HEAD
int my_strlen(const char *text) {
    int count = 0;
    while (*text != '\0') {   // go until null terminator
        count++;
        text++;
    }
    return count;
}

void my_strcpy(char *target, const char *source) {
    while (*source != '\0') { // copy until end
        *target = *source;
        target++;
        source++;
    }
    *target = '\0'; // add null terminator at end
=======
// Implement functions below
int my_strlen(const char *str) {
    // TODO: count characters until '\0'
    return 0; // placeholder
}

void my_strcpy(char *dest, const char *src) {
    // TODO: copy characters until '\0'
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
