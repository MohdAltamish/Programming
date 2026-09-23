#include <stdio.h>
#include <stdlib.h>

void findInverse(float **matrix, int n) {
    float **inverse = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        inverse[i] = (float *)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0; // Initialize as Identity Matrix
        }
    }

    for (int i = 0; i < n; i++) {
        float pivot = matrix[i][i];
        if (pivot == 0) {
            printf("Matrix is singular and cannot be inverted.\n");
            return;
        }

        // Divide current row by pivot to make diagonal element 1
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Make other elements in the column 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j < n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }

    printf("\nInverse Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.3f\t", inverse[i][j]);
        }
        printf("\n");
        free(inverse[i]);
    }
    free(inverse);
}

int main() {
    int n;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    float **matrix = (float **)malloc(n * sizeof(float *));
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    findInverse(matrix, n);

    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
