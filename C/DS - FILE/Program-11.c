// Write a C program to implement Sequential search and Binary search.

#include <stdio.h>

// SEQUENTIAL (LINEAR) SEARCH
int sequential_search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// BINARY SEARCH (array must be sorted in ascending order)
int binary_search(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// MAIN MENU
int main()
{
    int arr[50], n, i, ch, key, pos;
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    printf("========== SEQUENTIAL SEARCH AND BINARY SEARCH ==========\n");
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in ascending order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1)
    {
        printf("\n1. Sequential Search\n2. Binary Search\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 3)
            break;
        if (ch != 1 && ch != 2)
        {
            printf("Invalid choice\n");
            continue;
        }
        printf("Enter element to search: ");
        scanf("%d", &key);
        if (ch == 1)
            pos = sequential_search(arr, n, key);
        else
            pos = binary_search(arr, n, key);

        if (pos == -1)
            printf("Element %d not found\n", key);
        else
            printf("Element %d found at position %d\n", key, pos + 1);
    }
    printf("\nNAME: ALTAMISH \nROLL NO: 2501920100077\n");
    return 0;
}