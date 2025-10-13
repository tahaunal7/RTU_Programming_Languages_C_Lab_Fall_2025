/*
<<<<<<< HEAD
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
=======
 * Lab 3, Task 1
 * Student Name, Student ID
 *
 * Implement array algorithms:
 *   - find minimum value
 *   - find maximum value
 *   - calculate sum
 *   - calculate average
 *
 * Rules:
 *   - Write separate functions for each operation.
 *   - Work with int arrays.
 *   - Average should return a float.
 *
 * Example:
 *   int arr[] = {1, 2, 3, 4, 5};
 *   min = array_min(arr, 5); // 1
 *   max = array_max(arr, 5); // 5
 *   sum = array_sum(arr, 5); // 15
 *   avg = array_avg(arr, 5); // 3.0
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>
#include <limits.h>

<<<<<<< HEAD
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
=======
// Function prototypes
int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int main(void) {
    int arr[] = {10, 20, 5, 30, 15};
    int size = 5;

    printf("Min: %d\n", array_min(arr, size));
    printf("Max: %d\n", array_max(arr, size));
    printf("Sum: %d\n", array_sum(arr, size));
    printf("Avg: %.2f\n", array_avg(arr, size));
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4

    return 0;
}

<<<<<<< HEAD
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
=======
// Implement functions below
int array_min(int arr[], int size) {
    // TODO: return smallest element
    int my_min = INT_MAX; //set to max infinity
    for (int i=0;i<size;i++) {
        if (my_min > arr[i]) {
            my_min = arr[i];
        }
    }
    return my_min; // placeholder
}

int array_max(int arr[], int size) {
    // TODO: return largest element
    return 0; // placeholder
}

int array_sum(int arr[], int size) {
    // TODO: return sum of elements
    return 0; // placeholder
}

float array_avg(int arr[], int size) {
    // TODO: return average as float
    return 0.0f; // placeholder
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
