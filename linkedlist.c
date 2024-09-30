#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("Insufficient memory\n");  \
        exit(0);                          \
    }

struct node
{ // To define node structure
    int info;
    struct node *link;
};

typedef struct node *NODE; // Renamed struct node* as NODE using typedef

NODE insertion_front(int, NODE); // SLL operations list
void display(NODE);
NODE deletion_front(NODE);
NODE insertion_rear(int, NODE);
NODE deletion_rear(NODE);
int count_nodes(NODE);
void search(NODE, int);

void main()
{
    NODE first; // first variable always points to first node in Linked List(SLL)
    int item, choice, pos;
    first = NULL; // Linked List(SLL) is empty
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            first = insertion_front(item, first); // used to insert node at front end in SLL
            break;
        case 2:
            first = deletion_front(first); // used to delete node at front end in SLL
            break;
        case 3:
            display(first);
            break;
        case 4:
            scanf("%d", &item);
            first = insertion_rear(item, first); // used to insert node at rear end in SLL
            break;
        case 5:
            first = deletion_rear(first); // used to delete node at rear end in SLL
            break;
        case 6:
            printf("No of nodes in SLL = %d\n", count_nodes(first));
            break;
        case 7:
            // printf("Enter the item to search\n");
            scanf("%d", &item);
            search(first, item);
            break;
        case 8:
            exit(0);
        }
    }
}

NODE insertion_front(int item, NODE first)
{
    NODE temp;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = first;
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If SLL is empty
        printf("Empty SLL - Cannot display\n");
        return;
    }
    temp = first; // If SLL is not empty
    while (temp != NULL)
    {
        printf("%d", temp->info);
        temp = temp->link;
        printf("->");
    }
    printf("\n");
}

NODE deletion_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If SLL is empty
        printf("Empty SLL - Cannot delete\n");
        return NULL;
    }
    temp = first; // If SLL is not empty
    first = first->link;
    printf("Deleted element from SLL is %d\n", temp->info);
    free(temp);
    return first;
}

NODE insertion_rear(int item, NODE first)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
    { // If SLL is empty, return new node as first node in SLL
        return temp;
    }
    cur = first; // If SLL has more than one node
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE deletion_rear(NODE first)
{
    NODE prev, cur;
    if (first == NULL)
    { // If SLL is empty
        printf("Empty SLL - Cannot delete\n");
        return NULL;
    }
    if (first->link == NULL)
    { // If SLL has only one node
        printf("Deleted element from SLL is %d\n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL; // If SLL has more than one node
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted element from SLL is %d\n", cur->info);
    free(cur);
    prev->link = NULL;
    return first;
}

int count_nodes(NODE first)
{
    int count = 0;
    NODE temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void search(NODE first, int item)
{
    NODE temp = first;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->info == item)
        {
            found = 1;
            break;
        }
        temp = temp->link;
    }
    if (found)
    {
        printf("%d is found in SLL\n", item);
    }
    else
    {
        printf("%d is not found in SLL\n", item);
    }
}
//------------------------------------------------------CSL Operations----------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memeory\n"); \
        exit(0);                          \
    }
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE insertion_front(int, NODE);
void display(NODE);
NODE deletion_front(NODE);
NODE insertion_rear(int, NODE);
NODE deletion_rear(NODE);
int count_nodes(NODE);
void search(NODE, int);
void main()
{
    NODE head;
    int item, choice;
    MALLOC(head, 1, struct node);
    head->link = head;
    for (;;)
    {
        // printf("1.insertion_front 2.display\n");
        // printf("3.deletion_front 4.insertion_rear\n");
        // printf("5.deletion_rear 6.exit\n");
        // printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // printf("enter the item to be inserted\n");
            scanf("%d", &item);
            head = insertion_front(item, head);
            break;
        case 2:
            head = deletion_front(head);
            break;
        case 3:
            display(head);
            break;
        case 4: // printf("enter the item to be inserted\n");
            scanf("%d", &item);
            head = insertion_rear(item, head);
            break;
        case 5:
            head = deletion_rear(head);
            break;
        case 6:
            printf("No of nodes in CSL = %d\n", count_nodes(head));
            break;
        case 7: // printf("Enter the item to search\n");
            scanf("%d", &item);
            search(head, item);
            break;
        case 8:
            exit(0);
        }
    }
}
NODE insertion_front(int item, NODE head)
{
    NODE temp;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = head->link;
    head->link = temp;
    return head;
}
void display(NODE head)
{
    NODE temp;
    if (head->link == head)
    {
        printf("Empty CSL - Cannot display\n");
        return;
    }
    // printf("the content of csl is\n");
    temp = head->link;
    while (temp != head)
    {
        printf("%d->", temp->info);
        temp = temp->link;
    }
    printf("\n");
}
NODE deletion_front(NODE head)
{
    NODE temp;
    if (head->link == head)
    {
        printf("csl is empty\n");
        return NULL;
    }
    temp = head->link;
    head->link = temp->link;
    printf("Deleted element from csl is %d\n", temp->info);
    free(temp);
    return head;
}
NODE insertion_rear(int item, NODE head)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}
NODE deletion_rear(NODE head)
{
    NODE prev, cur;
    if (head->link == head)
    {
        printf("Csll is empty\n");
        return NULL;
    }
    prev = NULL;
    cur = head->link;
    while (cur->link != head)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("deleted item is:%d\n", cur->info);
    free(cur);
    prev->link = head;
    return head;
}
int count_nodes(NODE head)
{
    int count = 0;
    NODE temp = head->link;
    while (temp != head)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void search(NODE head, int item)
{
    NODE temp = head->link;
    int found = 0;
    while (temp != head)
    {
        if (temp->info == item)
        {
            found = 1;
            break;
        }
        temp = temp->link;
    }
    if (found)
    {
        printf("%d is found in CSL\n", item);
    }
    else
    {
        printf("%d is not found in CSL\n", item);
    }
}

//------------------------------------------------------DLL Operations----------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("Insufficient memory\n");  \
        exit(0);                          \
    }

