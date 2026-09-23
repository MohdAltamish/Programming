#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lpt;
    struct node *rpt;
};

struct node *head = NULL;

// CREATE
void create()
{
    struct node *ptr, *cpt;
    char ch;

    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &ptr->data);

    head = ptr;
    ptr->lpt = NULL;

    do
    {
        printf("Add another node? (Y/N): ");
        scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y')
        {
            cpt = (struct node*)malloc(sizeof(struct node));

            printf("Enter data: ");
            scanf("%d", &cpt->data);

            ptr->rpt = cpt;
            cpt->lpt = ptr;

            ptr = cpt;
        }

    } while (ch == 'Y' || ch == 'y');

    ptr->rpt = NULL;
}

// DISPLAY FORWARD
void display()
{
    struct node *temp = head;

    printf("List (Forward): ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->rpt;
    }

    printf("NULL\n");
}

// DISPLAY REVERSE
void reverse_display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Go to last node
    while (temp->rpt != NULL)
    {
        temp = temp->rpt;
    }

    printf("List (Reverse): ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->lpt;
    }

    printf("NULL\n");
}

// INSERT AT BEGINNING
void insert_begin()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->lpt = NULL;
    newnode->rpt = head;

    if (head != NULL)
        head->lpt = newnode;

    head = newnode;
}

// INSERT AT END
void insert_end()
{
    struct node *temp = head, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->rpt = NULL;

    if (head == NULL)
    {
        newnode->lpt = NULL;
        head = newnode;
        return;
    }

    while (temp->rpt != NULL)
        temp = temp->rpt;

    temp->rpt = newnode;
    newnode->lpt = temp;
}

// INSERT AT POSITION
void insert_pos()
{
    int pos, i;
    struct node *temp = head, *newnode;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->lpt = NULL;
        newnode->rpt = head;

        if (head != NULL)
            head->lpt = newnode;

        head = newnode;
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->rpt;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->rpt = temp->rpt;
    newnode->lpt = temp;

    if (temp->rpt != NULL)
        temp->rpt->lpt = newnode;

    temp->rpt = newnode;
}

// MAIN MENU
int main()
{
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    int choice;

    create();

    while (1)
    {
        printf("\n========== DOUBLY LINKED LIST MENU ==========\n");
        printf("1. Display\n");
        printf("2. Reverse Display\n");
        printf("3. Insert Begin\n");
        printf("4. Insert End\n");
        printf("5. Insert Position\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display();
                break;

            case 2:
                reverse_display();
                break;

            case 3:
                insert_begin();
                break;

            case 4:
                insert_end();
                break;

            case 5:
                insert_pos();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
