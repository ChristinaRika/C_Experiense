#include<stdio.h>
int main()
{
	int a1,b1,c1,a2,b2,c2;
	printf("Enter a date(mm/dd/yy): ");
	scanf("%d/%d/%d",&a1,&b1,&c1);
	a2=a1;b2=b1;c2=c1;
	while(1) 
	{
	printf("Enter a date(mm/dd/yy): ");
	scanf("%d/%d/%d",&a1,&b1,&c1);
	if(a1==0&&b1==0&&c1==0)
	break;
	if(c1<c2)
	{a2=a1;b2=b1;c2=c1;}
    if(c1==c2&&a1<a2)
	{a2=a1;b2=b1;c2=c1;}
    if(c1==c2&&a1==a2&&b1<b2)
	{a2=a1;b2=b1;c2=c1;}
	}
	printf("%d/%d/%.2d is the earlist date\n",a2,b2,c2);
	return 0;	
}
