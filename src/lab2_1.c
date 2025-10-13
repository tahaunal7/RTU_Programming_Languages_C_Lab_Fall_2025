#include <stdio.h>

<<<<<<< HEAD
int calculate_sum(int limit) {
  int total = 0;
  for (int k = 1; k <= limit; k++) {
    total += k;
  }
  return total;
}

int main(void) {
  int number;
  printf("Type a number greater than zero: ");
  scanf("%d", &number);

  if (number < 1) {
    printf("Invalid input. Please provide a value >= 1.\n");
  } else {
    int ans = calculate_sum(number);
    printf("Sum of integers from 1 to %d is %d\n", number, ans);
  }

  return 0;
=======
/*
    Task:
    Write a function `int sum_to_n(int n)` that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n) {
    // TODO: implement sum with a for loop
    return 0; // placeholder
}

int main(void) {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // TODO: validate input, call function, and print result

    return 0;
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
