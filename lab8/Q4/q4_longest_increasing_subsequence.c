
#include <stdio.h>

int main() {
    int n;
    int a[100], dp[100];
    int max = 1;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > max) {
            max = dp[i];
        }
    }

    printf("Length of LIS = %d\n", max);

    return 0;
}
