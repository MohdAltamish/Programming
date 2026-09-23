#include<stdio.h>
#include<stdlib.h>


int main(){
    int n = 5, i;
    int *ptr;
    int sum;

    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
        }
        
    printf("Elements Sum are:\n");
    for(i = 0; i < n; i++) {
        sum += ptr[i];
    }
    printf("%d ",sum);
    free(ptr);
    return 0;
}