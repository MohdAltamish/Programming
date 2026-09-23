#include <stdio.h>

#define MAX 100

int lowStack[MAX], highStack[MAX];

int top = -1;

void push(int low, int high)

{

    top++;

    lowStack[top] = low;

    highStack[top] = high;
}

void pop(int *low, int *high)

{

    *low = lowStack[top];

    *high = highStack[top];

    top--;
}

int partition(int a[], int low, int high)

{

    int pivot, i, j, temp;

    pivot = a[low]; // first element as pivot

    i = low + 1;

    j = high;

    while (i <= j)

    {

        while (i <= high && a[i] <= pivot)

            i++;

        while (a[j] > pivot)

            j--;

        if (i < j)

        {

            temp = a[i];

            a[i] = a[j];

            a[j] = temp;
        }
    }

    // Put pivot in its correct position

    temp = a[low];

    a[low] = a[j];

    a[j] = temp;

    return j;
}

void quickSort(int a[], int n)

{

    int low, high, pivotPos;

    // Initially entire array

    push(0, n - 1);

    while (top != -1)

    {

        // Get low and high bounds

        pop(&low, &high);

        if (low < high)

        {

            pivotPos = partition(a, low, high);

            // Left subarray

            if (low < pivotPos - 1)

                push(low, pivotPos - 1);

            // Right subarray

            if (pivotPos + 1 < high)

                push(pivotPos + 1, high);
        }
    }
}

int main()

{

    int a[MAX], n, i;

    printf("Enter number of elements: ");

    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)

        scanf("%d", &a[i]);

    quickSort(a, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)

        printf("%d ", a[i]);

    return 0;
}
