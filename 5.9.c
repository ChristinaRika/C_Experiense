//date comparing
#include<stdio.h>
int main()
{
	int a1,b1,c1,a2,b2,c2;
	printf("Enter first date(mm/dd/yy): ");
	scanf("%d/%d/%d",&a1,&b1,&c1);
	printf("Enter second date(mm/dd/yy): ");
	scanf("%d/%d/%d",&a2,&b2,&c2);
	if(c1>c2)
	printf(" %d/%d/%d is earlier than %d/%d/%d \n",a2,b2,c2,a1,b2,c1);
	else if(c1<c2)
	printf(" %d/%d/%d is earlier than %d/%d/%d \n",a1,b1,c1,a2,b2,c2);
	else
	{
		if(a1>a2)
		printf(" %d/%d/%d is earlier than %d/%d/%d \n",a2,b2,c2,a1,b2,c1);
		else if(a1<a2)
		printf(" %d/%d/%d is earlier than %d/%d/%d \n",a1,b1,c1,a2,b2,c2);
		else
		{
			if(b1>b2)
				printf(" %d/%d/%d is earlier than %d/%d/%d \n",a2,b2,c2,a1,b2,c1);
				else if(b1<b2)
				printf(" %d/%d/%d is earlier than %d/%d/%d \n",a1,b1,c1,a2,b2,c2);
				else
				printf(" %d/%d/%d is same as %d/%d/%d \n",a1,b1,c1,a2,b2,c2);
		}
		
	}
	return 0;	
}
