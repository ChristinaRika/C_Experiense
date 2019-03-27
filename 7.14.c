//square root calculating 
#include<stdio.h>
#include<math.h> 
int main()
{
	double y=1.0,x,i,j;
	printf("Enter a positive number: ");
	scanf("%lf",&x);
	while(1)
		{
		i=x/y,j=0.5*(y+i);
		if(fabs(y-j)>=1.0e-5)
		y=j;
		else
		break;
	}
	printf("Square root: %.5lf",y);
	return 0;
}
