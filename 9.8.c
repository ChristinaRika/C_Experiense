#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int roll_dice(void);
bool play_game(void);

int main(){
    char code;
    int win_already,win=0,lose=0;
    srand((unsigned) time(NULL));
    for(;;){
    win_already=play_game();

    if(win_already)
    win++;
    else
    lose++; 

    printf("Play again?\n");
    code=getchar();
    if(code=='n'||code=='N')
    break;
    }
    printf("wins: %d    Losses: %d",win,lose);
    return 0;
}

int roll_dice(void){
    int a,b=0,flag=1;
    while((a=rand()%6)!=0&&flag<=2)
    {b+=a;
    flag++;}
    return b;
}

bool play_game(void){
    int point,t;
    point=roll_dice();
    printf("You rolled: %d\n",point);
    if(point==7||point==11)
    {printf("You win!\n");
    return true;}
    else if(point==2||point==3||point==12)
    {printf("You lose!\n");
    return false;}
    else
    {printf("Your point is %d\n",point);
    while((t=roll_dice()!=point)){
        printf("You rolled: %d\n",t);
        if(point==2||point==3||point==12)
        {printf("You lose!\n");
        return false;}
    }
    printf("You rolled: %d\n",t);
    printf("You win!\n");
    return true;}
}