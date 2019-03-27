#include<stdio.h>
#include<ctype.h>
int main()
{
	char number='2';
	printf("Enter phone number: ");
	while(number!='\n'){
		number=getchar();
		number=toupper(number);
		switch(number){
			case 'A':case 'B':case 'C':number='2';break;
			case 'D':case 'E':case 'F':number='3';break;
			case 'G':case 'H':case 'I':number='4';break;
			case 'J':case 'K':case 'L':number='5';break;
			case 'M':case 'N':case 'O':number='6';break;
			case 'P':case 'Q':case 'R':case 'S':number='7';break;
			case 'T':case 'U':case 'V':number='8';break;
			case 'W':case 'X':case 'Y':case 'Z':number='9';break;
			
		}
		printf("%c",number);
	}
	return 0;
}
