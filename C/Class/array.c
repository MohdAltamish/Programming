#include<stdio.h>

int arr[10], n, value;

void insert(int value){
    for (int i = n; i > 0; i--){
        arr[i] = arr[i - 1];
    }arr[0] = value;
    n++;
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

    printf("Enter the elements you want to insert: ");
    scanf("%d", &value);

    insert(value);

    printf("The array elements are: ");
    print();

}