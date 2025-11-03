#include <stdio.h>

int main() {
    int arr[10];
    int i, j;

    
    printf("Enter 10 integers: ");
    for(i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

   
    for(i = 0; i < 10; i++) {
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                arr[i] = -1; 
                break;       
            }
        }
    }

   
    printf("Updated array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
