#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coff;
    int exp;
    struct Node *next;
};

// Create Polynomial
struct Node* create()
{
    struct Node *head = NULL, *ptr, *newnode;
    char ch;

    do
    {
        newnode = malloc(sizeof(struct Node));

        printf("Enter Coeff and Exp: ");
        scanf("%d %d", &newnode->coff, &newnode->exp);

        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;

        printf("More nodes? Y/N: ");
        scanf(" %c", &ch);

    } while (ch == 'Y' || ch == 'y');

    return head;
}

// Addition
struct Node* add(struct Node *p, struct Node *q)
{
    struct Node *head = NULL, *ptr, *newnode;

    while (p != NULL && q != NULL)
    {
        newnode = malloc(sizeof(struct Node));

        if (p->exp == q->exp)
        {
            newnode->coff = p->coff + q->coff;
            newnode->exp = p->exp;

            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            newnode->coff = p->coff;
            newnode->exp = p->exp;

            p = p->next;
        }
        else
        {
            newnode->coff = q->coff;
            newnode->exp = q->exp;

            q = q->next;
        }

        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
    }

    // Remaining terms of P
    while (p != NULL)
    {
        newnode = malloc(sizeof(struct Node));

        newnode->coff = p->coff;
        newnode->exp = p->exp;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
        p = p->next;
    }

    // Remaining terms of Q
    while (q != NULL)
    {
        newnode = malloc(sizeof(struct Node));

        newnode->coff = q->coff;
        newnode->exp = q->exp;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            ptr->next = newnode;

        ptr = newnode;
        q = q->next;
    }

    return head;
}

// Display
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Node *p, *q, *r;

    printf("Enter First Polynomial:\n");
    p = create();

    printf("\nEnter Second Polynomial:\n");
    q = create();

    printf("\nP1 = ");
    display(p);

    printf("P2 = ");
    display(q);

    r = add(p, q);

    printf("Addition = ");
    display(r);

    return 0;
}