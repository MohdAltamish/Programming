/* Write a C program to create array and perform various operations:
a) Insertion at:  i) Beg	ii) End	iii) Any position
b) Deletion from:  i) Beg   ii) End	 iii) Any position       
c) Display the array
*/ 

#include <stdio.h>
#include <stdlib.h>

// Insert Function
void insert(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Print Function
void output(int arr[], int n)
{
    printf("Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("| %d | ", arr[i]);
    }

    printf("\n");
}

//Insert At Beginning
void insBeg(int arr[], int n)
{
    int element;

    printf("Enter the new element to add: ");
    scanf("%d", &element);

    for (int j = n - 1; j >= 0; j--)
    {
        arr[j + 1] = arr[j];
    }

    arr[0] = element;
}
//Insert At Position
int insPos(int arr[], int n)
{
    int element, pos;

    printf("Enter the new element: ");
    scanf("%d", &element);

    printf("Enter the position of new element: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position!\n");
        return 0;
    }

    int idx = pos - 1;

    for (int j = n - 1; j >= idx; j--)
    {
        arr[j + 1] = arr[j];
    }

    arr[idx] = element;
    return 1;
}

//Insert At End
void insEnd(int arr[], int n)
{
    int element;

    printf("Enter the new element to add: ");
    scanf("%d", &element);

    arr[n] = element;
}

//Delete from Beginning
void delBeg(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

void delEnd()
{
    /* Size is decremented in main */
}

//Delete from Position
int delPos(int arr[], int n)
{
    int pos;

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return 0;
    }

    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    int n;
    int arr[50];
    int choice;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    if (n < 0 || n > 49)
    {
        printf("Invalid array size!\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    insert(arr, n);

    do
    {
        printf("\n----- ARRAY -----\n");
        output(arr, n);

        printf("\n----- MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Display Array\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (n < 50)
            {
                insBeg(arr, n);
                n++;
                printf("Element inserted at beginning.\n");
                output(arr, n);
            }
            else
            {
                printf("Array is full!\n");
            }
            break;

        case 2:
            if (n < 50)
            {
                if (insPos(arr, n))
                {
                    n++;
                    printf("Element inserted at position.\n");
                    output(arr, n);
                }
            }
            else
            {
                printf("Array is full!\n");
            }
            break;

        case 3:
            if (n < 50)
            {
                insEnd(arr, n);
                n++;
                printf("Element inserted at end.\n");
                output(arr, n);
            }
            else
            {
                printf("Array is full!\n");
            }
            break;

        case 4:
            output(arr, n);
            break;

        case 5:
            if (n > 0)
            {
                delBeg(arr, n);
                n--;

                printf("Deleted the element from beginning.\n");
                output(arr, n);
            }
            else
            {
                printf("Array is empty!\n");
            }
            break;

        case 6:
            if (n > 0)
            {
                delEnd();
                n--;

                printf("Deleted the element from end.\n");
                output(arr, n);
            }
            else
            {
                printf("Array is empty!\n");
            }
            break;

        case 7:
            if (n > 0)
            {
                if (delPos(arr, n))
                {
                    n--;
                    printf("Deleted the element from position.\n");
                    output(arr, n);
                }
            }
            else
            {
                printf("Array is empty!\n");
            }
            break;

        case 8:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}