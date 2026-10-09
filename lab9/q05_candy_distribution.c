/* DAA Lab 09 - Q5: Candy distribution
   Give each child one candy, then satisfy left and right rating slopes.
*/
#include <stdio.h>

int main(void) {
    int n, i;
    int rating[1000], candy[1000];
    long long total = 0;

    printf("Number of children (max 1000): ");
    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;
    for (i = 0; i < n; i++) {
        printf("Rating of child %d: ", i + 1);
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    for (i = 1; i < n; i++)
        if (rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;

    for (i = n - 2; i >= 0; i--)
        if (rating[i] > rating[i + 1] && candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;

    for (i = 0; i < n; i++) {
        printf("Child %d gets %d candy/candies\n", i + 1, candy[i]);
        total += candy[i];
    }
    printf("Minimum total candies = %lld\n", total);
    return 0;
}
