#include<stdio.h>

int arr[20], n, pos;
int a, b, c, d, choice;
char ch;

void insert_at_beg(int value){
    for(int i = n; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    n++;
}

void insert_at_end(int value){
    arr[n] = value;
    n++;
}

void place(int pos, int value){
    for(int i = n; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
}


void delete(int pos){
    for(int i = pos - 1; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n--;
}

void print(){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of an array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("The array elements are: ");
    print();



    do{
        printf("\n\nChoose the operation you want to perform:\n");
        printf("A - Insert at Beginning\n");
        printf("B - Insert at End\n");
        printf("C - Insert at any Position\n");
        printf("D - Delete at any Position\n");

        scanf(" %c", &ch);

        switch(ch){
            case 'A':
                printf("Enter the element to insert at beginning: ");
                scanf("%d", &a);
                insert_at_beg(a);
                print();
                break;

            case 'B':
                printf("Enter the element to insert at end: ");
                scanf("%d", &b);
                insert_at_end(b);
                print();
                break;

            case 'C':
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the element to insert at any position: ");
                scanf("%d", &c);
                place(pos, c);
                print();
                break;

            case 'D':
                printf("Enter the element to delete at any position: ");
                scanf("%d", &d);
                delete(d);
                print();
                break;  

            default:
                printf("Invalid Choice!");
        }

        printf("\nDo you want to continue: 1 - Yes, 2 - No: ");
        scanf("%d", &choice);

    }while(choice == 1);

    return 0;
}