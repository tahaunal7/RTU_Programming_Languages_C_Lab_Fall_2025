#include <stdio.h>

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
}
