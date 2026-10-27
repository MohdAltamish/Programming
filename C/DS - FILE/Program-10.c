// Write a C program to Implement Queue using Array and linked list.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node
{
    int data;
    struct node *next;
};

// ---------- QUEUE USING ARRAY ----------
int queue[MAX];
int front = -1, rear = -1;

void enqueue_array(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
    printf("%d inserted\n", x);
}

void dequeue_array()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d deleted\n", queue[front++]);
}

void display_array()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// ---------- QUEUE USING LINKED LIST ----------
struct node *qfront = NULL, *qrear = NULL;

void enqueue_list(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    if (qrear == NULL)
    {
        qfront = qrear = newnode;
    }
    else
    {
        qrear->next = newnode;
        qrear = newnode;
    }
    printf("%d inserted\n", x);
}

void dequeue_list()
{
    struct node *temp;
    if (qfront == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    temp = qfront;
    printf("%d deleted\n", temp->data);
    qfront = qfront->next;
    if (qfront == NULL)
        qrear = NULL;
    free(temp);
}

void display_list()
{
    struct node *temp = qfront;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front to rear): ");
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
        printf("\n[ARRAY QUEUE] 1.Enqueue 2.Dequeue 3.Display 4.Back: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue_array(x);
        }
        else if (ch == 2)
            dequeue_array();
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
        printf("\n[LINKED LIST QUEUE] 1.Enqueue 2.Dequeue 3.Display 4.Back: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue_list(x);
        }
        else if (ch == 2)
            dequeue_list();
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
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    while (1)
    {
        printf("\n========== QUEUE USING ARRAY AND LINKED LIST ==========\n");
        printf("MAIN MENU: \n 1.Array Queue \n 2.Linked List Queue \n 3.Exit: ");
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