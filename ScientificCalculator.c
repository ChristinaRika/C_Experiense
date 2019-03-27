#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    char data[100];
    int top;
} OperStack;

typedef struct{
    double data[100];
    int top;
} CalStack;
void trans(char [],char []);
double Calculate(char *);

void Push(OperStack *,char );
char Pop(OperStack *);
bool StackEmpty(OperStack *);
char Gettop(OperStack *);
void InitStack(OperStack **);

void Push1(CalStack *,double );
double Pop1(CalStack *);
bool StackEmpty1(CalStack *);
double Gettop1(CalStack *);
void InitStack1(CalStack **);

//Stack operation begin
void Push(OperStack *Oper,char e){
    if(Oper->top==99){
        printf("Stack full.\n");
        exit(EXIT_FAILURE);
    }
    Oper->top++;
    Oper->data[Oper->top]=e;
}
char Pop(OperStack *Oper){
    if(!StackEmpty(Oper)){
        char e=Oper->data[Oper->top];
        (Oper->top)--;
        return e;
    }
    printf("Stack overflow.\n");
    exit(EXIT_FAILURE);
}
bool StackEmpty(OperStack *Oper){
    return (Oper->top)==-1;
}
char Gettop(OperStack *Oper){
    if(!StackEmpty(Oper))
    return Oper->data[Oper->top];
    printf("Empty Oper\n");
    exit(EXIT_FAILURE);//Empty
}
void InitStack(OperStack **Oper){
    *Oper=(OperStack *)malloc(sizeof(OperStack));
    (*Oper)->top=-1;
}

void Push1(CalStack *Cal,double e){
    if(Cal->top==99){
        printf("Stack full.\n");
        exit(EXIT_FAILURE);
    }
    (Cal->top)++;
    Cal->data[Cal->top]=e;
}
double Pop1(CalStack *Cal){
    if(!StackEmpty1(Cal)){
    double num=Cal->data[Cal->top];
    (Cal->top)--;
    return num;}
    printf("Stack overflow.\n");
    exit(EXIT_FAILURE);
}
bool StackEmpty1(CalStack *Cal){
    return Cal->top==0;
}
double Gettop1(CalStack *Cal){
    if(!StackEmpty1(Cal))
    return Cal->data[Cal->top];
    printf("Empty element.\n");
    exit(EXIT_FAILURE);//Empty
}
void InitStack1(CalStack **Cal){
    *Cal=(CalStack *)malloc(sizeof(CalStack));
    (*Cal)->top=0;
}
//Stack operation end

void trans(char *exp,char postexp[]){
    char e;
    int i=0;
    OperStack *Oper;
    InitStack(&Oper);
    while(*exp!='\0'){
        switch(*exp){
            case '(':{
                Push(Oper,*exp);//In stack
                exp++;//Continue scan
                break;
            }
            case ')':{
                e=Pop(Oper);
                while(e!='('){
                    postexp[i++]=e;
                    e=Pop(Oper);
                }
                exp++;//Continue scan
                break;
            }
            case '+':
            case '-':{
                while(!StackEmpty(Oper)){
                    e=Gettop(Oper);
                    if(e!='('){
                        postexp[i++]=e;
                        e=Pop(Oper);
                    }
                    else
                    break;
                }
                Push(Oper,*exp);
                exp++;
                break;      
            }
            case '*':
            case '/':{
                while(!StackEmpty(Oper)){
                    e=Gettop(Oper);
                    if(e=='*'||e=='/'){
                        postexp[i++]=e;
                        e=Pop(Oper);
                    }
                    else
                    break;
                }
                Push(Oper,*exp);
                exp++;
                break; 
            }
            default:{
                while(*exp>='0'&&*exp<='9'){
                    postexp[i++]=*exp;
                    exp++;
                }
                postexp[i++]='#';
            }
        }
    }
    while(!StackEmpty(Oper))
        postexp[i++]=Pop(Oper);
        postexp[i]='\0';
}

double Calculate(char *postexp){
    double a,b,c,d;
    CalStack *Cal;
    InitStack1(&Cal);
    while(*postexp!='\0'){
        switch(*postexp){
            case '+':{
                a=Pop1(Cal);
                b=Pop1(Cal);
                Push1(Cal,b+a);
                break;
            }
            case '-':{
                a=Pop1(Cal);
                b=Pop1(Cal);
                Push1(Cal,b-a);
                break;
            }
            case '*':{
                a=Pop1(Cal);
                b=Pop1(Cal);
                Push1(Cal,b*a);
                break;
            }
            case '/':{
                a=Pop1(Cal);
                b=Pop1(Cal);
                if(a!=0)
                Push1(Cal,b/a);
                else
                {
                    printf("Error!Try to div 0.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            }
            default:{
                c=0;
                while(*postexp>='0'&&*postexp<='9'){
                    c=10.0*c+(double)(*postexp-'0');
                    postexp++;
                }
                Push1(Cal,c);
                break;
            }
        }
        postexp++;//Continue scan
    }
    d=Gettop1(Cal);
    return d;
}

int main(){
    char exp[100];
    char postexp[100];
    printf("Enter expression: ");
    scanf("%s",exp);
    trans(exp,postexp);
    printf("Calculate result: %lf",Calculate(postexp));
    return 0;
}