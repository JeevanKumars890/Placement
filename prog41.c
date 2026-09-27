#include <stdio.h>

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int digits = 1;
    int sum = 0;
    int square_sum = 0;
    int alternating_sum = 0;

    int temp = n;

    if (temp != 0) {
        digits = 0;
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
    }

    int divisor = 1;
    for (int i = 1; i < digits; i++) {
        divisor *= 10;
    }

    for (int i = 0; i < digits; i++) {
        int digit = n / divisor;
        n %= divisor;

        if (divisor > 1) {
            divisor /= 10;
        }

        sum += digit;
        square_sum += digit * digit;

        if (i % 2 == 0) {
            alternating_sum += digit;
        } else {
            alternating_sum -= digit;
        }
    }

    printf("%d\n", digits);
    printf("%d\n", sum);
    printf("%d\n", square_sum);
    printf("%d\n", alternating_sum);
    printf("%s\n", alternating_sum % 11 == 0 ? "VALID" : "INVALID");

    return 0;
}