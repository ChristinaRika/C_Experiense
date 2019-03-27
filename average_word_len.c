/*average word len*/
#include<stdio.h>
#include<stdbool.h>
float average_word_len(char string[]);
int extract(char s1[],char s2[],int n);
bool check(char string);
int main(){
    char input[100],operate[100];
    float aver;
    gets(input);                  //to read a line.
    extract(input,operate,100);
    aver=average_word_len(operate);
    printf("average word len: %.2f\n",aver);
    return 0;
}
float average_word_len(char string[]){
    int i,j=1,k=0;
    for(i=0;string[i]!='\0';i++)
    if(string[i]==' ')
    j++,k++;
    return ((float)i-(float)k)/(float)j;
}
int extract(char s1[],char s2[],int n){
    int i,j;
    for(i=0,j=0;i<n&&s1[i]!='\0';i++)
    if(check(s1[i]))
    s2[j++]=s1[i];
    s2[j]='\0';
    return j;
}
bool check(char n){
    if(n>='A'&&n<='Z')
    return true;
    else if(n>='a'&&n<='z')
    return true;
    else if(n>='0'&&n<='9')
    return true;
    else if(n==' '||n=='-')
    return true;
    else
    return false;
}
