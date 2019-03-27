#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 20
int read_line(char a[],int n);
void insert(void);
void search(void);
void update(void);
void print(void);
void quit(void);
struct part *find_number(int );
struct part{
	int number;
	char name[LEN+1];
	int on_hand;
	struct part *next;
};
struct part *inventory=NULL;

int main(){
	char code;
	for(;;)
	{printf("Enter operation code(q:quit  i:insert  s:search  u:update  p:print): ");
	scanf(" %c",&code);
	while(getchar()!='\n');
	switch(code){
		case 'q':quit();break;
		case 'i':insert();break;
		case 's':search();break;
		case 'u':update();break;
		case 'p':print();break;
		default :printf("Code error!Please enter a right code!\n");break;
	}
	system("pause");}
	return 0;
}

void insert(){
	struct part *pre,*cur,*new_node;
	new_node = malloc(sizeof(struct part));
	if(new_node==NULL)
	{printf("Database is full,can't add more parts.\n");return;}
	
	printf("Enter part number: ");
	scanf("%d",&new_node->number);
	for(pre=NULL,cur=inventory;
	cur!=NULL&&new_node->number > cur->number;
	pre=cur,cur=cur->next);                       //find the part.
	if(cur!=NULL&&new_node->number==cur->number)
	{printf("Part already exits.\n");free(new_node);return;}//remember to clear the spase to be wasted
	
	printf("Enter part name: ");
	read_line(new_node->name,LEN);
	printf("Enter quantity on hand: ");
	scanf(" %d",&new_node->on_hand);
	
	new_node->next=cur;                          //make new_node link with cur
	if(pre==NULL)                                //it is the first node
	inventory=new_node;
	else
	pre->next=new_node;
	return;
}

void update(){
	int i,change;
	struct part *j;
	printf("Enter part number: ");
	scanf(" %d",&i);
	j=find_number(i);
	if(j==NULL)
	{printf("Part can't be found.\n");return;}
	printf("Enter change in quantity on hand: ");
	scanf(" %d",&change);
	j->on_hand+=change;
	return;
}

void print(){
	struct part *i;
	printf("Part Numer\tPart Name\t\tQuantity on Hand\n");
	for(i=inventory;i!=NULL;i=i->next)
	printf("%7d            %-20s%11d\n",i->number,
	i->name,i->on_hand);
	return;
}

void search(){
	int n;
	struct part *i;
	printf("Enter part number: ");
	scanf(" %d",&n);
	i=find_number(n);
	if(i==NULL)
	{printf("Part not found.\n");return;}
	printf("Part name: %s\n",i->name);
	printf("Quantity on hand: %d\n",i->on_hand);
	return;
}

void quit(){
	exit(EXIT_SUCCESS);
}
                            
struct part *find_number(int n){
	struct part *p;
	for(p = inventory;p != NULL&&p->number < n;p = p->next);
	if(p!=NULL&&n==p->number)
	return p;                                  //already find the number p.
	return NULL;	
} 

int read_line(char str[],int n){
	int ch,i=0;
	while(isspace(ch=getchar()));//escape the space of the head or the tail space of last time.
	while(ch!='\n'&&ch!=EOF){
		if(i<n)
		str[i++]=ch;
		ch=getchar();
	}
	str[i]='\0';
	return i;
}
