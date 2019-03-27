//确定位数 
#include<stdio.h>
int main()
{
	int a;
	printf("Enter a number: \n");
	scanf("%d",&a);
	printf("The number %d has ",a);
	if(a<10)
	printf("1");
	else if(a<100)
	printf("2");
	else if(a<1000)
	printf("3");
	printf(" digits \n");
	return 0;
}

