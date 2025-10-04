/*
 * Programming Languages - Lab 3 (Task 1)
 * Author: Mehmet Taha Ünal
 * Student No: 231AMB077
 *
 * Topic: Array-based Calculations
 * ----------------------------------
 * Required operations:
 *   • Identify the smallest number
 *   • Identify the largest number
 *   • Compute total sum of all elements
 *   • Compute average as a floating-point value
 *
 * Conditions:
 *   - Every operation must be implemented in a separate function
 *   - Functions should work with integer arrays
 *   - No external libraries (other than stdio and limits)
 *
 * Demonstration Example:
 *   int nums[] = {1, 2, 3, 4, 5};
 *   printf("Min: %d", find_min(nums, 5)); // 1
 *   printf("Max: %d", find_max(nums, 5)); // 5
 *   printf("Sum: %d", calc_sum(nums, 5)); // 15
 *   printf("Avg: %.2f", calc_avg(nums, 5)); // 3.00
 */

#include <stdio.h>
#include <limits.h>

// Function declarations
int find_min(int values[], int count);
int find_max(int values[], int count);
int calc_sum(int values[], int count);
float calc_avg(int values[], int count);

int main(void) {
    int numbers[] = {10, 20, 5, 30, 15};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Minimum: %d\n", find_min(numbers, length));
    printf("Maximum: %d\n", find_max(numbers, length));
    printf("Total: %d\n", calc_sum(numbers, length));
    printf("Average: %.2f\n", calc_avg(numbers, length));

    return 0;
}

// Function definitions
int find_min(int values[], int count) {
    int minVal = INT_MAX;
    for (int i = 0; i < count; i++) {
        if (values[i] < minVal) {
            minVal = values[i];
        }
    }
    return minVal;
}

int find_max(int values[], int count) {
    int maxVal = INT_MIN;
    for (int i = 0; i < count; i++) {
        if (values[i] > maxVal) {
            maxVal = values[i];
        }
    }
    return maxVal;
}

int calc_sum(int values[], int count) {
    int result = 0;
    for (int i = 0; i < count; i++) {
        result += values[i];
    }
    return result;
}

float calc_avg(int values[], int count) {
    int total = calc_sum(values, count);
    return (float)total / count;
}
