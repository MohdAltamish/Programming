#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[10], index[10];
    int n,i,j,key,block,start,end;

    j = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for (i = 0; i<n; i+=3){
        index[j] = i;
        j++;
    }
    printf("Enter the key to be searched: ");
    scanf("%d",&key);

    block = -1;
    for(i=0;i<j;i++){
        if (key >= a[index[i]]){
            block = i;
        }
    }
    if (block == -1){
        printf("Element not found\n");
        return 0;
    }

    start = index[block];
    if (block + 1 < j)
        end = index[block + 1] - 1;
    else
        end = n - 1;
    for (i = start; i <= end; i++){
        if (a[i] == key){
            printf("Element found at index %d\n", i);
            return 0;
        }
    }
    printf("Element not found\n");
    return 0;
}
