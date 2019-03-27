#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>                              /*use isspase();*/
#define LEN 20
int read_line(char str[],int n);
void insert(void);
void search(void);
void update(void);
void print(void);
void quit(void);
int find_number(int );
struct part{
	int number;
	char name[LEN];
	int on_hand;
} inventory[100];

int num_parts=0;

int main(){
	char code;
	for(;;)
	{printf("Enter operation code(q:quit  i:insert  s:search  u:update  p:print): ");
	scanf(" %c",&code);
	while(getchar()!='\n');                         /*to read without former '\n'*/
	switch(code){
		case 'q':quit();break;
		case 'i':insert();break;
		case 's':search();break;
		case 'u':update();break;
		case 'p':print();break;
		default :printf("Code error!\n");break;
	}}                                             /*I want to use system("cls");*/
	return 0;
}

void insert(){
	int m;
	if(num_parts==100)
	{printf("Database is full,can't add more parts.\n");return;}
	printf("Enter part number: ");
	scanf(" %d",&m);
	if(find_number(m)>=0)
	{printf("Part already exits.\n");return;}
	inventory[num_parts].number=m;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name,LEN);
	printf("Enter quantity on hand: ");
	scanf(" %d",&inventory[num_parts].on_hand);
	num_parts++;
	return;
}

void update(){
	int i,j,change;
	printf("Enter part number: ");
	scanf(" %d",&i);
	j=find_number(i);
	if(j<0)
	{printf("Part can't be found.\n");return;}
	printf("Enter change in quantity on hand: ");
	scanf(" %d",&change);
	inventory[j].on_hand+=change;
	return;
}

void print(){
	int i;
	printf("Part Numer\tPart Name\t\tQuantity on Hand\n");
	for(i=0;i<num_parts;i++)
	printf("%7d            %-20s%11d\n",inventory[i].number,
	inventory[i].name,inventory[i].on_hand);
	return;
}

void search(){
	int n,i;
	printf("Enter part number: ");
	scanf(" %d",&n);
	i=find_number(n);
	if(i<0)
	{printf("Part not found.\n");return;}
	printf("Part name: %s\n",inventory[i].name);
	printf("Quantity on hand: %d\n",inventory[i].on_hand);
	return;
}

void quit(){
	exit(EXIT_SUCCESS);
}

int find_number(int s){
	int num;
	for(num=0;num<=100;num++)
	if(inventory[num].number==s)
	return num;
	return -1;
} 

int read_line(char str[],int n){
	int ch,i=0;
	while(isspace(ch=getchar()));               /*escape the space of the head or the tail space of last time.*/
	while(ch!='\n'&&ch!=EOF){
		if(i<n)
		str[i++]=ch;
		ch=getchar();
	}
	str[i]='\0';
	return i;
}
