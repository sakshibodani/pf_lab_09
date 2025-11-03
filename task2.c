#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, m;
    float A[5][5], B[5][5], I[5][5];
    int isSquare = 0, isZero = 1, isIdentity = 1, isDiagonal = 1, isScalar = 1;
    int isUpper = 1, isLower = 1, isSymmetric = 1, isSkewSymmetric = 1;
    int isRow = 0, isColumn = 0, isSingular = 0, isEqual = 1;
    int isIdempotent = 1, isNilpotent = 1;
    float det = 0;
    
    printf("Enter number of rows and columns (max 5): ");
    scanf("%d %d", &n, &m);

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%f", &A[i][j]);

    
    printf("\nMatrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%6.2f ", A[i][j]);
        printf("\n");
    }

    
    if (n == m) isSquare = 1;
    if (n == 1 && m > 1) isRow = 1;
    if (m == 1 && n > 1) isColumn = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (A[i][j] != 0)
                isZero = 0;
        }
    }

    if (isZero) {
        printf("\nThis is a Zero/Null Matrix.\n");
        return 0;
    }

    
    if (isSquare) {
        
        float diagonalValue = A[0][0];

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                
                if ((i == j && A[i][j] != 1) || (i != j && A[i][j] != 0))
                    isIdentity = 0;

                if (i != j && A[i][j] != 0)
                    isDiagonal = 0;

           
                if (i == j && A[i][j] != diagonalValue)
                    isScalar = 0;

           
                if (i > j && A[i][j] != 0)
                    isUpper = 0;

                if (i < j && A[i][j] != 0)
                    isLower = 0;

            
                if (A[i][j] != A[j][i])
                    isSymmetric = 0;

            
                if (A[i][j] != -A[j][i])
                    isSkewSymmetric = 0;
            }
        }

        if (n == 2)
            det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        else if (n == 3)
            det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
                - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
                + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);

        if (det == 0)
            isSingular = 1;

      
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                float sum = 0;
                for (int k = 0; k < n; k++)
                    sum += A[i][k] * A[k][j];
                I[i][j] = sum;
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (fabs(I[i][j] - A[i][j]) > 0.001)
                    isIdempotent = 0;
                if (fabs(I[i][j]) > 0.001)
                    isNilpotent = 0;
            }
        }
    }

    char choice;
    printf("\nDo you want to compare with another matrix? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int p, q;
        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &p, &q);
        printf("Enter elements of second matrix:\n");
        for (i = 0; i < p; i++)
            for (j = 0; j < q; j++)
                scanf("%f", &B[i][j]);

        if (n != p || m != q) isEqual = 0;
        else {
            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++)
                    if (A[i][j] != B[i][j])
                        isEqual = 0;
        }
    }

   
    printf("\nMatrix Type(s):\n");

    if (!isSquare) printf("- Rectangular Matrix\n");
    if (isSquare) printf("- Square Matrix\n");
    if (isIdentity) printf("- Identity Matrix\n");
    if (isDiagonal && !isIdentity) printf("- Diagonal Matrix\n");
    if (isScalar && !isIdentity) printf("- Scalar Matrix\n");
    if (isUpper) printf("- Upper Triangular Matrix\n");
    if (isLower) printf("- Lower Triangular Matrix\n");
    if (isSymmetric) printf("- Symmetric Matrix\n");
    if (isSkewSymmetric) printf("- Skew-Symmetric Matrix\n");
    if (isSingular) printf("- Singular Matrix\n");
    else if (isSquare) printf("- Non-Singular Matrix\n");
    if (isRow) printf("- Row Matrix\n");
    if (isColumn) printf("- Column Matrix\n");
    if (isIdempotent) printf("- Idempotent Matrix\n");
    if (isNilpotent) printf("- Nilpotent Matrix\n");
    if (isEqual) printf("- Equal Matrix (to the compared one)\n");

    return 0;
}
