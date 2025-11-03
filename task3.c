#include <stdio.h>

int main() {
    int A[3][3], B[3][3], C[3][3];
    int r1, c1, r2, c2;
    int i, j, k;
    printf("Enter rows and columns of Matrix A (max 3x3): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B (max 3x3): ");
    scanf("%d %d", &r2, &c2);

    
    if (c1 != r2) {
        printf("\nMatrix multiplication not possible!\n");
        printf("Columns of A (%d) must equal rows of B (%d).\n", c1, r2);
        return 0;
    }

    
    printf("\nEnter elements of Matrix A (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    
    printf("\nEnter elements of Matrix B (%dx%d):\n", r2, c2);
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            C[i][j] = 0;

    
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    printf("\nMatrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%5d ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%5d ", B[i][j]);
        printf("\n");
    }

    
    printf("\nResultant Matrix (A × B):\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%5d ", C[i][j]);
        printf("\n");
    }

    return 0;
}