struct node
{ // To define node structure
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE; // Renamed struct node* as NODE using typedef

NODE insertion_front(int, NODE); // SLL operations list
void display(NODE);
NODE deletion_front(NODE);
NODE insertion_rear(int, NODE);
NODE deletion_rear(NODE);
int count_nodes(NODE);
void search(NODE, int);

void main()
{
    NODE first; // first variable always points to first node in Linked List(DLL)
    int item, choice, pos;
    first = NULL; // Linked List(dlL) is empty
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            first = insertion_front(item, first); // used to insert node at front end in DLL
            break;
        case 2:
            first = deletion_front(first); // used to delete node at front end in DLL
            break;
        case 3:
            display(first);
            break;
        case 4:
            scanf("%d", &item);
            first = insertion_rear(item, first); // used to insert node at rear end in DLL
            break;
        case 5:
            first = deletion_rear(first); // used to delete node at rear end in DLL
            break;
        case 6:
            printf("No of nodes in DLL = %d\n", count_nodes(first));
            break;
        case 7:
            // printf("Enter the item to search\n");
            scanf("%d", &item);
            search(first, item);
            break;
        case 8:
            exit(0);
        }
    }
}

NODE insertion_front(int item, NODE first)
{
    NODE temp;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (first == NULL)
    {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If DLL is empty
        printf("Empty DLL - Cannot display\n");
        return;
    }
    temp = first; // If DLL is not empty
    while (temp != NULL)
    {
        printf("%d", temp->info);
        temp = temp->rlink;
        printf("->");
    }
    printf("\n");
}

NODE deletion_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If DLL is empty
        printf("Empty DLL - Cannot delete\n");
        return NULL;
    }

    if (first->rlink == NULL)
    {
        printf("Deleted element from DLL is %d\n", first->info);
        free(first);
        return NULL;
    } // If DLL is not empty
    temp = first;
    first = first->rlink;
    first->llink = NULL;
    printf("Deleted element from DLL is %d\n", temp->info);
    free(temp);
    return first;
}

NODE insertion_rear(int item, NODE first)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (first == NULL)
    { // If DLL is empty, return new node as first node in DLL
        return temp;
    }
    cur = first; // If DLL has more than one node
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}

NODE deletion_rear(NODE first)
{
    NODE prev, cur;
    if (first == NULL)
    { // If DLL is empty
        printf("Empty DLL - Cannot delete\n");
        return NULL;
    }
    if (first->rlink == NULL)
    { // If DLL has only one node
        printf("Deleted element from DLL is %d\n", first->info);
        free(first);
        return NULL;
    }
    prev = NULL; // If DLL has more than one node
    cur = first;
    while (cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }
    printf("Deleted element from DLL is %d\n", cur->info);
    free(cur);
    prev->rlink = NULL;
    return first;
}
int count_nodes(NODE first)
{
    int count = 0;
    NODE temp = first;
    while (temp != NULL)
    {
        count++;
        temp = temp->rlink;
    }
    return count;
}

void search(NODE first, int item)
{
    NODE temp = first;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->info == item)
        {
            found = 1;
            break;
        }
        temp = temp->rlink;
    }
    if (found)
    {
        printf("%d is found in DLL\n", item);
    }
    else
    {
        printf("%d is not found in DLL\n", item);
    }
}
//--------------------------------queues using linked list-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("Insufficient memory\n");  \
        exit(0);                          \
    }

struct node
{ // To define node structure
    int info;
    struct node *link;
};

typedef struct node *NODE; // Renamed struct node* as NODE using typedef

// QUEUE operations list
void display(NODE);
NODE deletion_front(NODE);
NODE insertion_rear(int, NODE);

void main()
{
    NODE first; // first variable always points to first node in QUEUE
    int item, choice, pos;
    first = NULL; // QUEUE is empty
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            first = insertion_rear(item, first); // used to insert node at rear end in QUEUE
            break;
        case 2:
            first = deletion_front(first); // used to delete node at front end in QUEUE
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }
}

void display(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If SLL is empty
        printf("EMPTY QUEUE-NOTHING TO DISPLAY\n");
        return;
    }
    printf("THE ELEMENTS OF  QUEUE  ARE -");
    temp = first; // If QUEUE is not empty
    while (temp != NULL)
    {
        printf("%d", temp->info);
        temp = temp->link;
        printf("->");
    }
    printf("\n");
}

NODE deletion_front(NODE first)
{
    NODE temp;
    if (first == NULL)
    { // If SLL is empty
        printf("QUEUE UNDERFLOW - No nodes to delete\n");
        return NULL;
    }
    temp = first; // If QUEUE is not empty
    first = first->link;
    printf("The DEQUEUED  Node VAL = %d\n", temp->info);
    free(temp);
    return first;
}
NODE insertion_rear(int item, NODE first)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
    { // If QUEUE is empty, return new node as first node in SLL
        return temp;
    }
    cur = first; // If QUEUE has more than one node
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
