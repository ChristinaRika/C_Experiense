#include<stdio.h>
int main()
{
	int a[10]={0},y[10]={0};
	long int n;
	int i,j,b;
	printf("Enter a number: ");
	scanf("%ld",&n);
	printf("Digit:\t\t");
	for(i=0;i<=8;i++)
	printf("%-3d",i);
	printf("%d",i);
	printf("\nOccurrences:\t");
	if(n==0)
	y[0]=1;
	while(n>0){
		b=n%10,n/=10;
		a[b]=1;
		if(a[b]==1)
		y[b]++;
	}
	for(i=0;i<=8;i++)
	printf("%-3d",y[i]);
	printf("%d",y[i]);
	printf("\n");
	return 0;
} 
