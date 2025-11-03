#include <stdio.h>
int main() {
int arr[3][3][3];
int i, j, k;
int layerSum, totalSum = 0;

int max = -9999, min = 9999;
float average;
int totalElements = 3 * 3 * 3;

printf("Enter elements for a 3x3x3 array (27 elements):\n");
for (i = 0; i &lt; 3; i++) {
printf("\n--- Enter elements for Layer %d ---\n”, i + 1");
for (j = 0; j &lt; 3; j++) {
for (k = 0; k &lt; 3; k++) {
printf("Element [%d][%d][%d]: ", i, j, k);
scanf("%d", &amp;arr[i][j][k]);
}
}
}

for (i = 0; i &lt; 3; i++) {
layerSum = 0;
printf("\nLayer %d:\n", i + 1);
for (j = 0; j &lt; 3; j++) {
for (k = 0; k &lt; 3; k++) {
printf("%d\t", arr[i][j][k]);
layerSum += arr[i][j][k];

if (arr[i][j][k] &gt; max)
Max = arr[i][j][k];
if (arr[i][j][k] &lt; min)
Min = arr[i][j][k];

}
printf("\n");
}
printf("Sum of Layer %d = %d\n", i + 1, layerSum);
totalSum += layerSum;
}

Average = (float)totalSum / totalElements;

printf("Total sum of all elements = %d\n", totalSum);
printf("Average of all elements = %.2f\n", average);
printf("Maximum element = %d\n", max);
printf("minimum element = %d\n", min);

return 0;
}
