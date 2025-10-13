/*
<<<<<<< HEAD
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
=======
 * Lab 3, Task 2
 * Student Name, Student ID
 *
 * Practice using pointers as function parameters.
 * Implement:
 *   - swap (exchange values of two ints)
 *   - modify_value (multiply given int by 2)
 *
 * Rules:
 *   - Use pointers to modify variables in the caller.
 *   - Demonstrate changes in main.
 *
 * Example:
 *   int a = 5, b = 10;
 *   swap(&a, &b);   // now a = 10, b = 5
 *
 *   modify_value(&a); // now a = 20
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>

<<<<<<< HEAD
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
=======
// Function prototypes
void swap(int *x, int *y);
void modify_value(int *x);

int main(void) {
    int a = 3, b = 7;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After swap: a=%d, b=%d\n", a, b);

    modify_value(&a);
    printf("After modify_value: a=%d\n", a);
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4

    return 0;
}

<<<<<<< HEAD
void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void double_value(int *n) {
    *n = *n * 2;
=======
// Implement functions below
void swap(int *x, int *y) {
    // TODO: swap values using a temporary variable
}

void modify_value(int *x) {
    // TODO: multiply value by 2
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
