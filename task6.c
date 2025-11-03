#include <stdio.h>

int main() {
    int arr[5];
    int i, last;

    
    printf("Enter 5 integers: ");
    for(i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

   
    last = arr[4];

   
    for(i = 4; i > 0; i--)
        arr[i] = arr[i-1];

  
    arr[0] = last;

   
    printf("Array after right shift: ");
    for(i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
