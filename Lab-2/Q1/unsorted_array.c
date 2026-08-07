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
        if (dict[i] < key)  // you are sorting the elements less than the key
        {
            if (pred == -1 || dict[i] > pred)  // now jo apna sort kiya hai numbers upar jo less than hai key sa usma sa sabsa badha ans hi predecessor hoga
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

// If you understand this then it is also easy to understand the sucessor

// Step 1:

// int pred = -1;
// Yeh ek variable hai.
// Isme hum answer store karenge.

// Initially
// pred = -1

// Matlab
// Abhi tak predecessor mila hi nahi.

// Step 2
// for(int i=0;i<size;i++)
// Array ke har element ko dekhna hai.

// Suppose:
// 30 10 80 20 50

// Loop chalega
// 30
// 10
// 80
// 20
// 50
// Ek ek karke.

// Step 3
// if(dict[i] < key)

// Maan lo
// key = 50
// Ab check karte hain

// First element
// 30

// Question
// 30 < 50 ?
// Yes.

// Toh ye predecessor ban sakta hai.

// Second element
// 10

// Question
// 10 < 50 ?
// Yes.

// Ye bhi ban sakta hai.

// Third element
// 80
// Question
// 80 < 50 ?
// No.
// Ignore.

// Fourth element
// 20
// Question
// 20 < 50 ?
// Yes.

// Fifth element
// 50
// Question
// 50 < 50 ?
// No.
// Ignore.

// Ab sirf ye candidates bache
// 30
// 10
// 20

// Ab inme predecessor kaun hai?

// Largest.

// Matlab
// 30
// Lekin code ko kaise pata chalega?

// Ye line.

// if(pred==-1 || dict[i]>pred)

// Isko slow motion me dekhte hain.

// First iteration
// Element
// 30
// Current
// pred=-1

// Question
// pred==-1 ?
// Yes.

// Toh
// pred=30

// Ab

// pred=30

// Second iteration
// Element
// 10
// Question
// 10>30 ?
// No.

// Toh
// pred=30
// Same.

// Third candidate
// Element
// 20
// Question
// 20>30 ?
// No.

// Again
// pred=30
// Loop finish.
// Return
// 30

// Done.


