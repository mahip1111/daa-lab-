#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    // Run only for first (n-1) elements
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        // Find smallest element in remaining array
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    return 0;
}