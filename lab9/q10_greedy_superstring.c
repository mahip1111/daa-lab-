/* DAA Lab 09 - Q10: Greedy shortest-superstring heuristic
   Repeatedly merge the pair with the largest suffix-prefix overlap.
   This is a heuristic, not an exact solver; the lab sheet calls the topic open.
*/
#include <stdio.h>
#include <string.h>

#define NMAX 30
#define LMAX 200

int overlap(const char *a, const char *b) {
    int la = (int)strlen(a), lb = (int)strlen(b), k;
    for (k = (la < lb ? la : lb); k > 0; k--)
        if (strncmp(a + la - k, b, (size_t)k) == 0) return k;
    return 0;
}

int main(void) {
    int n, i, j, x, y, best, ov;
    char s[NMAX][LMAX];

    printf("Number of strings (2-%d): ", NMAX);
    scanf("%d", &n);
    if (n < 2 || n > NMAX) return 0;
    for (i = 0; i < n; i++) {
        printf("String %d (no spaces): ", i + 1);
        scanf("%199s", s[i]);
    }

    /* Remove strings already contained in another string. */
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
        if (i != j && s[i][0] != '\0' && strstr(s[j], s[i]) != NULL) s[i][0] = '\0';
    }

    while (1) {
        best = 0; x = y = -1;
        for (i = 0; i < n; i++) if (s[i][0]) {
            for (j = 0; j < n; j++) if (i != j && s[j][0]) {
                ov = overlap(s[i], s[j]);
                if (ov > best) { best = ov; x = i; y = j; }
            }
        }
        if (x == -1) break;
        if (strlen(s[x]) + strlen(s[y]) - best >= LMAX) {
            printf("Merged string too long for this demo.\n");
            return 0;
        }
        strcat(s[x], s[y] + best);
        s[y][0] = '\0';
    }

    printf("Greedy superstring result(s):\n");
    for (i = 0; i < n; i++) if (s[i][0]) printf("%s\n", s[i]);
    printf("Note: greedy output is not guaranteed to be globally shortest.\n");
    return 0;
}
