#include<stdio.h>
int main()
{
	float a,b,c,d,e,f,rate,s;
	printf("Enter amount of loan: ");
	scanf("%f",&a);
	printf("Enter interest rate: ");
	scanf("%f",&b);
	printf("Enter monthly payment: \n");
	scanf("%f",&c);
	s = b/100.00;
	rate = s/12.00;
	d = a*(rate+1)-c;
	e = d*(rate+1)-c;
	f = e*(rate+1)-c;
	printf("Balance remaining after first payment: $%.2f\n",d);
	printf("Balance remaining after second payment: $%.2f\n",e);
	printf("Balance remaining after third payment: $%.2f\n",f);
	return 0;
} 
