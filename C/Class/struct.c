#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Info;
    struct node *Link;
};

struct node *START = NULL;

void create(void)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &ptr->Info);

    START = ptr;
    ptr->Link = NULL;
}

void traverse(void)
{
    struct node *ptr = START;
    while (ptr != NULL)
    {
        printf("%d ", ptr->Info);
        ptr = ptr->Link;
    }
    printf("\n");
}

int main(void)
{
    create();
    traverse();
}
