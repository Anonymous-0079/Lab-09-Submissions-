#include <stdio.h>

void analyzeMileage(float (*mileage)[7], int vehicles, int days) {
    for (int i = 0; i < vehicles; i++) {
        float sum = 0.0;
        for (int j = 0; j < days; j++) {
            sum += *(*(mileage + i) + j);
        }
        float avg = sum / days;
        printf("Vehicle %d: Average Mileage = %.2f km/l", i + 1, avg);
        if (avg >= 18) {
            printf("Efficient\n");
        } else if (avg >= 12) {
            printf("Moderate\n");
        } else {
            printf("Poor\n");
        }
    }
}

int main() {
    float mileage[5][7];
    int vehicles = 5, days = 7;

    for (int i = 0; i < vehicles; i++) {
        printf("\nEnter mileage (km/l) for Vehicle %d over %d days:\n", i + 1, days);
        for (int j = 0; j < days; j++) {
            printf("Day %d: ", j + 1);
            scanf("%f", (*(mileage + i) + j)); 
        }
    }
    analyzeMileage(mileage, vehicles, days);

    return 0;
}
