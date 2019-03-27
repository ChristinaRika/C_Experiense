#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter numerical grade: ");
	scanf("%d",&a);
	if(a>100||a<0)
	printf("Error, grade must be between 0 and 100.\n");
	else
	b=a/10;
	switch(b)
	{
	case 9:case 10:printf("Letter Grade: A\n");
	break;
	case 8:printf("Letter Grade: B\n");
	break;
	case 7:printf("Letter Grade: C\n");
	break;
	case 6:printf("Letter Grade: D\n");
	break;
	case 5:case 4:case 3:case 2:case 1:case 0:printf("Letter Grade: F\n");
	break;
	}
	return 0;
} 
