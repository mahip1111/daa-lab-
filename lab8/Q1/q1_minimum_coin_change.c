#include <stdio.h>
#include <stdlib.h>

int coinChange(int* coins, int coinsSize, int amount) {

    // dp[i] = minimum number of coins needed to make amount i
    int* dp = (int*)malloc((amount + 1) * sizeof(int));

    // Initialize every value with amount + 1
    // amount + 1 means "currently impossible"
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // 0 coins are needed to make amount 0
    dp[0] = 0;

    // Calculate minimum coins for every amount from 1 to amount
    for (int i = 1; i <= amount; i++) {

        // Try every coin
        for (int j = 0; j < coinsSize; j++) {

            int coin = coins[j];

            if (i >= coin) {

                // Either keep the current answer
                // or use this coin
                dp[i] = dp[i] < dp[i - coin] + 1
                        ? dp[i]
                        : dp[i - coin] + 1;
            }
        }
    }

    // If dp[amount] is still amount + 1,
    // then the amount cannot be formed
    int answer;

    if (dp[amount] > amount) {
        answer = -1;
    } else {
        answer = dp[amount];
    }

    free(dp);

    return answer;
}

int main() {

    int coins[] = {1, 2, 5};
    int coinsSize = 3;
    int amount = 11;

    int result = coinChange(coins, coinsSize, amount);

    printf("Minimum number of coins = %d\n", result);

    return 0;
}