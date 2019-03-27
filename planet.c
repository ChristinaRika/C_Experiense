/*Open in cmd!!!*/
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
    char *planet[]={"Mercury","Venus","Earth",
    "Mars","Jupiter","Saturn","Uranus","Neptune","Pluto"};
    int i,j;
    for(i=1;i<argc;i++){
    for(j=0;j<9;j++){
        if(strcmp(argv[i],planet[j])==0)   
        break;
    }
    if(j==9)
    printf("%s is not a planet.\n",argv[i]);
    else
    printf("%s is planet %d.\n",argv[i],j+1);
    }
    return 0;
}