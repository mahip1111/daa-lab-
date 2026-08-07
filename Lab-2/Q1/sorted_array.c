#include <stdio.h>

#define MAX 100

int dict[MAX];
int size = 0;

/*---------------- Binary Search ----------------*/
// O(logn)
int search(int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (dict[mid] == key)
            return mid;

        else if (dict[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

/*---------------- Insert ----------------*/
// O(n)
void insert(int key)
{
    if (size == MAX)
    {
        printf("Dictionary Full!\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && dict[i] > key)
    {
        dict[i + 1] = dict[i];
        i--;
    }

    dict[i + 1] = key;
    size++;
}

/*---------------- Delete ----------------*/
// O(n)
void deleteKey(int key)
{
    int index = search(key);

    if (index == -1)
    {
        printf("Key Not Found!\n");
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        dict[i] = dict[i + 1];
    }

    size--;
}

/*---------------- Maximum ----------------*/
// O(1)
int maximum()
{
    if (size == 0)
        return -1;

    return dict[size - 1];
}

/*---------------- Minimum ----------------*/
// O(1)
int minimum()
{
    if (size == 0)
        return -1;

    return dict[0];
}

/*---------------- Predecessor ----------------*/
// O(1)
int predecessor(int key)
{
    int index = search(key);

    if (index == -1)
        return -1;

    if (index == 0)
        return -1;

    return dict[index - 1];
}

/*---------------- Successor ----------------*/
// O(1)
int successor(int key)
{
    int index = search(key);

    if (index == -1)
        return -1;

    if (index == size - 1)
        return -1;

    return dict[index + 1];
}

/*---------------- Display ----------------*/
// O(1)
void display()
{
    printf("Dictionary : ");

    for (int i = 0; i < size; i++)
        printf("%d ", dict[i]);

    printf("\n");
}

/*---------------- Main ----------------*/

int main()
{
    insert(30);
    insert(10);
    insert(80);
    insert(20);
    insert(50);

    display();

    printf("Search 20 : %d\n", search(20));

    printf("Maximum : %d\n", maximum());

    printf("Minimum : %d\n", minimum());

    printf("Predecessor of 50 : %d\n", predecessor(50));

    printf("Successor of 30 : %d\n", successor(30));

    deleteKey(30);

    display();

    return 0;
}