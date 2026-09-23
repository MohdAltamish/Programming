#include<stdio.h> 

int main(){
    
    int i, n = 5, key;
    int arr[n];

    printf("Enter elements");

    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter key elements");
    scanf("%d", &key);

    int low = 0, high = n-1, mid, found;

    while(low <= high){
        mid = (low + high) / 2;
        if (arr[mid] == key){
            printf("Element Found");
            break;
            found = 1;
        }
        
        
        else if (arr[mid] < key){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    if (found == 0){
        printf("Element not found");
    }

    return 0;
}