#include<stdio.h>
#include<stdlib.h>


int main(){
    int n, i;
    int *ptr;

    n = 5;

    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
        }
        
    printf("Elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    n = 10;
    ptr = (int *)realloc(ptr, n * sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
        }
        
    printf("Updated Elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}