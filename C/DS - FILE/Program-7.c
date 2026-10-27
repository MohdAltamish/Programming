// Write a C program to Implement Stack using Array and Linked List.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node
{
    int data;
    struct node *next;
};

// ---------- STACK USING ARRAY ----------
int stack[MAX];
int top = -1;

void push_array(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed\n", x);
}

void pop_array()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top--]);
}

void display_array()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// ---------- STACK USING LINKED LIST ----------
struct node *head = NULL;

void push_list(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = x;
    newnode->next = head;
    head = newnode;
    printf("%d pushed\n", x);
}

void pop_list()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    temp = head;
    printf("%d popped\n", temp->data);
    head = head->next;
    free(temp);
}

void display_list()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void array_menu()
{
    int ch, x;
    while (1)
    {
        printf("\n[ARRAY STACK] 1.Push 2.Pop 3.Display 4.Back: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            push_array(x);
        }
        else if (ch == 2)
            pop_array();
        else if (ch == 3)
            display_array();
        else if (ch == 4)
            return;
        else
            printf("Invalid choice\n");
    }
}

void list_menu()
{
    int ch, x;
    while (1)
    {
        printf("\n[LINKED LIST STACK] 1.Push 2.Pop 3.Display 4.Back: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            push_list(x);
        }
        else if (ch == 2)
            pop_list();
        else if (ch == 3)
            display_list();
        else if (ch == 4)
            return;
        else
            printf("Invalid choice\n");
    }
}

// MAIN MENU
int main()
{
    int ch;
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    while (1)
    {
        printf("\n========== STACK USING ARRAY AND LINKED LIST ==========\n");
        printf("MAIN MENU: 1.Array Stack 2.Linked List Stack 3.Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
            array_menu();
        else if (ch == 2)
            list_menu();
        else if (ch == 3)
            break;
        else
            printf("Invalid choice\n");
    }
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}