//º∆À„e
#include<stdio.h>
int main()
{
	int n,m,y;
	double a,b=1.0,x=1.0;
	printf("Enter a number: ");
	scanf("%d",&n);
	m=n;
	y=n;
	while(y>=1){
	while(m>=1){
		x*=m;
		m--;
	}
	y--;
	m=y;
	a=1.0/x;
	x=1.0;
	b+=a;
	}
	printf("e is %lf\n",b);
	return 0;
}
	
