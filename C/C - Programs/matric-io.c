#include<stdio.h>

int main()
{
    int arr[2][3], i, j;

    printf("Enter elements:\n");

    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Matrix is:\n");

    for(j=0;j<3;j++)
    {
        for(i=0;i<2;i++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}