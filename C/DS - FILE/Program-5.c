/*
    Program to implement a Circular Linked List with the following operations:
    a) Create a Circular Linked List
    b) Display the contents of the Circular Linked List
    c) Insert a node at the beginning of the Circular Linked List
    d) Insert a node at the end of the Circular Linked List
    e) Insert a node at a specified position in the Circular Linked List
    f) Delete a node from the beginning of the Circular Linked List
    g) Delete a node from the end of the Circular Linked List
    h) Delete a node from a specified position in the Circular Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *newNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

int count()
{
    int n = 0;
    struct Node *temp;

    if (head == NULL)
        return 0;

    temp = head;

    do
    {
        n++;
        temp = temp->next;
    } while (temp != head);

    return n;
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}

void insertBeg()
{
    int value;
    struct Node *node, *last;

    printf("Enter value: ");
    scanf("%d", &value);

    node = newNode(value);

    if (head == NULL)
    {
        head = node;
        node->next = head;
    }
    else
    {
        last = head;
        while (last->next != head)
            last = last->next;

        node->next = head;
        last->next = node;
        head = node;
    }
}

void insertEnd()
{
    int value;
    struct Node *node, *last;

    printf("Enter value: ");
    scanf("%d", &value);

    node = newNode(value);

    if (head == NULL)
    {
        head = node;
        node->next = head;
        return;
    }

    last = head;
    while (last->next != head)
        last = last->next;

    last->next = node;
    node->next = head;
}

void insertPos()
{
    int value, pos, i;
    struct Node *node, *temp;

    printf("Enter value and position: ");
    scanf("%d %d", &value, &pos);

    if (pos < 1 || pos > count() + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        node = newNode(value);

        if (head == NULL)
        {
            head = node;
            node->next = head;
            return;
        }

        temp = head;
        while (temp->next != head)
            temp = temp->next;

        node->next = head;
        temp->next = node;
        head = node;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    node = newNode(value);
    node->next = temp->next;
    temp->next = node;
}

void deleteBeg()
{
    struct Node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);
}

void deleteEnd()
{
    struct Node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    last = temp->next;
    temp->next = head;
    free(last);
}

void deletePos()
{
    int pos, i;
    struct Node *temp, *del;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count())
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeg();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;
    free(del);
}

int main()
{
    int choice;

    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertPos(); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: deletePos(); break;
            case 7: display(); break;
            case 8: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}