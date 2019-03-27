#include<stdio.h>
#include<ctype.h>
int main()
{
	int a,x=0;
	printf("Enter a word: ");
	char word='0';
	while(word!='\n'){
		word=getchar();
		word=toupper(word);
		switch(word){
			case 'A':case 'E':case 'I':case 'L':
			case 'N':case 'R':case 'S':case 'T':
			case 'U':case 'O':
			a=1;
			break;
			case 'D':case 'G':
			a=2;
			break;
			case 'B':case 'C':case 'M':case 'P':
			a=3;
			break;
			case 'F':case 'H':case 'V':case 'W':case 'Y':
			a=4;
			break;
			case 'K':
			a=5;
			break;
			case 'J':case 'X':
			a=8;
			break;
			case 'Q':case 'Z':
			a=10;
			break;
		}
		x+=a;
	}
	printf("Scrabble value: %d\n",x);
	return 0;
}
