#include <stdio.h>

#define MAX 64

// Recursive multiplication
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
              int ar, int ac, int br, int bc, int cr, int cc, int n)
{
    // Base Case
    if (n == 1)
    {
        C[cr][cc] = A[ar][ac] * B[br][bc];
        return;
    }

    int m = n / 2;

    // Four recursive multiplications
    multiply(A, B, C, ar, ac, br, bc, cr, cc, m);               // P
    multiply(A, B, C, ar, ac + m, br + m, bc, cr, cc, m);       // Q

    multiply(A, B, C, ar, ac, br, bc + m, cr, cc + m, m);       // R
    multiply(A, B, C, ar, ac + m, br + m, bc + m, cr, cc + m, m);// S

    // Build remaining blocks
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            C[cr][cc] += 0; // Already calculated
            C[cr+i+m][cc+j] = C[cr+i][cc+j+m];
            C[cr+i+m][cc+j+m] = C[cr+i][cc+j];
        }
    }
}

int main()
{
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX]={0};

    printf("Enter size (power of 2): ");
    scanf("%d",&n);

    printf("Enter Matrix A:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    multiply(A,B,C,0,0,0,0,0,0,n);

    printf("\nResult Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}