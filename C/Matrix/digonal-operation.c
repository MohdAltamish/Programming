#include<stdio.h>

int main(){
    int a[3][3], mainSum = 0, secSum = 0, diff;
    int i, j, k;

    // First Matrix:
    printf("Enter the elements of (3 X 3) Matrix: \n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // Main-Sum of Matrix digonal:
    for (i = 0; i < 3; i++){
        mainSum += a[i][i];
    }

    // Sec-Sum of Matrix digonal:
    for (i = 0; i < 3; i++){
        secSum += a[i][3 - i - 1];
    }

     // Difference of Matrix digonal:
    for (i = 0; i < 3; i++){
        diff = mainSum - secSum;
    }


    // Print the matrix
    printf("The required diagonal sum of 3 X 3 matrix is: \n");
    
        printf("%d\n",mainSum);

     // Print the matrix
    printf("The required diagonal difference of 3 X 3 matrix is: \n");
    
        printf("%d\n",diff);
}


