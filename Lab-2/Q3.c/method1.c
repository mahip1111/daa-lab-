#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge two sorted arrays
void merge(int a[], int n1, int b[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];
}

int main() {

    int k = 4;
    int n = 3;

    int arrays[4][3] = {
        {1,5,9},
        {2,6,10},
        {3,7,11},
        {4,8,12}
    };

    clock_t start = clock();

    int *result = (int *)malloc(n * sizeof(int));

    for(int i=0;i<n;i++)
        result[i]=arrays[0][i];

    int currentSize=n;

    for(int i=1;i<k;i++){

        int *temp=(int *)malloc((currentSize+n)*sizeof(int));

        merge(result,currentSize,arrays[i],n,temp);

        free(result);

        result=temp;

        currentSize+=n;
    }

    clock_t end=clock();

    printf("Merged Array:\n");

    for(int i=0;i<currentSize;i++)
        printf("%d ",result[i]);

    printf("\n");

    double time=((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nExecution Time : %lf seconds\n",time);

    free(result);

    return 0;
}