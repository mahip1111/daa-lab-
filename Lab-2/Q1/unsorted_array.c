#include <stdio.h>

#define MAX 100

int dict[MAX];
int size = 0;

// Search O(n)
int search(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (dict[i] == key)
            return i;
    }
    return -1;
}

// Insert O(1)
void insert(int key)
{
    if (size == MAX)
    {
        printf("Dictionary Full!\n");
        return;
    }

    dict[size++] = key;
}

// Delete O(n)
void deleteKey(int key)
{
    int index = search(key);  // here we are calling the search operation

    if (index == -1)
    {
        printf("Key not found!\n");
        return;
    }

    // Replace with last element
    dict[index] = dict[size - 1];
    size--;
}

// Maximum O(n)
int maximum()
{
    if (size == 0)
        return -1;

    int max = dict[0];

    for (int i = 1; i < size; i++)
    {
        if (dict[i] > max)
            max = dict[i];
    }

    return max;
}

// Minimum O(n)
int minimum()
{
    if (size == 0)
        return -1;

    int min = dict[0];

    for (int i = 1; i < size; i++)
    {
        if (dict[i] < min)
            min = dict[i];
    }

    return min;
}

// Predecessor
int predecessor(int key)
{
    int pred = -1;

    for (int i = 0; i < size; i++)
    {
        if (dict[i] < key)
        {
            if (pred == -1 || dict[i] > pred)
                pred = dict[i];
        }
    }

    return pred;
}

// Successor
int successor(int key)
{
    int succ = -1;

    for (int i = 0; i < size; i++)
    {
        if (dict[i] > key)
        {
            if (succ == -1 || dict[i] < succ)
                succ = dict[i];
        }
    }

    return succ;
}

// Display
void display()
{
    printf("Dictionary : ");

    for (int i = 0; i < size; i++)
        printf("%d ", dict[i]);

    printf("\n");
}

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

    deleteKey(80);

    display();

    return 0;
}

// Dry run of the predecessor code :


