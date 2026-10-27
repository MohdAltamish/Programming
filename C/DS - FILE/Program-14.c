// Write a C program to Implement of Heapsort.

#include <stdio.h>

// MAX HEAP: sift down element at index i (heap size n)
void heapify(int a[], int n, int i)
{
    int largest, left, right, t;
    while (1)
    {
        largest = i;
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;
        if (largest == i)
            break;
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        i = largest;
    }
}

void heap_sort(int a[], int n)
{
    int i, t;
    // build max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    // extract elements one by one
    for (i = n - 1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[50], n, i;
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    printf("========== HEAP SORT ==========\n");
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nBefore sorting: ");
    display(a, n);
    heap_sort(a, n);
    printf("After sorting : ");
    display(a, n);
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}