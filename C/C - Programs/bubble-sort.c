#include<stdio.h> 

int main(){
    int i, j, temp, n = 5;
    int arr[n];

    for ( i = 0; i < n; i++)
    {
        printf("Enter elements");
        scanf("%d", &arr[i]);
    }

    for ( i = 0; i < n - i; i++)
    {
        for ( j = 0; j < n - i - 1; j++)        
        {
            if (arr[j] > arr[j + 1]){
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            }
        
        }
    }
    for ( i = 0; i < n; i++)
    {
        printf("Elements: %d \n", arr[i]);
    }
    
    return 0;
}