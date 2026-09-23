#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *head   = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third  = (struct Node *)malloc(sizeof(struct Node));

    head->data   = 10;
    second->data = 20;
    third->data  = 30;


    head->next   = second;
    second->next = third;
    third->next  = head;      

    head->prev   = third;   
    second->prev = head;
    third->prev  = second;

    struct Node *temp = head;


    printf("Forward Print: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");


    temp = head->prev;   
    printf("Backward Print: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to last node)\n");

    return 0;
}