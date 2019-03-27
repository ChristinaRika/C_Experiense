#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M 8
#define N 8
#define MAX_SIZE (M+2)*(N+2)

/*This is a maze,which users can edit this.
to change the size of maze,just go to the 
head and then change the value of 'M' and 'N'
at #define area*/
int maze[M+2][N+2]={
  {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
  {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
  {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
  {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
  {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};
//Operation

typedef struct{
    int i,j;
    int pre;
} Box;
typedef struct{
    Box data[MAX_SIZE];
    int front,rear;
} Maze;

void InitQueue(Maze **);
void Destroy(Maze *);
bool QueueEmpty(Maze *);
bool QueueFull(Maze *);
bool enQueue(Maze *,Box e);
Box deQueue(Maze *);
void Print(Maze *,int);
bool MazePath(int,int,int,int);

void InitQueue(Maze **q)
{
  (*q)=(Maze *)malloc(sizeof(Maze));
  (*q)->front=(*q)->rear=-1;
}
void Destroy(Maze *q)
{
  free(q);
}
bool QueueEmpty(Maze *q)
{
  return q->front == q->rear;
}
bool QueueFull(Maze *q)
{
  return q->rear==MAX_SIZE-1;
}
bool enQueue(Maze *q,Box e)
{
  if(QueueFull(q)){
    printf("Quence full!\n");
    return false;
  }
  q->data[++(q->rear)]=e;
  return true;
}
Box deQueue(Maze *q)
{
  if(QueueEmpty(q)){
    printf("Quence empty!\n");
    exit(0);
  }
  return q->data[++(q->front)];
}
void Print(Maze *q,int front)      //print the path
{
  int k=front,j,ns=0;
  printf("\n");
  do{
    j=k;
    k=q->data[k].pre;     //back to get
    q->data[j].pre=-1;    //mark the got element 
  }while(k!=0);
  printf("A path: \n");
  for(k=0;k<MAX_SIZE;k++)
  {
    if(q->data[k].pre==-1)
    {
      ns++;
      printf("\t(%d,%d)",q->data[k].i,q->data[k].j);
      if(ns%5==0)
      printf("\n");
    }
  }
  printf("\n");
}
bool MazePath(int xi,int yi,int xe,int ye)      //(xi,yi)——>(xe,ye)
{
  Box e;
  int i,j,di,i1,j1;
  Maze *q;
  InitQueue(&q);
  e.i=xi;e.j=yi;e.pre=-1;
  enQueue(q,e);
  maze[xi][yi]=-1;
  while(!QueueEmpty(q))
  {
    e=deQueue(q);
    i=e.i;j=e.j;
    if(i==xe&&j==ye)        //find the path
    {
      Print(q,q->front);    //print the path
      Destroy(q);
      return true;
    }
    for(di=0;di<4;di++)     //search the way beside the current cube
    {
            switch (di)                  //different direction
            {
                case 0:i1=i-1;j1=j;break;
                case 1:i1=i;j1=j+1;break;
                case 2:i1=i+1;j1=j;break;
                case 3:i1=i;j1=j-1;break;
            }
            if(maze[i1][j1]==0)
            {
              e.i=i1;e.j=j1;
              e.pre=q->front;
              enQueue(q,e);
              maze[i1][j1]=-1;          //mark the got element
            }
    }
  }
  Destroy(q);
  return false;                        //fail to find the path
}
int main()
{
  if(!MazePath(1,1,M,N))
    printf("No path!\n");
  return 0;
}