//seriously
//24 hour to 12 hour
#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&a,&b);
	printf("Equivalent 12-hour time: ");
	if(a==0)
	{printf("12:%.2d AM\n",b);
	return 0;}
	if(a==12)
	{printf("%d:%.2d PM\n",a,b);
	return 0;}
	switch(a<=11)
	{
		case 1:printf("%d:%.2d AM\n",a,b);
		break;
		default:printf("%d:%.2d PM\n",a-12,b);
		break;
	}
	done:
	return 0;
} 
