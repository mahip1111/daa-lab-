#include <stdio.h>

void findMinMax(int arr[], int low, int high, int *min, int *max)
{
    // Only one element
    if (low == high)
    {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // Two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;

    int leftMin, leftMax;
    int rightMin, rightMax;

    findMinMax(arr, low, mid, &leftMin, &leftMax);
    findMinMax(arr, mid + 1, high, &rightMin, &rightMax);

    *min = (leftMin < rightMin) ? leftMin : rightMin;
    *max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}