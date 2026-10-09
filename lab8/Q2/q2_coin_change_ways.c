#include <stdio.h>
#include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {

    // dp[i] = number of ways to make amount i
    unsigned int* dp =
        (unsigned int*)calloc(amount + 1, sizeof(unsigned int));

    // There is exactly 1 way to make amount 0:
    // choose nothing.
    dp[0] = 1;

    // Try each coin
    for (int i = 0; i < coinsSize; i++) {

        int coin = coins[i];

        // Calculate ways for every amount
        // that can use this coin.
        for (int j = coin; j <= amount; j++) {

            dp[j] += dp[j - coin];
        }
    }

    // Store the answer
    unsigned int answer = dp[amount];

    // Free dynamically allocated memory
    free(dp);

    return answer;
}

int main() {

    int coins[] = {1, 2, 5};
    int coinsSize = 3;
    int amount = 5;

    int result = change(amount, coins, coinsSize);

    printf("Number of combinations = %d\n", result);

    return 0;
}