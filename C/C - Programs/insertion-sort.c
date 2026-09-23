#include<stdio.h> 

void sort(int arr[5]){

    int i, j, n = 5, key;

    for ( i = 1; i < n; i++)
    {
        j = i -1;
        key = arr[i];
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

    

int main(){

    int a[5] = {5,2,9,8,3};
    sort(a);

    printf("Sorted array:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}

