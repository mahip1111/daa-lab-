#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node
{
    int key;
    struct Node *next;
};

struct Node *head = NULL;

/*---------------- Search ----------------*/

struct Node *search(int key)
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    // Empty list OR insert at beginning
    if (head == NULL || key < head->key)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL && temp->next->key < key)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
        printf("Key Not Found!\n");
        return;
    }

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

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp->key;
}

/*---------------- Minimum ----------------*/

int minimum()
{
    if (head == NULL)
        return -1;

    return head->key;
}

/*---------------- Predecessor ----------------*/

int predecessor(int key)
{
    struct Node *temp = head;
    int pred = -1;

    while (temp != NULL && temp->key < key)
    {
        pred = temp->key;
        temp = temp->next;
    }

    return pred;
}

/*---------------- Successor ----------------*/

int successor(int key)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->key > key)
            return temp->key;

        temp = temp->next;
    }

    return -1;
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

    deleteKey(30);

    display();

    return 0;
}