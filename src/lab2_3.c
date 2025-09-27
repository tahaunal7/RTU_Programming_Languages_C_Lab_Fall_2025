#include <stdio.h>
#include <stdbool.h>

// custom function to check if a number is prime
bool isPrimeNumber(int candidate) {
    if (candidate <= 1) {
        return false;   // 0, 1 and negatives are not prime
    }

    // check divisibility
    for (int divider = 2; divider * divider <= candidate; divider++) {
        if (candidate % divider == 0) {
            return false;  // divisible → not prime
        }
    }
    return true; // if no divisors → prime
}

int main(void) {
    int given;

    printf("Enter any integer to test for primality: ");
    scanf("%d", &given);

    if (isPrimeNumber(given)) {
        printf("Result: %d is a prime number.\n", given);
    } else {
        printf("Result: %d is NOT a prime number.\n", given);
    }

    return 0;
}
