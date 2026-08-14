#include <stdio.h>
int bs(int arr[], int n, int x){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            printf("Element found at index %d\n", mid);
            return mid;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    printf("Element not found\n");
    return -1;
}

int main(){
    // here we can also take the input from the user but for now we are using a static array
    int arr[5] ={1,2,3,4,5};
    bs(arr, 5, 3);
    return 0;
}