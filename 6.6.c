#include<stdio.h>
int main()
{
	int n,a;
	printf("Enter a number: ");
	scanf("%d",&n);
    for(a=2;a*a<=n;printf("%d\n",a*a),a+=2);
	return 0;
}
