#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node
{
    int key;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;

    // Empty list
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Insert at beginning
    if (key < head->key)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL && temp->next->key < key)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/*---------------- Delete ----------------*/

void deleteKey(int key)
{
    struct Node *temp = search(key);

    if (temp == NULL)
    {
        printf("Key Not Found!\n");
        return;
    }

    if (temp->prev == NULL)
    {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

/*---------------- Maximum ----------------*/

int maximum()
{
    if (head == NULL)
        return -1;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

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
    struct Node *node = search(key);

    if (node == NULL)
        return -1;

    if (node->prev == NULL)
        return -1;

    return node->prev->key;
}

/*---------------- Successor ----------------*/

int successor(int key)
{
    struct Node *node = search(key);

    if (node == NULL)
        return -1;

    if (node->next == NULL)
        return -1;

    return node->next->key;
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