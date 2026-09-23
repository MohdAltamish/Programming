#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4};
    int *ptr;
    int a;
    int n = sizeof arr / sizeof arr[0];

    printf("Enter the position to know the address: ");
    if (scanf("%d", &a) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (a < 0 || a >= n)
    {
        printf("Position is out of range.\n");
        return 1;
    }

    ptr = &arr[a];
    printf("The size of the array is: %d\n", n);
    printf("The address is: %p\n", (void *)ptr);

    return 0;
}