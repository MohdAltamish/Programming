#include <stdio.h>

int main()
{
    int a[10];
    // int n;
    // printf("Enter the size of the array: ");
    // scanf("%d", &n);

    printf("Enter 10 elements: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    // sorting the array in ascending order
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}