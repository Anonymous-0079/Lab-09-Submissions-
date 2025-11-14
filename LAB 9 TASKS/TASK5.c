#include <stdio.h>

int dataAttendance(int (*attendance)[5], int students, int days) {
    int defaulters = 0;
    int i, j;
    for (i = 0; i < students; i++) {
        int totalP = 0;
        for (j = 0; j < days; j++) {
            totalP += *(*(attendance + i) + j);
        }
        float percentage = ((float)totalP / days) * 100;
        printf("Student %d: Attendance is %.1f%% - ", i + 1, percentage);
        if (percentage >= 90) {
            printf("Good\n");
        } else if (percentage >= 75) {
            printf("Average\n");
        } else {
            printf("Poor\n");
            defaulters += 1;
        }
    }
    return defaulters;
}

int main() {
    int att[30][5];
    int i, j;
    printf("Enter attendance (1 for present, 0 for absent) for 30 students over 5 days:\n");
    for (i = 0; i < 30; i++) {
        printf("\nStudent %d\n", i + 1);
        for (j = 0; j < 5; j++) {
            int val;
            while (1) {
                printf("Day %d: ", j + 1);
                scanf("%d", &val);
                if (val == 0 || val == 1) {
                    *(*(att + i) + j) = val;  
                    break;
                } else {
                    printf("Invalid! Please enter 0 or 1.\n");
                }
            }
        }
    }

    int totalDef = dataAttendance(att, 30, 5);
    printf("\nTotal number of defaulters: %d\n", totalDef);

    return 0;
}
