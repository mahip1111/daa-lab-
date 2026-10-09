#include <stdio.h>
#include <string.h>

int main() {

    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // dp[i][j] = LCS length of
    // X[0...i-1] and Y[0...j-1]
    int dp[101][101] = {0};

    // Build DP table
    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (X[i - 1] == Y[j - 1]) {
                // Characters match
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                // Characters don't match
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // LCS length
    printf("\nLength of LCS = %d\n", dp[m][n]);

    // Reconstruct the actual LCS
    char lcs[101];
    int index = dp[m][n];

    lcs[index] = '\0';

    int i = m;
    int j = n;

    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {

            // This character is part of LCS
            lcs[index - 1] = X[i - 1];

            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {

            // Move UP
            i--;
        }
        else {

            // Move LEFT
            j--;
        }
    }

    printf("LCS = %s\n", lcs);

    return 0;
}