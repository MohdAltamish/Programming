#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Info;
    struct node *Link;
};

struct node *START = NULL;

void create(){

    char ch = 'Y';
    do{
        struct node *cpt, *ptr;
    struct node *last = NULL;
    
        cpt = (struct node *)malloc(sizeof(struct node));
        ptr = (struct node *)malloc(sizeof(struct node));

        printf("Enter a data: ");
        scanf("%d", &cpt->Info);

        ptr -> Link = cpt;
        ptr = cpt;
    }
    
        while(ch == 'Y') {
            ptr -> Link = NULL;
        };
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