#include <stdio.h>
#include <stdlib.h>

void multiplyMatrix()
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
        r1 > 10 || c1 > 10 || r2 > 10 || c2 > 10)
    {
        printf("Invalid matrix size! Maximum size is 10 x 10.\n");
        return;
    }

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible!\n");
        return;
    }

    printf("Enter elements of first matrix:\n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    /* Initialize result matrix */
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
        }
    }

    /* Matrix multiplication */
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d\t", c[i][j]);
        }

        printf("\n");
    }
}

void diffDiagonal()
{
    int arr[10][10];
    int n;
    int primaryDiagonal = 0;
    int secondaryDiagonal = 0;

    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    if (n > 10 || n <= 0)
    {
        printf("Invalid matrix size!\n");
        return;
    }

    printf("Enter elements of matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        primaryDiagonal += arr[i][i];
        secondaryDiagonal += arr[i][n - i - 1];
    }

    printf("\nMain Diagonal Sum = %d", primaryDiagonal);
    printf("\nSecondary Diagonal Sum = %d", secondaryDiagonal);
    printf("\nDifference = %d\n",primaryDiagonal - secondaryDiagonal);
}

int main()
{
    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");
    int choice;

    do
    {
        printf("\n\n----- MENU -----\n");
        printf("1. Matrix Multiplication\n");
        printf("2. Difference of Diagonals\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                multiplyMatrix();
                break;

            case 2:
                diffDiagonal();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}





