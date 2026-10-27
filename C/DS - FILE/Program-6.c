/*
    Program to add two polynomials using arrays.
    The user is prompted to enter the degree and coefficients of two polynomials,
    and the program calculates and displays their sum.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void addPolynomials()
{
    int p1[MAX] = {0}, p2[MAX] = {0}, sum[MAX] = {0};
    int d1, d2, maxDegree;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &d1);

    printf("Enter coefficients from x^0 to x^%d:\n", d1);
    for (int i = 0; i <= d1; i++)
        scanf("%d", &p1[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &d2);

    printf("Enter coefficients from x^0 to x^%d:\n", d2);
    for (int i = 0; i <= d2; i++)
        scanf("%d", &p2[i]);

    maxDegree = (d1 > d2) ? d1 : d2;

    for (int i = 0; i <= maxDegree; i++)
        sum[i] = p1[i] + p2[i];

    printf("\nSum of Polynomials:\n");

    for (int i = maxDegree; i >= 0; i--)
    {
        if (sum[i] != 0)
        {
            if (i == 0)
                printf("%d", sum[i]);
            else if (i == 1)
                printf("%dx", sum[i]);
            else
                printf("%dx^%d", sum[i], i);

            if (i > 0)
                printf(" + ");
        }
    }

    printf("\n");
}

int main()
{
    int choice;

    printf("NAME: ALTAMISH \nROLL NO: 2501920100077\n");

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Add Two Polynomials\n");
        printf("2. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addPolynomials();
                break;

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 2);

    return 0;
}