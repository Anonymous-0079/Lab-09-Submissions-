#include <stdio.h>

float calcTotal(float *prices, int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        if (*(prices + i) < 1000)
            *(prices + i) *= 0.90;  
        else if (*(prices + i) <= 5000)
            *(prices + i) *= 0.85;  
        else
            *(prices + i) *= 0.75;   

        total += *(prices + i);
    }
    return total;
}

int main() {
    float prices[5];
    float totalAmount;

    printf("Enter prices of 5 products:\n");
    for (int i = 0; i < 5; i++) {
        printf("Product %d price: Rs. ", i + 1);
        scanf("%f", &prices[i]);
    }

    totalAmount = calcTotal(prices, 5);

    float *ptr = &totalAmount;
    printf("\nTotal amount after discounts: Rs. %.2f\n", *ptr);

    return 0;
}

