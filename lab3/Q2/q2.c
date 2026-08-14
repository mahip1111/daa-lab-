#include <stdio.h>

// Returns index of defective coin, or -1 if none exists
int findDefective(int coins[], int low, int high, int normalWeight) {
    // No coins
    if (low > high)
        return -1;

    // Only one coin left
    if (low == high) {
        if (coins[low] < normalWeight)
            return low;
        return -1;
    }

    int mid = (low + high) / 2;

    int leftSum = 0, rightSum = 0;

    // Sum of left half
    for (int i = low; i <= mid; i++)
        leftSum += coins[i];

    // Sum of right half
    for (int i = mid + 1; i <= high; i++)
        rightSum += coins[i];

    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int expectedLeft = leftSize * normalWeight;
    int expectedRight = rightSize * normalWeight;

    if (leftSum < expectedLeft)
        return findDefective(coins, low, mid, normalWeight);

    if (rightSum < expectedRight)
        return findDefective(coins, mid + 1, high, normalWeight);

    return -1; // No defective coin
}

int main() {
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter weights of the coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    // Assume first coin has the standard weight
    int normalWeight = coins[0];

    // Find the maximum weight (actual standard weight)
    for (int i = 1; i < n; i++) {
        if (coins[i] > normalWeight)
            normalWeight = coins[i];
    }

    int ans = findDefective(coins, 0, n - 1, normalWeight);

    if (ans == -1)
        printf("\nNo defective coin found. All coins have equal weight.\n");
    else
        printf("\nDefective (lighter) coin found at position %d (1-based index).\n", ans + 1);

    return 0;
}