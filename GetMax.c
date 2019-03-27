#include<stdio.h>
int main(){
    float scores[10];
    int i;
    printf("Enter scores: ");
    for(i=0;i<10;i++)
    scanf("%f",&scores[i]);
    float max=scores[0];
    for(i=1;i<10;i++)
    if(scores[i]>max)
    max=scores[i];
    printf("Max: %f\n",max);
    return 0;
}