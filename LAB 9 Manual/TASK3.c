#include <stdio.h>

float CalcAvg(float *marks) {
    float sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += *(marks + i);  
    }
    return sum / 3;
}

char determineGrade(float avg) {
    if (avg >= 85)
        return 'A';
    else if (avg >= 70)
        return 'B';
    else if (avg >= 55)
        return 'C';
    else if (avg >= 40)
        return 'D';
    else
        return 'F';
}

int findTopper(float avg[], int students) {
    int top = 0;
    int i;
    for ( i= 1; i < students; i++) {
        if (avg[i] > avg[top])
            top = i;
    }
    return top;
}

int main() {
    int i, j;
    float marks[5][3], avg[5];
    char grades[5];
   
    printf("Enter marks of 5 students in 3 subjects:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &marks[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        avg[i] = CalcAvg(marks[i]);
        grades[i] = determineGrade(avg[i]);
    }

    int (*ptrTop)(float[], int) = findTopper;
    int topIndex = ptrTop(avg, 5);

    for (i = 0; i < 5; i++) {
        printf("Student %d: Average: %.2f and Grade: %c\n", i + 1, avg[i], grades[i]);
    }

    printf("Topper: Student %d with Average %.2f and Grade %c\n",topIndex + 1, avg[topIndex], grades[topIndex]);

    return 0;
}




