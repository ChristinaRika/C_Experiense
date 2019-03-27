//dollor amount
#include<stdio.h>
int main()
{
int a,b,c,d,Z,y,x;
printf("Enter a dollar amount: \n");
scanf("%d",&Z);
a = Z/20;
x = Z%20;
b = x/10;
y = x%10;
c = y/5;
d = y%5;
printf("$20 bills: %d\n",a);
printf("$10 bills: %d\n",b);
printf(" $5 bills: %d\n",c);
printf(" $1 bills: %d\n",d);
return 0;
}
