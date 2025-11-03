#include <stdio.h>

int main() {
    float matrix[3][3];
    float transpose[3][3];
    float cofactor[3][3];
    float adjoint[3][3];
    float inverse[3][3];
    float determinant = 0;

    int i, j, k;

  
    printf("Enter elements of a 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

 
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%8.3f ", matrix[i][j]);
        printf("\n");
}
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("\nTranspose of Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%8.3f ", transpose[i][j]);
        printf("\n");
    }

    
    determinant = 0;
    for (i = 0; i < 3; i++) {
        determinant += matrix[0][i] * 
            (matrix[1][(i+1)%3] * matrix[2][(i+2)%3] - 
             matrix[1][(i+2)%3] * matrix[2][(i+1)%3]);
    }

    printf("\nDeterminant = %.3f\n", determinant)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int x1 = (i+1)%3, x2 = (i+2)%3;
            int y1 = (j+1)%3, y2 = (j+2)%3;
            cofactor[i][j] = (matrix[x1][y1]*matrix[x2][y2] - matrix[x1][y2]*matrix[x2][y1]) * (((i+j)%2==0)? 1 : -1);
        }
    }

    printf("\nCofactor Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%8.3f ", cofactor[i][j]);
        printf("\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adjoint[i][j] = cofactor[j][i];
        }
    }

    printf("\nAdjoint of Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%8.3f ", adjoint[i][j]);
        printf("\n");
    }

    if (determinant == 0) {
        printf("\nInverse does not exist (Determinant = 0)\n");
    } else {
        printf("\nInverse of Matrix:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inverse[i][j] = adjoint[i][j] / determinant;
                printf("%8.3f ", inverse[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

