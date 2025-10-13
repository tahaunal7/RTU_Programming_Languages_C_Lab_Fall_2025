#include <stdio.h>

<<<<<<< HEAD
long long getFactorial(int value) {
  long long result = 1;
  for (int i = 2; i <= value; i++) {
    result *= i;
  }
  return result;
}

int main(void) {
  int input;

  printf("Please insert a non-negative number: ");
  scanf("%d", &input);

  if (input < 0) {
    printf("Error! Factorial is undefined for negative numbers.\n");
  } else {
    long long outcome = getFactorial(input);
    printf("The factorial of %d equals %lld\n", input, outcome);
  }

  return 0;
=======
/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    // TODO: compute factorial iteratively
    return 1; // placeholder
}

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);

    // TODO: validate input, call function, print result

    return 0;
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4
}
