#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert (struct Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insert(root->left, value);
    }
    else if (value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}


struct Node* search (struct Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if (key < root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}


void inorder(struct Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBinary Search Tree in Sorted Order ");
    inorder(root);

    printf("\nEnter the element to seach: ");
    scanf("%d", &key);

    if (search(root,key) != NULL){
        printf("Element Found");
    }
    else{
        printf("Element not Found");
    }
    
    printf("\n");
    return 0;
}
