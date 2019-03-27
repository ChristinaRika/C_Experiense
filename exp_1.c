#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,two,three;
    int two_,three_;
    printf("Enter two digit(i<j):\n");
    printf("i: ");
    scanf("%d",&i);
    printf("j: ");
    scanf("%d",&j);
    two_=0;three_=0;
    for(two=i+1;two<j;two++)
    if(two%2==0)
    two_+=two;
    for(three=i+1;three<j;three++)
    if(three%3==0)
    three_+=three;
    printf("%d",two_-three);
    system("pause");
    return 0;
}