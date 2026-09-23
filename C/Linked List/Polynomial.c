#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coff;
    int exp;
    struct Node *next;
};

struct Node *head = NULL;

// Create
struct Node* create()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *newNode;

    printf("Enter the value of Coeff and Exp: ");
    scanf("%d %d", &ptr->coff, &ptr->exp);
    head = ptr;
    char ch;
    do
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the value of Coeff and Exp: ");
        scanf("%d %d", &newNode->coff, &newNode->exp);

        ptr->next = newNode;
        ptr = newNode;

        printf("Press Y for more Nodes: ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    ptr->next = NULL;
    return head;
}

// Polynomial Addition

struct Node* add(struct Node *p, struct Node *q){
    struct Node *head = NULL;
    struct Node *last = NULL;
    struct Node *ptr;

    while(p != NULL && q != NULL){
        ptr = (struct Node *)malloc(sizeof(struct Node));

        if()
    }
    
}

// Display
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->coff);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    create();

    display();
}
