//tax added
#include<stdio.h>
int main()
{
float X,Y;
printf("Enter an amount: ");
scanf("%f",&X);
Y = X*1.05;
printf("With tax added: $%.2f\n",Y);
return 0;
}
