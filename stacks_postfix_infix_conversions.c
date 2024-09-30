//-------------------------------------stack implementation-------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define stack_size 4
int top;
int s[10];

void push(int item) // push or insertion operation
{
    if (top == stack_size - 1)
    {
        printf("Stack Overflow-Cannot Push\n");
        return;
    }
    top = top + 1;
    s[top] = item;
}

int pop() // pop or deletion operation
{
    if (top == -1)
    {
        return 0;
    }
    return s[top--];
}

void display() // display operation
{
    if (top == -1)
    {
        printf("Stack is Empty-No elements to Display\n");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
    printf("\n");
}

void peek() // to access topmost element from stack
{
    if (top == -1)
    {
        printf("Empty stack- No peek\n");
        return;
    }
    printf("The top most element in stack is :%d\n", s[top]);
}

void main()
{
    int item;
    int item_deleted;
    int choice;
    top = -1;
    for (;;)
    {
        // printf("1.PUSH 2.POP\n");
        // printf("3.display 4.exit\n");
        // printf("enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // printf("enter the item to be inserted\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            item_deleted = pop();
            if (item_deleted == 0)
                printf("Stack Underflow-Cannot Pop\n");
            else
                printf("\nThe popped element is :%d\n", item_deleted);
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        } /*switch close*/
    } /*forloop close*/
} /*main() close*/
//--------------------------------------infix to postfix conversion------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*Stack precedence function F*/
int F(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 8;
    }
}

/*input precedence function G*/
int G(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int isValidSymbol(char symbol)
{
    return isalnum(symbol) || strchr("+-*/^()", symbol);
}

int checkParentheses(char infix[])
{
    int balance = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
            balance++;
        if (infix[i] == ')')
            balance--;
        if (balance < 0)
            return 0; // Imbalanced braces
    }
    return balance == 0; // Should be balanced
}

void infix_postfix(char infix[], char postfix[])
{
    int top;        // points to top of stack
    int j;          // index for postfix expression
    int i;          // index to access infix expression
    char s[30];     // acts storage for stack elements
    char symbol;    // holds char from infix expression
    top = -1;       // stack is empty
    s[++top] = '#'; // Initialize stack to #
    j = 0;          // output is empty. So, j=0
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i]; // scan the next symbol
        if (!isValidSymbol(symbol))
        {
            printf("Incorrect Infix Expression - Invalid Symbols\n");
            return;
        }
        // If the stack precedence is greater, remove symbol from stack and place into postfix
        while (F(s[top]) > G(symbol))
        {
            postfix[j] = s[top--];
            j++;
        }
        if (F(s[top]) != G(symbol))
        {
            s[++top] = symbol; // push the input symbol
        }
        else
            top--; // discard '(' from stack
    }

    // Pop remaining symbols and place them in postfix expression
    while (s[top] != '#')
    {

        postfix[j++] = s[top--];
    }
    postfix[j] = '\0'; // attach NULL char at the end to frame a string
}

void main()
{
    char infix[30];
    char postfix[30];
    scanf("%s", infix);
    // Check for invalid symbols first
    for (int i = 0; i < strlen(infix); i++)
    {
        if (!isValidSymbol(infix[i]))
        {
            printf("Incorrect Infix Expression - Invalid Symbols\n");
            return;
        }
    }
    // Check for missing close and open braces braces
    if (!checkParentheses(infix))
    {
        printf("Invalid Infix Expression - Imbalanced braces\n");
        return;
    }
    printf("Given infix expression is : %s\n", infix);
    infix_postfix(infix, postfix);
    if (strlen(postfix) > 0)
    {
        printf("Postfix expression is : %s\n", postfix);
    }
}
//--------------------------------------postfix evaluation----------------------------------
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define max 100
float st[max];
int top = -1;
void push(float st[], float val)
{
    if (top == max - 1)
    {
        printf("\nstack overflow");
    }
    else
    {
        top++;
        st[top] = val;
    }
}
float pop(float st[])
{
    float val = -1;
    if (top == -1)
    {
        printf("\nStack Underflow - missing operands / insufficient postfix exp");
        exit(0);
    }
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

float evaluatepostfixexp(char exp[])
{
    int i = 0;
    float op1, op2, val;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else if (isalpha(exp[i]))
        {
            float a;
            scanf("%f", &a);
            push(st, a);
        }
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(st, val);
        }
        i++;
    }
    double res = pop(st);
    if (top != -1)
    {
        printf("Insufficient POSTFIX Expression");
        exit(0);
    }
    return res;
}
int main()
{
    float val;
    char exp[100];
    scanf("%s", exp);
    val = evaluatepostfixexp(exp);
    printf("The result is : %.2f", val);
}
//----------------------------------stacks using linked list--------------------------------------------------------------

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

NODE insertion_front(int, NODE); // STACK operations list
void display(NODE);
NODE deletion_front(NODE);

void main()
{
    NODE first; // first variable always points to first node in STACK
    int item, choice, pos;
    first = NULL; // STACK is empty
    for (;;)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &item);
            first = insertion_front(item, first); // used to insert node at front end in STACK
            break;
        case 2:
            first = deletion_front(first); // used to delete node at front end in STACK
            break;
        case 3:
            display(first);
            break;
        case 4:
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
    { // If STACK is empty
        printf("EMPTY STACK - NOTHING TO DISPLAY\n");
        return;
    }
    printf("THE ELEMENTS OF STACK ARE -\n");
    temp = first; // If STACK is not empty
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
    { // If STACK is empty
        printf("STACK UNDERFLOW - CANNOT POP\n");
        return NULL;
    }
    temp = first; // If STACK is not empty
    first = first->link;
    printf("Popped element from stack is %d\n", temp->info);
    free(temp);
    return first;
}
