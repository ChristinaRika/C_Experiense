#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool CheckMatch(char pre,char cur);
struct stack{
    char symbol[100];
    int top;
}SymbolStack;
void Push(char);
char Pop(void);
bool Empty(void);
int main(){
    char a;
    bool match = true;
    printf("Enter expression: ");
    while((a=getchar())!='\n'){
        if(a == '(' || a == '{' || a == '[')
        Push(a);
        if(a == ')' || a == '}' || a == ']')
        match = CheckMatch(Pop(),a);
    }
    if(match&&Empty())
    printf("Match.\n");
    else
    {
        printf("Dismatch.\n");
    }
    return 0;
}
char Pop(void){
    if(Empty()){
        printf("Dismatch.\n");      //underflow
        exit(EXIT_FAILURE);
    }
    return SymbolStack.symbol[--(SymbolStack.top)];
}
void Push(char c){
    if(SymbolStack.top==100){
        printf("Dismatch.\n");      //overflow
        exit(EXIT_FAILURE);
    }
    SymbolStack.symbol[(SymbolStack.top)++] = c;
}
bool Empty(void){
    return SymbolStack.top==0;
}
bool CheckMatch(char pre,char cur){
    if (pre == '(' && cur != ')')
                return false;
    if (pre == '{' && cur != '}')
                return false;
    if (pre == '[' && cur != ']')
                return false;
}