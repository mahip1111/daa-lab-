#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int n1, int b[], int n2, int result[]) {

    int i=0,j=0,k=0;

    while(i<n1 && j<n2){

        if(a[i]<=b[j])
            result[k++]=a[i++];
        else
            result[k++]=b[j++];
    }

    while(i<n1)
        result[k++]=a[i++];

    while(j<n2)
        result[k++]=b[j++];
}

int main(){

    int k=4;
    int n=3;

    int arrays[4][3]={
        {1,5,9},
        {2,6,10},
        {3,7,11},
        {4,8,12}
    };

    int *list[4];
    int size[4];

    for(int i=0;i<k;i++){

        list[i]=(int*)malloc(n*sizeof(int));

        for(int j=0;j<n;j++)
            list[i][j]=arrays[i][j];

        size[i]=n;
    }

    clock_t start=clock();

    int current=k;

    while(current>1){

        int newCount=0;

        for(int i=0;i<current;i+=2){

            if(i+1<current){

                int newSize=size[i]+size[i+1];

                int *temp=(int*)malloc(newSize*sizeof(int));

                merge(list[i],size[i],list[i+1],size[i+1],temp);

                free(list[i]);
                free(list[i+1]);

                list[newCount]=temp;
                size[newCount]=newSize;

                newCount++;
            }

            else{

                list[newCount]=list[i];
                size[newCount]=size[i];
                newCount++;
            }
        }

        current=newCount;
    }

    clock_t end=clock();

    printf("Merged Array:\n");

    for(int i=0;i<size[0];i++)
        printf("%d ",list[0][i]);

    printf("\n");

    double time=((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nExecution Time : %lf seconds\n",time);

    free(list[0]);

    return 0;
}