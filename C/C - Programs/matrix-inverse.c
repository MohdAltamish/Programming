#include <stdio.h>

#define N 3

// Function to find determinant of 2x2 matrix
float det2x2(float a[2][2]) {
    return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
}

// Function to get cofactor matrix
void getCofactor(float A[N][N], float temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Function to find determinant of matrix
float determinant(float A[N][N], int n) {
    float D = 0;

    if (n == 1)
        return A[0][0];

    float temp[N][N];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return D;
}

// Function to find adjoint
void adjoint(float A[N][N], float adj[N][N]) {
    if (N == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    float temp[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            getCofactor(A, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * determinant(temp, N - 1);
        }
    }
}

// Function to find inverse
int inverse(float A[N][N], float inv[N][N]) {
    float det = determinant(A, N);

    if (det == 0) {
        printf("Matrix is singular, can't find inverse\n");
        return 0;
    }

    float adj[N][N];
    adjoint(A, adj);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv[i][j] = adj[i][j] / det;

    return 1;
}

int main() {
    float A[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    float inv[N][N];

    if (inverse(A, inv)) {
        printf("Inverse Matrix:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                printf("%.2f ", inv[i][j]);
            printf("\n");
        }
    }

    return 0;
}