/*
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
 */

#include <stdio.h>

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

    return 0;
}

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
}
