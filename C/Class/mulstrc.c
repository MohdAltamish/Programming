#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Info;
    struct node *Link;
};

struct node *START = NULL;


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Info;
    struct node *Link;
};

struct node *START = NULL;

void create(void){
    struct node *ptr;
    struct node *last = NULL;

    for (int i = 0; i < 10; i++)
    {
        ptr = malloc(sizeof(struct node));

        if (ptr == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data: ");

        if (scanf("%d", &ptr->Info) != 1)
        {
            printf("Invalid input.\n");
            free(ptr);
            return;
        }

        ptr->Link = NULL;

        if (START == NULL)
        {
            START = ptr;
        }
        else
        {
            last->Link = ptr;
        }

        last = ptr;
    }
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

int main()
{
    create();
    traverse();
}