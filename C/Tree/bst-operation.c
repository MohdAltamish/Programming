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

// Traversal
void inorder(struct Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Insertion
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

// Searching
struct Node* search (struct Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if (key < root->data){
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Minimum Value
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

// Deletion
struct Node* deletion (struct Node* root, int key){
    if(root == NULL){
        return root;
    }
    if (key < root->data){
        root->left = deletion(root->left, key);
    }
    else if (key > root->data){
        root->right = deletion(root->right, key);
    }
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    struct Node* temp = minValueNode(root->right);  
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}


// Menu
int main(){
    struct Node* root = NULL;
    int choice, value;

    while(1) {
        printf("\n--- BST MENU ---");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Search Element");
        printf("\n4. Display Inorder");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;
                
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    root = deletion(root, value);
                    printf("%d deleted successfully.\n", value);
                } else {
                    printf("Element not found in the tree.\n");
                }
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) printf("Element %d found!\n", value);
                else printf("Element %d not found.\n", value);
                break;
                
            case 4:
                printf("BST Inorder Sorted Traversal: ");
                inorder(root);
                printf("\n");
                break;
                
            case 5:
                printf("Exiting application...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}