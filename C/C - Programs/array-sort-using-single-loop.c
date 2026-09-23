#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements in the array: ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int no_of_zero = 0;
    int no_of_one = 0;
    int no_of_two = 0;
    int no_of_three = 0;
    int no_of_four = 0;
    int no_of_five = 0;
    int no_of_six = 0;
    int no_of_seven = 0;
    int no_of_eight = 0;
    int no_of_nine = 0;

    printf("\n");

    // Counting the number of 0s, 1s, 2s, 3s, 4s, 5s, 6s, 7s, 8s and 9s in the array
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            no_of_zero++;
        }
        else if (a[i] == 1)
        {
            no_of_one++;
        }
        else if (a[i] == 2)
        {
            no_of_two++;
        }
        else if (a[i] == 3)
        {
            no_of_three++;
        }
        else if (a[i] == 4)
        {
            no_of_four++;
        }
        else if (a[i] == 5)
        {
            no_of_five++;
        }
        else if (a[i] == 6)
        {
            no_of_six++;
        }
        else if (a[i] == 7)
        {
            no_of_seven++;
        }
        else if (a[i] == 8)
        {
            no_of_eight++;
        }
        else if (a[i] == 9)
        {
            no_of_nine++;
        }
    }

    printf("\n");
    printf("Number of 0s: %d\n", no_of_zero);
    printf("Number of 1s: %d\n", no_of_one);
    printf("Number of 2s: %d\n", no_of_two);
    printf("Number of 3s: %d\n", no_of_three);
    printf("Number of 4s: %d\n", no_of_four);
    printf("Number of 5s: %d\n", no_of_five);
    printf("Number of 6s: %d\n", no_of_six);
    printf("Number of 7s: %d\n", no_of_seven);
    printf("Number of 8s: %d\n", no_of_eight);
    printf("Number of 9s: %d\n", no_of_nine);

    // int k = 0;
    for (int i = 0; i < no_of_zero; i++)
        a[i] = 0;
    for (int i = no_of_zero; i < no_of_zero + no_of_one; i++)
        a[i] = 1;
    for (int i = no_of_zero + no_of_one; i < no_of_zero + no_of_one + no_of_two; i++)
        a[i] = 2;
    for (int i = no_of_zero + no_of_one + no_of_two; i < no_of_zero + no_of_one + no_of_two + no_of_three; i++)
        a[i] = 3;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three; i < n; i++)
        a[i] = 4;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three + no_of_four; i < n; i++)
        a[i] = 5;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three + no_of_four + no_of_five; i < n; i++)
        a[i] = 6;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three + no_of_four + no_of_five + no_of_six; i < n; i++)
        a[i] = 7;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three + no_of_four + no_of_five + no_of_six + no_of_seven; i < n; i++)
        a[i] = 8;
    for (int i = no_of_zero + no_of_one + no_of_two + no_of_three + no_of_four + no_of_five + no_of_six + no_of_seven + no_of_eight; i < n; i++)
        a[i] = 9;

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
