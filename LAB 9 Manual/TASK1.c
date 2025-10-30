#include<stdio.h>

float CalcBill(float units)
	{
	float bill;
	
	if (units <= 100){
		bill = units * 10;
	}else {
		bill = (15 * (units - 100)) + (10 * 100);
		}
		
	 return bill;
	}
	
int main(){
	float consumption[10], TotalRev = 0, *ptr;
	int i;
	
	for (i = 0; i < 10; i++){
		printf("Units Consumed by house %d in Kwh:", i+1);
		scanf("%f", &consumption[i]);
	}
	
	ptr = consumption;
	
	float bill = 0;
	for (i = 0; i <10; i++){
		bill = CalcBill(*(ptr + i));
		printf("House %d consumed %.2f kWh: Total Amount is PKR. %.2f\n", i+1, *(ptr + i), bill);
		TotalRev += bill;
	}
	
	printf("Totaln Revenue collected is: PKR %.2f\n", TotalRev);
	
return 0;
}
