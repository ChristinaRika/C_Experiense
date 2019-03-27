//REVERSAL
#include<stdio.h>
int main()
{
	char sentence[100],*p,a;
	int i=0;
	printf("Enter a message: ");
	while((a=getchar())!='\n'&&i<100){
		sentence[i++]=a;
	}
	p=&sentence[i-1];
	printf("Reversal is: ");
    while(p>=sentence){
    printf("%c",*p--);
    }
    printf("\n");
	return 0;
}
