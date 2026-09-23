#include<stdio.h>

int main(){
    int a[3][3], b[3][3], mul[3][3];
    int i, j, k;

    printf("Enter the elements of First (3 X 3) Matrix: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of Second (3 X 3) Matrix: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &b[i][j]);
        }
    }

    printf("Enter the elements of First (3 X 3) Matrix: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            mul[i][j] = 0;
            for (k = 0; k < 3; k++){
                mul[i][j] = a[i][k] * b[k][j];
            }
        }
    }

    printf("The required multiply of 3 X 3 matrix is: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d",mul[i][j]);
        }
        printf("\n ");
    }
}


