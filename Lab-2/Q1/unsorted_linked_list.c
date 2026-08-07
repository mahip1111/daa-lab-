#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int key;
    struct Node *next;
};

struct Node *head = NULL;

/*---------------- Search ----------------*/

struct Node* search(int key)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->key == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

/*---------------- Insert ----------------*/

void insert(int key)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->next = head;

    head = newNode;
}

/*---------------- Delete ----------------*/

void deleteKey(int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Key not found!\n");
        return;
    }

    // deleting first node
    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
}

/*---------------- Maximum ----------------*/

int maximum()
{
    if (head == NULL)
        return -1;

    int max = head->key;

    struct Node *temp = head->next;

    while (temp != NULL)
    {
        if (temp->key > max)
            max = temp->key;

        temp = temp->next;
    }

    return max;
}

/*---------------- Minimum ----------------*/

int minimum()
{
    if (head == NULL)
        return -1;

    int min = head->key;

    struct Node *temp = head->next;

    while (temp != NULL)
    {
        if (temp->key < min)
            min = temp->key;

        temp = temp->next;
    }

    return min;
}

/*---------------- Predecessor ----------------*/

int predecessor(int key)
{
    int pred = -1;

    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->key < key)
        {
            if (pred == -1 || temp->key > pred)
                pred = temp->key;
        }

        temp = temp->next;
    }

    return pred;
}

/*---------------- Successor ----------------*/

int successor(int key)
{
    int succ = -1;

    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->key > key)
        {
            if (succ == -1 || temp->key < succ)
                succ = temp->key;
        }

        temp = temp->next;
    }

    return succ;
}

/*---------------- Display ----------------*/

void display()
{
    struct Node *temp = head;

    printf("Dictionary : ");

    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }

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

    if (search(20))
        printf("20 Found\n");
    else
        printf("20 Not Found\n");

    printf("Maximum : %d\n", maximum());

    printf("Minimum : %d\n", minimum());

    printf("Predecessor of 50 : %d\n", predecessor(50));

    printf("Successor of 30 : %d\n", successor(30));

    deleteKey(80);

    display();

    return 0;
}