#include<stdio.h> 

int main(){
    int i, n = 6, key, found = 0;
    int arr[n];

    printf("Enter elements");

    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter key elements");
    scanf("%d", &key);

    for (i = 0; i < n; i++){
        if (arr[i] == key) {
        printf("Elements Found");
        found = 1;
        }
    }

    return 0;
}