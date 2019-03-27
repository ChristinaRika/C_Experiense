#include<stdio.h>
#include<ctype.h>
int main()
{
	int i=0;
	char a='a';
	printf("Enter a sentence: ");
	while(a!='\n'){
		a=getchar();
		a=tolower(a);
		if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
		i++;
	}
	printf("Your sentence contains %d vowels.\n",i);
	return 0;
}
