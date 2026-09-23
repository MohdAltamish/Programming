#include<stdio.h>
#include<stdlib.h>


int main(){
    int n = 5, i;
    int *ptr;

    ptr = (int *)calloc(n, sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
        }
        
    printf("Elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
}