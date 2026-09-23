#include <stdio.h>

void sort(int a[], int n, int i)
{
    // Base case
    if (i == n - 1)
        return;

    // Find min index:
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[j] < a[min])
            min = j;
    }

    // Swap
    if (min != i)
    {
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    // Function call
    sort(a, n, i + 1);
}

int main()
{
    int a[10];
    printf("Enter 10 elements: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, 10, 0);

    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}