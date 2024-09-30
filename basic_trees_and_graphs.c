// -------------------------create and insertion in a bst---------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memory\n");  \
        exit(0);                          \
    }

// To declare BST node structure
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

// To insert or create BST
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("Duplicate items are not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

// To display the content of BST in inorder
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

// To search node in BST
NODE search(int item, NODE root)
{
    NODE cur;
    if (root == NULL)
        return NULL; // empty tree
    cur = root;
    while (cur != NULL)
    { // search for the item
        if (item == cur->info)
            return cur; // If key found, return the node
        if (item < cur->info)
            cur = cur->llink; // search towards left
        else
            cur = cur->rlink; // search towards right
    }
    return NULL; // key not found
}

// To delete a node in BST
NODE delete(int item, NODE root)
{
    NODE cur, parent, suc, q;
    if (root == NULL)
    {
        printf("Cannot delete - %d is not found or BST empty\n", item);
        return root;
    }
    parent = NULL, cur = root; // obtain node to be deleted, its parent
    while (cur != NULL)
    {
        if (item == cur->info)
            break;
        parent = cur;
        cur = (item < cur->info) ? cur->llink : cur->rlink;
    }
    if (cur == NULL)
    {
        printf("Cannot delete - %d is not found or BST empty\n", item);
        return root;
    }
    // Item found and delete it
    if (cur->llink == NULL)      // If left subtree is empty
        q = cur->rlink;          // obtain non-empty right subtree
    else if (cur->rlink == NULL) // If right subtree is empty
        q = cur->llink;          // obtain non-empty left subtree
    else
    {
        // CASE-2
        suc = cur->rlink; // obtain inorder successor
        while (suc->llink != NULL)
            suc = suc->llink;
        suc->llink = cur->llink; // Attach left of node to be deleted to left of successor of node to be deleted
        q = cur->rlink;
    }
    if (parent == NULL)
    {
        printf("%d is found and deleted from BST\n", item);
        free(cur);
        return q; // If parent does not exist return q as root
    }
    // connecting parent of the node to be deleted to q
    if (cur == parent->llink)
        parent->llink = q;
    else
        parent->rlink = q;
    printf("%d is found and deleted from BST\n", item);
    free(cur);
    return root;
}

void main()
{
    NODE root, search_node;
    int item, choice, item_search, item_deleted;
    root = NULL;
    printf("Binary Search Tree Operations\n");
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            /*  if (root == NULL) {
                  printf("BST EMPTY\n");
                  break;
              }*/
            scanf("%d", &item_deleted);
            root = delete (item_deleted, root);
            break;
        case 3:
            if (root == NULL)
            {
                printf("BST EMPTY\n");
            }
            else
            {
                printf("INORDER TRAVERSAL OF BST: ");
                inorder(root);
                printf("\n");
            }
            break;
        case 4:
            /*if (root == NULL) {
                printf("BST EMPTY\n");
                break;
            }*/
            scanf("%d", &item_search);
            search_node = search(item_search, root);
            if (search_node == NULL)
                printf("Search Unsuccessful %d is not found in BST\n", item_search);
            else
                printf("Search Successful %d is found in BST\n", item_search);
            break;

        case 5:
            exit(0);
        case 6:
            printf("Invalid Choice\n");
        }
    }
}

//---------------------- operations on Binary Search Tree----------------------------
// 1.Create - Insert BST  2.NODE COUNT 3.HEIGHT  4.MINIMUM 5. MAXIMUM 6.Exit
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("Insufficient memory\n");  \
        exit(0);                          \
    }

// To declare BST node structure
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
int count = 0;

// To find maximum value in BST
NODE maximum(NODE root)
{
    NODE cur;
    if (root == NULL)
        return root;
    cur = root;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    return cur;
}

// To find minimum value in BST
NODE minimum(NODE root)
{
    NODE cur;
    if (root == NULL)
        return root;
    cur = root;
    while (cur->llink != NULL)
    {
        cur = cur->llink;
    }
    return cur;
}

// To count nodes in BST
int count_nodes(NODE root)
{
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->llink) + count_nodes(root->rlink);
}

// To find height of a given BST
/*function to find maximum of two numbers*/
int max(int a, int b)
{
    return (a > b) ? a : b;
}
/*function to find height of the tree*/
int height(NODE root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->llink), height(root->rlink));
}

