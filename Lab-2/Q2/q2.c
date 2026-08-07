#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

/*----------------------------------------------------------
    Standard Merge Sort
----------------------------------------------------------*/

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];

    for(int i=0;i<n2;i++)
        R[i]=arr[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

/*----------------------------------------------------------
    Modified 3-Way Merge Sort
----------------------------------------------------------*/

void mergeThree(int arr[], int l, int m1, int m2, int r)
{
    int n1=m1-l+1;
    int n2=m2-m1;
    int n3=r-m2;

    int *A=(int*)malloc(n1*sizeof(int));
    int *B=(int*)malloc(n2*sizeof(int));
    int *C=(int*)malloc(n3*sizeof(int));

    for(int i=0;i<n1;i++)
        A[i]=arr[l+i];

    for(int i=0;i<n2;i++)
        B[i]=arr[m1+1+i];

    for(int i=0;i<n3;i++)
        C[i]=arr[m2+1+i];

    int i=0,j=0,k=0,index=l;

    while(i<n1 && j<n2 && k<n3)
    {
        if(A[i]<=B[j] && A[i]<=C[k])
            arr[index++]=A[i++];
        else if(B[j]<=A[i] && B[j]<=C[k])
            arr[index++]=B[j++];
        else
            arr[index++]=C[k++];
    }

    while(i<n1 && j<n2)
        arr[index++]=(A[i]<=B[j])?A[i++]:B[j++];

    while(i<n1 && k<n3)
        arr[index++]=(A[i]<=C[k])?A[i++]:C[k++];

    while(j<n2 && k<n3)
        arr[index++]=(B[j]<=C[k])?B[j++]:C[k++];

    while(i<n1)
        arr[index++]=A[i++];

    while(j<n2)
        arr[index++]=B[j++];

    while(k<n3)
        arr[index++]=C[k++];

    free(A);
    free(B);
    free(C);
}

void modifiedMergeSort(int arr[], int l, int r)
{
    if(l>=r)
        return;

    int third=(r-l)/3;

    int m1=l+third;
    int m2=l+2*third;

    modifiedMergeSort(arr,l,m1);
    modifiedMergeSort(arr,m1+1,m2);
    modifiedMergeSort(arr,m2+1,r);

    mergeThree(arr,l,m1,m2,r);
}

/*----------------------------------------------------------
    Utility Functions
----------------------------------------------------------*/

void generateRandom(int arr[], int n)
{
    for(int i=0;i<n;i++)
        arr[i]=rand()%100000;
}

void copyArray(int src[], int dest[], int n)
{
    for(int i=0;i<n;i++)
        dest[i]=src[i];
}

/*----------------------------------------------------------
    Driver
----------------------------------------------------------*/

int main()
{
    srand(time(NULL));

    FILE *fp=fopen("merge_sort_analysis.csv","w");

    fprintf(fp,"InputSize,MergeSort,ModifiedMergeSort\n");

    printf("\nInput\tMergeSort\tModifiedMergeSort\n");

    for(int n=1000;n<=50000;n+=2000)
    {
        int *A=(int*)malloc(n*sizeof(int));
        int *B=(int*)malloc(n*sizeof(int));
        int *temp=(int*)malloc(n*sizeof(int));

        generateRandom(temp,n);

        copyArray(temp,A,n);
        copyArray(temp,B,n);

        clock_t start,end;

        start=clock();
        mergeSort(A,0,n-1);
        end=clock();

        double t1=(double)(end-start)/CLOCKS_PER_SEC;

        start=clock();
        modifiedMergeSort(B,0,n-1);
        end=clock();

        double t2=(double)(end-start)/CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%.6f\n",n,t1,t2);

        fprintf(fp,"%d,%lf,%lf\n",n,t1,t2);

        free(A);
        free(B);
        free(temp);
    }

    fclose(fp);

    printf("\nCSV file generated successfully: merge_sort_analysis.csv\n");
    printf("Plot the graph using Excel, Python, or Google Sheets.\n");

    return 0;
}