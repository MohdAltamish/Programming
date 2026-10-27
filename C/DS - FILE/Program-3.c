/* Write a C program to implement Linked List and perform various operations:
a) Insertion at:  i) Beg	ii) End	iii) Any position
b) Deletion from:  i) Beg   ii) End	 iii) Any position       
c) Display the Linked List
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

/* Create Linked List */
void create()
{
    struct node *head;
    struct node *ptr;
    struct node *cpt;
    char yn;

    head = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &head->data);

    head->next = NULL;
    start = head;
    cpt = head;

    printf("Do you want to add another node? (y/n): ");
    scanf(" %c", &yn);

    while (yn == 'y' || yn == 'Y')
    {
        ptr = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of the node: ");
        scanf("%d", &ptr->data);

        ptr->next = NULL;
        cpt->next = ptr;
        cpt = ptr;

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &yn);
    }
}

/* Traverse Linked List */
void traverse()
{
    struct node *temp = start;

    if (start == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Insert at Beginning */
void inAtBeg()
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &newNode->data);

    newNode->next = start;
    start = newNode;
}

/* Insert at End */
void inAtEnd()
{
    struct node *newNode;
    struct node *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
        return;
    }

    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

/* Insert at Position */
void inAtPos()
{
    struct node *newNode;
    struct node *p;
    int pos;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &newNode->data);

    printf("Enter the position to add the new node: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    if (pos == 1)
    {
        newNode->next = start;
        start = newNode;
        return;
    }

    p = start;

    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = p->next;
    p->next = newNode;
}

/* Delete from Beginning */
void delAtBeg()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    ptr = start;
    start = start->next;

    free(ptr);
}

/* Delete from End */
void delAtEnd()
{
    struct node *temp;
    struct node *prev;

    if (start == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }

    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    prev = start;

    while (prev->next != temp)
    {
        prev = prev->next;
    }

    prev->next = NULL;
    free(temp);
}

/* Delete from Position */
void delAtPos()
{
    int pos;
    struct node *p;
    struct node *q;

    printf("Enter the node position to delete: ");
    scanf("%d", &pos);

    if (start == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    if (pos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        q = start;
        start = start->next;
        free(q);
        return;
    }

    p = start;

    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }

    if (p == NULL || p->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    q = p->next;
    p->next = q->next;

    free(q);
}

/* Main Function */
int main()
{
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    int choice;

    do
    {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Traverse Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                printf("Linked list created successfully.\n");
                traverse();
                break;

            case 2:
                traverse();
                break;

            case 3:
                inAtBeg();
                printf("Node inserted at beginning.\n");
                traverse();
                break;

            case 4:
                inAtEnd();
                printf("Node inserted at end.\n");
                traverse();
                break;

            case 5:
                inAtPos();
                printf("Node inserted at position.\n");
                traverse();
                break;

            case 6:
                delAtBeg();
                printf("Node deleted from beginning.\n");
                traverse();
                break;

            case 7:
                delAtEnd();
                printf("Node deleted from end.\n");
                traverse();
                break;

            case 8:
                delAtPos();
                printf("Node deleted from position.\n");
                traverse();
                break;

            case 9:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}