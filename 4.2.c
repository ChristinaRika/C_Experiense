#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	printf("Enter a three-digit number: ");
	scanf("%d",&a);
	b = a/100;
	c = (a-b*100)/10;
	d = a%10;
	e = 100*d+10*c+b;
	printf("The reversal is: %d \n",e);
	return 0;
} 
