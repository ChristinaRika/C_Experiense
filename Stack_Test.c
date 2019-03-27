#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Second level pointer！！！！！！！！！！！
typedef struct{
    char data[100];
    int top;
} Stack;


void Push(Stack *p,char e);
char Pop(Stack *p);
bool Empty(Stack *p);
char Gettop(Stack *p);
bool Full(Stack *p);
bool InitStack(Stack **p);
void Destroy(Stack *p);

bool InitStack(Stack **p){
    *p=(Stack *)malloc(sizeof(Stack));
    (*p)->top=-1;
    if(p==NULL)
    return false;
    return true;
}
void Destroy(Stack *p){
    free(p);
}
void Push(Stack *p,char e){
    if(!Full(p))
    {p->top++;
    p->data[p->top]=e;
    return;}
    printf("Error!Stack full!\n");
    exit(0);
}
char Pop(Stack *p){
    if(!Empty(p))
    {char e= p->data[p->top];
    p->top--;
    return e;}
    printf("Error!Stack empty!\n");
    exit(0);
}
char Gettop(Stack *p){
    if(!Empty(p))
    return p->data[p->top];
    printf("Error!Stack empty!\n");
    return 'u';
}
bool Empty(Stack *p){
    return p->top==-1;
}
bool Full(Stack *p){
    return p->top==99;
}


int main(){
    Stack *p;
    InitStack(&p);
    printf("Enter elements: ");
    char e[100];
    scanf("%s",e);
    for(int i=0;e[i]!='\0';i++)
    Push(p,e[i]);
    while(!Empty(p)){
        printf("%c",Pop(p));
    }
    return 1;
}