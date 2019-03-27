#include<stdio.h>
int main()
{
	int i=1,j=1,n;
	char a;
	printf("This program is a table of squaers.\n");
	printf("Enter number of entries in table: ");
	scanf("%d",&n);
	while(i<=n){
		printf("%10d%10d\n",i,i*i);
		i++;
		j++;
		if(j==25)
		{
			printf("Press Enter to continue...\n");
			a=getchar();
			while(a!='\n');
			j=1;
		}
	} 
	return 0;
}
