#include <stdio.h>
#include <math.h>

int main() {
    double n = 100;   // try changing this and re-running

    double log2n = log2(n);   // log base 2 of n, used a few times below

    printf("Values at n = %.0f, in increasing order of growth:\n\n", n);

    printf("1/n              = %f\n",  1.0 / n);
    printf("log2(n)          = %f\n",  log2n);
    printf("12*sqrt(n)       = %f\n",  12 * sqrt(n));
    printf("50*n^0.5         = %f\n",  50 * pow(n, 0.5));
    printf("n^0.51           = %f\n",  pow(n, 0.51));
    printf("n*log2(n)        = %f\n",  n * log2n);
    printf("n^2 - 324        = %f\n",  n * n - 324);
    printf("100n^2 + 6n      = %f\n",  100 * n * n + 6 * n);
    printf("2n^3             = %f\n",  2 * n * n * n);
    printf("n^(log2 n)       = %f\n",  pow(n, log2n));

    // These two get astronomically large, so print log2(value) instead
    printf("3^n   -> log2 of it       = %f\n", n * log2(3.0));
    printf("2^(32n) -> log2 of it     = %f\n", 32 * n);

    return 0;
}
