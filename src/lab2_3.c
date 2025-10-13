#include <stdio.h>
<<<<<<< HEAD
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
=======

/*
    Task:
    Write a function `int is_prime(int n)` that returns 1 if n is prime,
    0 otherwise.

    In main():
      - Ask user for an integer n (>= 2)
      - If invalid, print an error
      - Otherwise, print all prime numbers up to n
*/

int is_prime(int n) {
    // TODO: check if n is prime using loop up to sqrt(n)
    return 0; // placeholder
}

int main(void) {
    int n;

    printf("Enter an integer n (>= 2): ");
    scanf("%d", &n);

    // TODO: validate input and print all primes up to n
>>>>>>> 6275a13ea42e7fac345dbfa2230c9d49608be1d4

    return 0;
}
