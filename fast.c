#include <stdio.h>

#include "primes.h"

/* Uses decomposition in prime factors for fast sum of proper divisors */
unsigned int fast_sum(unsigned int num) {
    unsigned int sum, x, sub;

    sum = 1;
    x = num;
    for (int i = 0; i < P_COUNT; ++i) {
        if (P[i] > x / P[i]) break;
        if (x % P[i] == 0) {
            sub = P[i] + 1;
            x /= P[i];
            while (x % P[i] == 0) {
                x /= P[i];
                sub = sub * P[i] + 1;
            }
            sum *= sub;
        }
    }
    if (x > 1) sum *= x + 1;
    return sum - num;
}

int main(int argc, char *argv[]) {
    unsigned int n = 21387312;
    printf("Sum of proper divisors for (%d): %d\n", n, fast_sum(n));
    return 0;
}