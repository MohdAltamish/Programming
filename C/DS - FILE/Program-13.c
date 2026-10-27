/* Write a non-recursive C program to implement:
a) Bubble sort b) Selection sort c) Insertion sort d) Quick sort
e) Shell sort f) Radix sort g) Merge Sort */

#include <stdio.h>

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// a) BUBBLE SORT
void bubble_sort(int a[], int n)
{
    int i, j, t, swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

// b) SELECTION SORT
void selection_sort(int a[], int n)
{
    int i, j, min, t;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}

// c) INSERTION SORT
void insertion_sort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// d) QUICK SORT (non-recursive, using explicit stack)
int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j, t;
    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;
    return i + 1;
}

void quick_sort(int a[], int n)
{
    int stack[100], top = -1, low, high, p;
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        p = partition(a, low, high);

        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}

// e) SHELL SORT
void shell_sort(int a[], int n)
{
    int gap, i, j, t;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            t = a[i];
            for (j = i; j >= gap && a[j - gap] > t; j -= gap)
                a[j] = a[j - gap];
            a[j] = t;
        }
    }
}

// f) RADIX SORT (for non-negative integers)
void radix_sort(int a[], int n)
{
    int output[50], count[10], max = a[0], exp, i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            a[i] = output[i];
    }
}

// g) MERGE SORT (non-recursive, bottom-up)
void merge(int a[], int left, int mid, int right)
{
    int temp[50], i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[left + i] = temp[i];
}

void merge_sort(int a[], int n)
{
    int size, left, mid, right;
    for (size = 1; size < n; size *= 2)
    {
        for (left = 0; left < n - 1; left += 2 * size)
        {
            mid = left + size - 1;
            right = left + 2 * size - 1;
            if (mid >= n - 1)
                continue;
            if (right > n - 1)
                right = n - 1;
            merge(a, left, mid, right);
        }
    }
}

// MAIN MENU
int main()
{
    int a[50], b[50], n, i, ch;
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    printf("========== NON-RECURSIVE SORTING ALGORITHMS ==========\n");
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\n1.Bubble 2.Selection 3.Insertion 4.Quick 5.Shell 6.Radix 7.Merge 0.Exit\n");

    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 0)
            break;

        for (i = 0; i < n; i++)
            b[i] = a[i];

        printf("Before sorting: ");
        display(b, n);

        switch (ch)
        {
            case 1: bubble_sort(b, n); break;
            case 2: selection_sort(b, n); break;
            case 3: insertion_sort(b, n); break;
            case 4: quick_sort(b, n); break;
            case 5: shell_sort(b, n); break;
            case 6: radix_sort(b, n); break;
            case 7: merge_sort(b, n); break;
            default: printf("Invalid choice\n"); continue;
        }

        printf("After sorting : ");
        display(b, n);
    }

    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}