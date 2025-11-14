#include <stdio.h>

void CalcNotes(int amount, int *denominations, int *count, int size) {
    for (int i = 0; i < size; i++) {
        *(count + i) = amount / *(denominations + i);   
        amount = amount % *(denominations + i);          
    }
}

int main() {
    int amount;
    int denominations[3] = {5000, 1000, 500};
    int count[3] = {0};
    int size = 3;

    printf("Enter the amount to withdraw: Rs. ");
    scanf("%d", &amount);

    if (amount % 50 != 0) {
        printf("Invalid amount! Please enter a multiple of Rs. 50.\n");
        return 0;
    }

    CalcNotes(amount, denominations, count, size);

    printf("\nCash Dispensed:\n");
    for (int i = 0; i < size; i++) {
        if (count[i] > 0)
            printf("Rs. %d x %d\n", denominations[i], count[i]);
    }

    return 0;
}
