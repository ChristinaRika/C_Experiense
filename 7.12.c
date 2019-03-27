#include<stdio.h>
int main()
{
	float a,b;
	char c='a';
	int i=1;
	printf("Enter an expression: ");
	while(c!='\n'){
		switch(i){
			case 1:
			scanf("%f",&a);i++;
			break;
			case 2:
			scanf("%c",&c);i++;
			break;
			case 3:
			scanf("%f",&b);i=2;
			switch(c){
				case '+':a+=b;break;
				case '-':a-=b;break;
				case '*':a*=b;break;
				case '/':a/=b;break;
			}
			break;
		}
	}

	printf("Value of expression: %g\n",a);
	return 0;
}
