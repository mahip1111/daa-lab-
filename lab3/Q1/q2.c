// ternary search algorithm in C

#include <stdio.h>
int ternary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == x) {
            printf("Element found at index %d\n", mid1);
            return mid1;
        }
        if (arr[mid2] == x) {
            printf("Element found at index %d\n", mid2);
            return mid2;
        }

        if (x < arr[mid1]) {
            return ternary_search(arr, l, mid1 - 1, x);
        } else if (x > arr[mid2]) {
            return ternary_search(arr, mid2 + 1, r, x);
        } else {
            return ternary_search(arr, mid1 + 1, mid2 - 1, x);
        }
    }
    printf("Element not found\n");
    return -1;
}

int main(){
    // here we can also take the input from the user but for now we are using a static array
    int arr[5] = {1, 2, 3, 4, 5};
    ternary_search(arr, 0, 4, 3);
    return 0;
}