// To insert or create BST
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("Duplicate items are not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

int main()
{
    NODE root = NULL;
    NODE max, min;
    int item, choice, ht;

    printf("Binary Search Tree Operations\n");

    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("TREE is empty\n");
                break;
            }
            count = count_nodes(root);
            printf("NUMBER OF NODES IN BST = %d\n", count);
            break;
        case 3:
            if (root == NULL)
            {
                printf("TREE is empty\n");
                break;
            }
            ht = height(root);
            printf("HEIGHT OF BST IS = %d\n", ht);
            break;
        case 4:
            if (root == NULL)
            {
                printf("TREE is empty\n");
                break;
            }
            min = minimum(root);
            printf("MINIMUM VALUE IN BST IS = %d\n", min->info);
            break;
        case 5:
            if (root == NULL)
            {
                printf("TREE is empty\n");
                break;
            }
            max = maximum(root);
            printf("MAXIMUM VALUE IN BST IS = %d\n", max->info);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}

//---------------------Inorder Preorder and Postorder traversals of Binary search Tree using recursion------------------

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("Insufficient memory\n");  \
        exit(0);                          \
    }

// To declare BST node structure
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

// To insert or create BST
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("Duplicate items are not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

// Traverse the tree in preorder
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

// Traverse the tree in postorder
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

// Traverse the tree in inorder
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

void main()
{
    NODE root;
    int item, choice;
    root = NULL;
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("BST Empty\n");
            }
            else
            {
                printf("PREORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                preorder(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("BST Empty\n");
            }
            else
            {
                printf("INORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                inorder(root);
                printf("\n");
            }
            break;
        case 4:
            if (root == NULL)
            {
                printf("BST Empty\n");
            }
            else
            {
                printf("POSTORDER TRAVERSAL OF BINARY SEARCH TREE\n");
                postorder(root);
                printf("\n");
            }
            break;

        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}

//-----------------------IMPLEMENT LEVEL ORDER TRAVERSAL ON  A BST-----------------------

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memory\n");  \
        exit(0);                          \
    }

// To declare BST node structure
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;

// To insert or create BST
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("Duplicate items are not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

// To display the content of BST in level order
void level_order(NODE root)
{
    if (root == NULL)
    {
        printf("BST EMPTY - LOT/BFS NOT POSSIBLE\n");
        return;
    }
    NODE q[100], cur;
    int front = 0, rear = -1;
    q[++rear] = root;
    printf("LEVEL ORDER TRAVERSAL OF BINARY SEARCH TREE\n");
    while (front <= rear)
    {
        cur = q[front++];
        printf("%d ", cur->info);
        if (cur->llink != NULL)
            q[++rear] = cur->llink;
        if (cur->rlink != NULL)
            q[++rear] = cur->rlink;
    }
    printf("\n");
}

void main()
{
    NODE root;
    int item, choice;
    root = NULL;
    for (;;)
    {
        // printf("1.insertion 2.level_order traversal\n");
        // printf("3.exit\n");
        // printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // printf("enter the item to be inserted\n");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            level_order(root);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice\n");
            exit(0);
        }
    }
}

//--------------------------------Adjacency List of a given graph.------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
/****************To allocate memory for new node during runtime**************/
#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memeory\n"); \
        exit(0);                          \
    }
/*******************To delcare node structure**********************/
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE insertion_rear(int, NODE);
/*****************************To read adjacency list******************************/
NODE insertion_rear(int item, NODE first)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
    {
        return temp;
    }
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
void read_adjacency_list(int n, NODE a[])
{
    int i, j, m, item;
    for (i = 0; i < n; i++)
    {
        // printf("enter the number of nodes adjacent to %d:",i);
        scanf("%d", &m);
        if (m == 0)
            continue;
        // printf("enter nodes adjacent to %d:\n",i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &item);
            a[i] = insertion_rear(item, a[i]);
        }
    }
}
/*********************************display operation***********************/
void display_adjacency_list(int n, NODE a[])
{
    int i;
    NODE temp;
    printf("Adjacency Linked List elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("a[%d]=", i);
        temp = a[i];
        if (temp == NULL)
            printf("NULL\n");
        else
        {
            temp = a[i];
            while (temp->link != NULL)
            {
                printf("%d-->", temp->info);
                temp = temp->link;
            }
            printf("%d\n", temp->info);
        }
    }
}
void main()
{
    NODE a[10];
    int vertices, choice, i, n;
    //  printf("enter number of vertices to be inserted\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) // Create initial array of n linked lists
    {
        a[i] = NULL;
    }
    for (;;)
    {
        // printf("1.insertion 2.display\n");
        // printf("3.exit\n");
        // printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            read_adjacency_list(n, a);
            break;
        case 2:
            display_adjacency_list(n, a);
            break;
        case 3:
            exit(0);
        default:
            printf("please enter valid choice\n");
        }
    }
}
//------------------------- traverse the graph in DFS order.---------------------------------------------------

#include <stdio.h>
int a[10][10], s[10], n; // Global variables

void read_adjacency_matrix(int a[10][10], int n) // read adjacency matrix
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void dfs(int u)
{
    int v;
    s[u] = 1;
    printf("%d\t", u);
    for (v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && s[v] == 0)
            dfs(v); // recursive function
    }
}

