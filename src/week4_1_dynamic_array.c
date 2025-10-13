/*
 * week4_1_dynamic_array.c
<<<<<<< HEAD
 * Author: Mehmet Taha Ünal
 * Student ID: 231AMB077
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students allocate memory for integers, fill it with user input,
 *   compute the sum and average, and then free the memory properly.
=======
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Students should allocate memory for an integer array, fill it with data,
 *   compute something (e.g., average), and then free the memory.
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
<<<<<<< HEAD
  int n;
  int *arr = NULL;
  int sum = 0;
  double avg;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // Allocate memory for n integers using malloc
  arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Read n integers from user input
  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  // Compute average
  avg = (double)sum / n;

  // Print the results
  printf("Sum = %d\n", sum);
  printf("Average = %.2f\n", avg);

  // Free allocated memory
  free(arr);

  return 0;
=======
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // TODO: Allocate memory for n integers using malloc
    // Example: arr = malloc(n * sizeof(int));

    // TODO: Check allocation success

    // TODO: Read n integers from user input and store in array

    // TODO: Compute sum and average

    // TODO: Print the results

    // TODO: Free allocated memory

    return 0;
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
