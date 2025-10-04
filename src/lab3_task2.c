/*
 * Lab 3 - Task 2
 * Student: Mehmet Taha Ünal
 * Student ID: 231AMB077
 *
 * Topic: Working with Pointers
 * ----------------------------------
 * Implement two simple functions:
 *   • swap_values → exchange two integer values using pointers
 *   • double_value → multiply an integer by 2 using its pointer
 *
 * Rules:
 *   - Functions must modify the original variables.
 *   - No return values, only pointer parameters.
 */

#include <stdio.h>

// Function declarations
void swap_values(int *a, int *b);
void double_value(int *n);

int main(void) {
    int x = 12, y = 45;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap_values(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);

    double_value(&x);
    printf("After doubling x: %d\n", x);

    return 0;
}

void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void double_value(int *n) {
    *n = *n * 2;
}
