
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of coins on each side: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    int moves = (n * (n + 1) + 5) / 6;

    printf("Minimum moves = %d\n", moves);

    return 0;
}
