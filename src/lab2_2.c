#include <stdio.h>

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
}
