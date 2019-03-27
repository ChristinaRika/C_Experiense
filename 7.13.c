//the average length of word
#include<stdio.h>
int main()
{
	char a='a';
	float n=1,m=0;
	printf("Enter a sentence: ");
	while(a!='\n'){
		a=getchar();
		if(a==' ')
		n++;
		else if(a!='\n')
		m++;
	}
	printf("Average word length: %.1f",m/n);
	return 0;
}
