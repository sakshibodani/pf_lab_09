#include <stdio.h>

int main() {
    int matrix[3][3][3]; 
    int i, j, k, identical;
    
    
    printf("Enter elements of 3x3x3 matrix (layer by layer):\n");
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i+1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }

    
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i+1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++)
                printf("%5d", matrix[i][j][k]);
            printf("\n");
        }
    
    printf("\nLayer Comparisons:\n");

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) { 
            identical = 1; 
            for (k = 0; k < 3 && identical; k++) {
                for (int l = 0; l < 3 && identical; l++) {
                    if (matrix[i][k][l] != matrix[j][k][l])
                        identical = 0;
                }
            }

            if (identical)
                printf("Layer %d and Layer %d are IDENTICAL.\n", i+1, j+1);
            else
                printf("Layer %d and Layer %d are DISTINCT.\n", i+1, j+1);
        }
    }

    return 0;
}
