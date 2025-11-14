#include <stdio.h>

void weatherAnalysis(float *rainfall, int size, float *avg, int *maxday) {
    float sum = 0.0, max = *rainfall;
    *maxday = 0;

    for (int i = 0; i < size; i++) {
        sum += *(rainfall + i);
        if (*(rainfall + i) > max) {
            max = *(rainfall + i);
            *maxday = i;
        }
    }
    *avg = sum / size;
}
int main() {
    float Rain[7], avg;
    int maxday, aboveAvg = 0;

    printf("Enter the rainfall data for 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &Rain[i]);
    }
    weatherAnalysis(Rain, 7, &avg, &maxday);

    for (int i = 0; i < 7; i++) {
        if (*(Rain + i) > avg) {
            aboveAvg += 1;
        }
    }

    printf("\nAverage Rainfall: %.2f mm\n", avg);
    printf("Maximum Rainfall: %.2f mm on Day %d\n", Rain[maxday], maxday + 1);

    if (aboveAvg > 3) {
        printf("Weather Summary: Rainy Week 🌧️\n");
    } else {
        printf("Weather Summary: Normal Week ☀️\n");
    }

    return 0;
}