void main()
{
    int i, source;
    // printf("enter number of nodes in the graph\n");
    scanf("%d", &n);
    //  printf("enter the adjacency matrix\n");
    read_adjacency_matrix(a, n);
    for (source = 0; source < n; source++)
    {
        for (i = 0; i < n; i++)
        {
            s[i] = 0;
        }
        printf("\n the nodes reachable from %d :", source);
        dfs(source);
    }
}

//------------------------------traverse the graph in BFS order.----------------------------------------------------------
#include <stdio.h>
int a[10][10], s[10], n;                         // Global variables
void read_adjacency_matrix(int a[10][10], int n) // read adjacency matrix
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs(int a[10][10], int n, int u)
{
    int f, r, q[10], v;
    int s[10] = {0}; // intialize all elements in S to 0 i.e., no node is visited
    printf("The nodes visited form %d:", u);
    f = 0, r = -1;     // queue is empty
    q[++r] = u;        // insert u into queue
    s[u] = 1;          // insert u to source
    printf("%d\t", u); // print the node visited
    while (f <= r)
    {
        u = q[f++]; // delete an element from queue
        for (v = 0; v < n; v++)
        {
            if (a[u][v] == 1)
            {
                if (s[v] == 0)
                {
                    printf("%d\t", v);
                    s[v] = 1;
                    q[++r] = v; // insert v into queue
                }
            }
        }
    }
    printf("\n");
}

void main()
{
    int i, source;
    // printf("enter number of nodes in the graph\n");
    scanf("%d", &n);
    // printf("enter the adjacency matrix\n");
    read_adjacency_matrix(a, n);
    for (source = 0; source < n; source++)
    {
        bfs(a, n, source);
    }
}

//----------------------------------Hashing using sll----------------------------

#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 5

#define MALLOC(p, n, type)                \
    p = (type *)malloc(n * sizeof(type)); \
    if (p == NULL)                        \
    {                                     \
        printf("insufficient memeory\n"); \
        exit(0);                          \
    }

struct node // To delcare node structure
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE search_sll(int, NODE);
NODE insertion_rear(int, NODE);
int search_hash_table(int, NODE[]);
int H(int);
/***************************insertion operation****************************/
void insert_hash_table(int item, NODE a[])
{
    int h_value;
    h_value = H(item);
    a[h_value] = insertion_rear(item, a[h_value]); // insertion_rear from SLL
}
int H(int k) // To compute hash value for the given key
{
    return k % HASH_SIZE;
}
NODE insertion_rear(int item, NODE first)
{
    NODE temp, cur;
    MALLOC(temp, 1, struct node);
    temp->info = item;
    temp->link = NULL;
    if (first == NULL)
    {
        return temp;
    }
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}
/**********************Search Operation*******************/
NODE search_sll(int key, NODE first)
{
    NODE cur;
    if (first == NULL)
    {
        printf("SLL is empty\n");
        return NULL;
    }
    /*compare one after the other*/
    cur = first;
    while (cur != NULL)
    {
        if (key == cur->info)
            break;
        cur = cur->link;
    }
    return cur;
}
int search_hash_table(int key, NODE a[])
{
    int h_value;
    NODE cur;
    h_value = H(key);
    cur = search_sll(key, a[h_value]); // Search operation from SLL
    if (cur == NULL)
        return 0;
    else
        return 1;
}
/*********************************display operation***********************/
void display_hash_table(NODE a[])
{
    int i;
    NODE temp;
    for (i = 0; i < HASH_SIZE; i++)
    {
        printf("a[%d]=", i);
        temp = a[i];
        if (temp == NULL)
            printf("NULL\n");
        else
        {
            temp = a[i];
            while (temp->link != NULL)
            {
                printf("%d-->", temp->info);
                temp = temp->link;
            }
            printf("%d\n", temp->info);
        }
    }
}
void main()
{
    NODE a[10];
    int item, key, choice, flag, i;
    for (i = 0; i < HASH_SIZE; i++) // Create initial hash table
    {
        a[i] = NULL;
    }
    for (;;)
    {
        // printf("1.insertion 2.Search\n");
        // printf("3.display 4.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // printf("enter the item to be inserted\n");
            scanf("%d", &item);
            insert_hash_table(item, a);
            break;
        case 2: // printf("enter the key item\n");
            scanf("%d", &key);
            flag = search_hash_table(key, a);
            if (flag == 0)
            {
                printf("key is not found\n");
            }
            else
            {
                printf("key is found\n");
            }
            break;
        case 3:
            printf("content of hash table\n");
            display_hash_table(a);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("please enter valid choice\n");
        }
    }
}