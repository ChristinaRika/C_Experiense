//this is a program to object the stack to judge if the elements are matched.
//push:add an element and then top++.
//pop:decline an element and then top--.

#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

char contents[STACK_SIZE+1];
int top=0,match=1;

int is_empty(void),is_full(void);
void push(char i),make_empty(void),check(char i,char a);
char pop(void);
void stack_underflow(void),stack_overflow(void);

int is_empty(void)
{
	return top==0;
}

int is_full(void)
{
	return top>STACK_SIZE;
}

void stack_overflow(void)
{
	printf(" Stack overflow");
	exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
	match=0;
}

void push(char i)
{
	if(is_full())
	stack_overflow();
	else
	contents[top++]=i;
}

char pop(void)//PROBLEM
{
	if(is_empty())
	stack_underflow();
	else
	return contents[--top];
}

void check(char i,char a)
{
	if(a=='}'&&i!='{')
	match=0;
	if(a==')'&&i!='(')
	match=0;
}

int main()
{
	char a,i;
	printf("Enter parentheses and/or braces:");
	
	while((a=getchar())!='\n'){
	if(a=='('||a=='{')
	push(a);
	if(a==')'||a=='}')
	{i=pop();
	check(i,a);}
	}
	
	if(is_empty()&&match)
	printf(" Parentheses/braces are nested properly\n");
	else
	printf(" Parentheses/braces are NOT nested properly\n");
	return 0;
}
