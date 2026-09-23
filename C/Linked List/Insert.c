#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node *head, int val){
    struct Node *newNode = createNode(val);
    if (head == NULL){
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void print(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *head = NULL;
    int n, val;
    printf("How many nodes ?\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("Enter the value: \n");
        scanf("%d", &val);
        head = insertNode(head, val);
    }
    print(head);
    return 0;
}

