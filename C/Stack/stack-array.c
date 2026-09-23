#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stk[MAX];
int top = -1;


void push(int value){
    if (top == MAX-1){
        printf("Stack Overflow! \n");
        return;
    }
    top++;
    stk[top] = value;
}

void pop(){
    if (top == -1){
        printf("Stack Underflow \n");
    }
    else{
        printf("Element deleted: %d \n", stk[top]);
        top--;
    }
}

void peek(){
    if (top == -1) {
        printf("Stack is Empty\n");
    }
    else{
        printf("Top Value : %d\n", stk[top]);
    }
}

void print() {
    if (top == -1) {
        printf("Empty Stack\n");
    }
    else {
        printf("Stack:\n");
        printf("--------\n");

        for (int i = top; i >= 0; i--) {
            printf("|  %d  |\n", stk[i]);
            printf("--------\n");
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