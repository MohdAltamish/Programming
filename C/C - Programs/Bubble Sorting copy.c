#include <stdio.h>

int main()
{
    int arr[5] = {5, 2, 8, 1, 9};
    int temp;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array:\n");

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}