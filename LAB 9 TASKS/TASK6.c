#include <stdio.h>

void calcTotalValue(float *price, int *stock, float *total) {
    *total = (*price) * (*stock);
}
void Discount(float *total, int *stock) {
    if (*stock < 3) {
    } else if (*stock <= 5) {
        *total = *total - (*total * 0.10); 
    } else {
        *total = *total - (*total * 0.20); 

    }
}
int main() {
    float price[5], total[5];
    int stock[5];
    int i;
    void (*discountPtr)(float *, int *) = Discount;
    for (i = 0; i < 5; i++) {
        printf("\nEnter details of Book %d:\n", i + 1);
        printf("Price: ");
        scanf("%f", (price + i));
        printf("Number of copies in stock: ");
        scanf("%d", (stock + i));
        calcTotalValue((price + i), (stock + i), (total + i));
    }
    printf("Book\tPrice\tStock\tTotal\tAfter Discount\n");
    for (i = 0; i < 5; i++) {
        float discountedTotal = total[i];
        (*discountPtr)(&discountedTotal, (stock + i));
        printf("%d\t%.2f\t%d\t%.2f\t%.2f\n",i + 1, *(price + i), *(stock + i), *(total + i), discountedTotal);
    }
    return 0;
}
