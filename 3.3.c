//ISBN
#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d",&a,&b,&c,&d,&e);
	printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\n",a,b,c);
	printf("Item number: %d\nCheck digit: %d\n",d,e);
	return 0;
} 
