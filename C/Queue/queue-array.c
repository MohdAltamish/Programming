#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    int value = queue[front];
    printf("Element deleted: %d\n", value);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is Empty\n");
    }
    else {
        printf("Front Value: %d\n", queue[front]);
    }
}

// void print() {
//     if (front == -1) {
//         printf("Empty Queue\n");
//     }
//     else {
//         for (int i = front; i <= rear; i++) {
//             printf("%d, ", queue[i]);
//         }
//         printf("\n");
//     }
// }

void print() {
    if (front == -1) {
        printf("Empty Queue\n");
    }
    else {
        printf("Queue:\n");

        for (int i = front; i <= rear; i++) {
            printf("+-----+");
        }
        printf("\n");

        for (int i = front; i <= rear; i++) {
            printf("| %3d |", queue[i]);
        }
        printf("\n");

        for (int i = front; i <= rear; i++) {
            printf("+-----+");
        }
        printf("\n");

        printf("  FRONT");
        for (int i = front; i < rear; i++) {
            printf("      ");
        }
        printf("  REAR\n");
    }
}

int main() {

    int choice, value;

    do {
        printf("1 : Enqueue \n");
    printf("2 : Dequeue \n");
    printf("3 : Peek \n");
    printf("4 : Print \n");
    printf("5 : Exit \n");

    printf("\n");

    scanf("%d",&choice);

    switch(choice){

        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
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