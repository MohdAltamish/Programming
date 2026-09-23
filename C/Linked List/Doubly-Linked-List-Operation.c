#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create New Node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insertBeg(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    newNode->next = head;
    last->next = newNode;
    head = newNode;
}

// Insert at End
void insertEnd(int value) {
    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    last->next = newNode;
    newNode->next = head;
}

// Insert at Position
void insertPos(int value, int pos) {

    if (pos <= 0) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertBeg(value);
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (pos > 2 && temp->next == head && pos - 1 > 1) {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from Beginning
void deleteBeg() {

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    struct Node *temp = head;

    head = head->next;
    last->next = head;

    free(temp);
}

// Delete from End
void deleteEnd() {

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    free(temp->next);
    temp->next = head;
}

// Delete at Position
void deletePos(int pos) {

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        printf("Invalid Position\n");
        return;
    }

    struct Node *del = temp->next;

    temp->next = del->next;

    free(del);
}

// Display
void display() {

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;

    printf("HEAD -> ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}

// Search
void search(int value) {

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;

    do {

        if (temp->data == value) {
            printf("Element Found at Position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    printf("Element Not Found\n");
}

// Count Nodes
void count() {

    if (head == NULL) {
        printf("Total Nodes = 0\n");
        return;
    }

    struct Node *temp = head;
    int c = 0;

    do {
        c++;
        temp = temp->next;
    } while (temp != head);

    printf("Total Nodes = %d\n", c);
}

int main() {

    int choice, value, pos;

    do {

        printf("\n===== Circular Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;

            case 2:
                printf("Enter Value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter Value and Position: ");
                scanf("%d%d", &value, &pos);
                insertPos(value, pos);
                break;

            case 4:
                deleteBeg();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Enter Value to Search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 9:
                count();
                break;

            case 10:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 10);

    return 0;
}