#include<stdio.h>

void quicksort(int arr[], int low, int high){
    if (low >= high){
        return;
    }

    int pivot = arr[low];

    int i = low;
    int j = high;

    while(i < j){

        while (arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if (i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    quicksort(arr, low, j-1 );
    quicksort(arr, j+1, high );

}

int main(){

    int arr[] = {3, 5, 7, 2, 8, 1, 6, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n-1 );

    printf("Sorted Array is \n");

    for(int i = 0; i < n; i++){
        printf("%d ->", arr[i]);
    }
    return 0;
}

// QUICKSORT(arr, low, high)

//     if low >= high
//         return

//     pivot = arr[low]

//     i = low
//     j = high

//     while i < j

//         while arr[i] <= pivot
//             i++

//         while arr[j] > pivot
//             j--

//         if i < j
//             swap(arr[i], arr[j])

//     swap(arr[low], arr[j])

//     QUICKSORT(arr, low, j - 1)

//     QUICKSORT(arr, j + 1, high)