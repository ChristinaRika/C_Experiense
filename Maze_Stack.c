#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define M 8
#define N 8
#define MAX_SIZE 10*10
typedef struct{
    int i;//row
    int j;//col
    int di;//direction
} Box;
typedef struct{
    Box data[MAX_SIZE];
    int top;
} Maze;

void InitStack(Maze **);
void Push(Maze *,Box );
Box Pop(Maze *);
bool StackEmpty(Maze *);
void StackDestroy(Maze *);
Box Gettop(Maze *);
bool MazePath(int xi,int yi,int xe,int ye);//(xi,yi)-->(xe,ye)

void InitStack(Maze **maze){
    (*maze)=(Maze *)malloc(sizeof(Maze));
    (*maze)->top=-1;
}
void Push(Maze *maze,Box e){
    if(maze->top==MAX_SIZE){
        printf("Overflow!\n");
        exit(EXIT_FAILURE);
    }
    maze->data[++(maze->top)]=e;
}
Box Pop(Maze *maze){
    if(StackEmpty(maze)){
        printf("Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return maze->data[(maze->top)--];
}
bool StackEmpty(Maze *maze){
    return maze->top==-1;
}
Box Gettop(Maze *maze){
    if(StackEmpty(maze)){
        printf("Empty.\n");
        exit(0);
    }
    return maze->data[maze->top];
}
void StackDestroy(Maze *maze){
    free(maze);
}
/*This is a maze,which users can edit this.
to change the size of maze,just go to the 
head and then change the value of 'M' and 'N'*/
int mg[M+2][N+2]={
  {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
  {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
  {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
  {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
  {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
  //Operation
bool MazePath(int xi,int yi,int xe,int ye){
    Box path[MAX_SIZE],e;
    int i,j,di,i1,j1,k;
    bool find;
    Maze *st;
    InitStack(&st);                   //init the stack
    e.i=xi;e.j=yi;e.di=-1;
    Push(st,e);
    mg[xi][yi]=-1;
    while(!StackEmpty(st)){           
        e=Gettop(st);
        i=e.i;j=e.j;di=e.di;
        if(i==xe&&j==ye){                   //find the right path
            printf("A path: \n");
            k=0;
            while(!StackEmpty(st)){
                e=Pop(st);
                path[k++]=e;
            }
            while(k>=1){
                k--;
                printf("\t(%d,%d)",path[k].i,path[k].j);
                if((k+2)%5==0)
                printf("\n");
            }
            printf("\n");
            StackDestroy(st);
            return true;
        }
        find=false;
        while(di<4&&!find){              //search the way beside the current cube
            di++;
            switch (di)                  //different direction
            {
                case 0:i1=i-1;j1=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(mg[i1][j1]==0)
            find=true;
        }
        if(find){                        //there is a way
            st->data[st->top].di=di;
            e.i=i1;e.j=j1;e.di=-1;
            Push(st,e);
            mg[i1][j1]=-1;
        }
        else{                            //no way to go,then go back
            e=Pop(st);
            mg[e.i][e.j]=0;
        }
    }
    StackDestroy(st);
    return false;
}
int main(){
    if(!MazePath(1,1,M,N)){
        printf("No path!\n");
    }
    return 0;
}