#include<stdio.h>
int main()
{
	int a,b,c,d,a1,a2,a3,b1,b2,b3;
	printf("Enter four integers: ");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a1 = a>b?a:b;
	a2 = a1>c?a1:c;
	a3 = a2>d?a2:d;
	b1 = a<b?a:b;
	b2 = b1<c?b1:c;
	b3 = b2<d?b2:d;
	printf("Largest: %d \n",a3);
	printf("Smallest: %d \n",b3);
	return 0;
}
