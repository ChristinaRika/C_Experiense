#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("Enter a two-digit number: ");
	scanf("%d",&a);
	b = a/10;
	c = a%10;
	d = 10*c+b;
	printf("The reversal is: %d\n",d);
	return 0;
} 
