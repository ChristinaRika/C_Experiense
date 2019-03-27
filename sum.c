/*conmand argument*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int a=0,i;
    for(i=1;i<argc;i++)
    a+=atoi(argv[i]);
    printf("Total: %d\n",a);
    system("pause");
    return 0;
}