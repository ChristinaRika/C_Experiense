 #include<stdio.h>
int main()
{
	int a,c,d,e;
	float b;
	printf("Enter item number: ");
	scanf("%d",&a);
	printf("Enter unit price: ");
	scanf("%f",&b);
	printf("Enter purchase date(mm/dd/yyyy): ");
	scanf("%d/%d/%d",&c,&d,&e);
	printf(" Item\t\tUnit\t\t\tPurchase\n");
	printf("    \t\tPrice\t\t\tDate\n");
	printf(" %-d\t\t$%7.2f\t\t\n",a,b);
	printf(" %d/%d/%-d\n",c,d,e);
	return 0;
}
