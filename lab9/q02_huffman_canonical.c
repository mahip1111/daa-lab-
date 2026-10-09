/* DAA Lab 09 - Q2: Huffman coding and canonical codebook
   Simple array-based Huffman construction for small inputs.
   Compile: gcc q02_huffman_canonical.c -o q02
*/
#include <stdio.h>
#include <string.h>

#define MAX 60
typedef struct {
    char symbol;
    int freq, parent, left, right;
} Node;

char codes[MAX][MAX];
int lengths[MAX];

int main(void) {
    int n, i, j, total, min1, min2, a, b;
    Node t[2 * MAX];

    printf("Number of symbols (2-%d): ", MAX);
    scanf("%d", &n);
    if (n < 2 || n > MAX) return 0;

    for (i = 0; i < 2 * n - 1; i++) {
        t[i].freq = 0; t[i].parent = -1; t[i].left = -1; t[i].right = -1;
        t[i].symbol = 0;
    }
    for (i = 0; i < n; i++) {
        printf("Symbol and frequency: ");
        scanf(" %c %d", &t[i].symbol, &t[i].freq);
    }

    for (i = n; i < 2 * n - 1; i++) {
        min1 = min2 = -1;
        for (j = 0; j < i; j++) {
            if (t[j].parent == -1) {
                if (min1 == -1 || t[j].freq < t[min1].freq) {
                    min2 = min1; min1 = j;
                } else if (min2 == -1 || t[j].freq < t[min2].freq) {
                    min2 = j;
                }
            }
        }
        a = min1; b = min2;
        t[i].freq = t[a].freq + t[b].freq;
        t[i].left = a; t[i].right = b;
        t[a].parent = t[b].parent = i;
    }

    for (i = 0; i < n; i++) {
        char reverse[MAX];
        int len = 0, cur = i, p;
        while (t[cur].parent != -1) {
            p = t[cur].parent;
            reverse[len++] = (t[p].left == cur) ? '0' : '1';
            cur = p;
        }
        if (len == 0) reverse[len++] = '0';
        lengths[i] = len;
        for (j = 0; j < len; j++) codes[i][j] = reverse[len - 1 - j];
        codes[i][len] = '\0';
    }

    /* Sort symbols by code length, then symbol. Canonical assignment:
       first code is all zeroes; next code = (previous + 1) shifted by length change. */
    for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) {
        if (lengths[j] < lengths[i] ||
            (lengths[j] == lengths[i] && t[j].symbol < t[i].symbol)) {
            int tmpLen = lengths[i]; lengths[i] = lengths[j]; lengths[j] = tmpLen;
            char tmpSym = t[i].symbol; t[i].symbol = t[j].symbol; t[j].symbol = tmpSym;
            char tmpCode[MAX]; strcpy(tmpCode, codes[i]); strcpy(codes[i], codes[j]); strcpy(codes[j], tmpCode);
        }
    }

    /* Convert the lengths into canonical binary codes. */
    unsigned long long code = 0;
    int previousLength = lengths[0];
    for (i = 0; i < n; i++) {
        if (i > 0) code = (code + 1ULL) << (lengths[i] - previousLength);
        previousLength = lengths[i];
        for (j = lengths[i] - 1; j >= 0; j--) {
            codes[i][j] = (code & 1ULL) ? '1' : '0';
            code >>= 1;
        }
        /* Rebuild the integer from the printed bits for the next step. */
        code = 0;
        for (j = 0; j < lengths[i]; j++) code = (code << 1) | (codes[i][j] - '0');
    }

    printf("\nCanonical Huffman codebook:\n");
    for (i = 0; i < n; i++)
        printf("Symbol %c, frequency %d, length %d, code %s\n",
               t[i].symbol, t[i].freq, lengths[i], codes[i]);
    return 0;
}
