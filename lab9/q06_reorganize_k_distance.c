/* DAA Lab 09 - Q6: Reorganise string so equal characters are K apart
   This simple version supports English letters a-z and A-Z only.
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1001], out[1001];
    int freq[256] = {0}, nextAllowed[256] = {0};
    int n, k, i, pos, best, placed = 0;

    printf("Enter string (no spaces): ");
    scanf("%1000s", s);
    printf("Enter K: ");
    scanf("%d", &k);
    n = (int)strlen(s);
    if (k <= 1) { printf("Result: %s\n", s); return 0; }
    for (i = 0; i < n; i++) freq[(unsigned char)s[i]]++;

    for (pos = 0; pos < n; pos++) {
        best = -1;
        for (i = 0; i < 256; i++)
            if (freq[i] > 0 && nextAllowed[i] <= pos &&
                (best == -1 || freq[i] > freq[best])) best = i;
        if (best == -1) {
            printf("Impossible; result is an empty string.\n");
            return 0;
        }
        out[pos] = (char)best;
        freq[best]--;
        nextAllowed[best] = pos + k;
        placed++;
    }
    out[placed] = '\0';
    printf("Reorganised string: %s\n", out);
    return 0;
}
