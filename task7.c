#include <stdio.h>

int main() {
    int arr[10];
    int i, num, count = 0;

 
    printf("Enter 10 numbers: ");
    for(i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

 
    printf("Enter the number to search: ");
    scanf("%d", &num);

   
    for(i = 0; i < 10; i++) {
        if(arr[i] == num)
            count++;
    }

    
    if(count > 0)
        printf("Number %d occurs %d time%s.\n", num, count, count > 1 ? "s" : "");
    else
        printf("Number not found.\n");

    return 0;
}
