#include<stdio.h>
int main()
{
	int m,n,a;
	printf("Enter two integers: ");
	scanf("%d %d",&m,&n);
	while(n!=0)
	{
		a=n;
	    n=m%n;
	    m=a;
	}
	printf("Greatest common divisor: %d\n",m);
	return 0;
}
