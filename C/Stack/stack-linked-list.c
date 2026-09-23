#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

void pop(){
    if (top == NULL){
        printf("Stack Underflow \n");
    }
    else{
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

void peek(){
    if (top == NULL) {
        printf("Stack is Empty\n");
    }
    else{
        printf("Top Value : %d\n", top->data);
    }
}

void print() {
    if (top == NULL) {
        printf("Empty Stack\n");
    }
    else {
        struct Node *temp = top;

        printf("Stack:\n");
        printf("--------\n");

        while (temp != NULL) {
            printf("|  %d  |\n", temp->data);
            printf("--------\n");
            temp = temp->next;
        }

        printf("   TOP\n");
    }
}

int main() {

    int choice, value;

    do {
        printf("1 : Push \n");
        printf("2 : Pop \n");
        printf("3 : Peek \n");
        printf("4 : Print \n");
        printf("5 : Exit \n");

        printf("\n");
        printf("Enter you choice: ");
        scanf("%d",&choice);
        printf("\n");

    switch(choice){

        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            print();
            break;
        case 5:
            printf("Exiting...");
            break;
        }

    }while(choice != 5);

    
    return 0;
}