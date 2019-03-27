#include<stdio.h>
int main()
{
	int a[10]={0},y[10]={10,10,10,10,10,10,10,10,10,10};
	long int n;
	int b,i=0;
	printf("Enter a number: ");
	scanf("%ld",&n);
	printf("Repeted digit(s):");
	while(n>0){
		b=n%10;
		n/=10;
		if(a[b]==1&&b!=y[b]){
			printf("%2d",b);
			i++;
			y[b]=b;
		}
		a[b]=1;	
	}
	if(i==0)
	printf("There are no repeted digits.\n");
	else
	printf("\n");
	return 0;
}
