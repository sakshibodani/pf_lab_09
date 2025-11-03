#include <stdio.h>

int main() {
    int total_students = 10;
    int marks[10];
    int pass_marks[10], fail_marks[10];
    int pass_count = 0, fail_count = 0;
    int i;
    float pass_avg = 0.0, fail_avg = 0.0;

    printf("Enter marks for 10 students (enter -1 to exit):\n");

    for(i = 0; i < total_students; i++) {
        printf("Student %d: ", i+1);
        scanf("%d", &marks[i]);

        if(marks[i] == -1) {
            printf("Exiting input...\n");
            break;
        }

        if(marks[i] >= 5 && marks[i] <= 10) {
            pass_marks[pass_count++] = marks[i];
            pass_avg += marks[i];
        } 
        else if(marks[i] >= 0 && marks[i] < 5) {
            fail_marks[fail_count++] = marks[i];
            fail_avg += marks[i];
        } 
        else {
            printf("Invalid mark! Please enter marks between 0-10.\n");
            i--;
        }
    }

   
    printf("\nPassed Students Marks:\n");
    if(pass_count == 0)
        printf("No passed students.\n");
    else {
        for(i = 0; i < pass_count; i++)
            printf("%d ", pass_marks[i]);
        pass_avg /= pass_count;
        printf("\nAverage of passed students: %.2f\n", pass_avg);
    }

   
    printf("\nFailed Students Marks:\n");
    if(fail_count == 0)
        printf("No failed students.\n");
    else {
        for(i = 0; i < fail_count; i++)
            printf("%d ", fail_marks[i]);
        fail_avg /= fail_count;
        printf("\nAverage of failed students: %.2f\n", fail_avg);
    }

    return 0;
}
