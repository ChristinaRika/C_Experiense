//class of tax
#include<stdio.h>
int main()
{
	float value;
	printf("Enter your value: ");
	scanf("%f",&value);
	printf("Your tax is ");
	if (value<=750)
	printf("%.2f \n",value*0.01);
	else if (value<=2250)
	printf("%.2f \n",7.50+0.02*(value-750));
	else if (value<=3750)
	printf("%.2f \n",37.50+0.03*(value-2250));
	else if (value<=5250)
	printf("%.2f \n",82.50+0.04*(value-3750));
	else if (value<=7000)
	printf("%.2f \n",142.50+0.05*(value-5250));
	else
	printf("%.2f \n",230.00+0.06*(value-7000));
	return 0;
}
