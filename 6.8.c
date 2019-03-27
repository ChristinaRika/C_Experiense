#include<stdio.h>
int main()
{
	int i,j,k,m,n;
	printf("Enter number of days in month: ");
	scanf("%d",&i);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d",&j);
    for(m=1;m<j;m++)
    printf("   ");
	n=1;
    printf("%2d",n);
    j++;
    for(n=2;n<=i;printf("%2d",n),n++,j++)
	if(j>7)
   {
    printf("\n");
    j=1;
   }
   else
   printf(" ");
   if(i<n)
   printf("\n"); 
	return 0;
}
