//random walk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned)time(NULL));
	char square[10][10];
	int a[10][10]={0},i,j,m;

	for(i=0;i<=9;i++)
	{ 
	  j=0;
	  for(;j<=9;j++)
	  square[i][j]='.';
	} 
	i=0;j=0;                              //first square 
	
    square[i][j]='A';
    a[i][j]=1;
    
    while(square[i][j]<'Z'){
    	
    	if(i-1>=0&&a[i-1][j]==1&&i+1<=9&&a[i+1][j]==1&&j-1>=0&&a[i][j-1]==1&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1<0&&i+1<=9&&a[i+1][j]==1&&j-1>=0&&a[i][j-1]==1&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1>=0&&a[i-1][j]==1&&i+1>9&&j-1>=0&&a[i][j-1]==1&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1>=0&&a[i-1][j]==1&&i+1<=9&&a[i+1][j]==1&&j-1<0&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1>=0&&a[i-1][j]==1&&i+1<=9&&a[i+1][j]==1&&j-1>=0&&a[i][j-1]==1&&j+1>9)
    	break;
    	if(i-1<0&&i+1<=9&&a[i+1][j]==1&&j-1<0&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1<0&&i+1<=9&&a[i+1][j]==1&&j-1>=0&&a[i][j-1]==1&&j+1>9)
    	break;
    	if(i-1>=0&&a[i-1][j]==1&&i+1>9&&j-1<0&&j+1<=9&&a[i][j+1]==1)
    	break;
    	if(i-1>=0&&a[i-1][j]==1&&i+1>9&&j-1>=0&&a[i][j-1]==1&&j+1>9)
    	break;
    	
    	switch(rand()%4){
	    	case 0:
	    	if(i-1>=0&&a[i-1][j]==0)
	    	{i-=1;
	    	square[i][j]=square[i+1][j]+1;
	    	a[i][j]=1;}
	    	break;
	    	
	    	case 1:
	    	if(i+1<=9&&a[i+1][j]==0)
	    	{i+=1;
	    	square[i][j]=square[i-1][j]+1;
	    	a[i][j]=1;}
	    	break;
	    	
	    	case 2:
	    	if(j-1>=0&&a[i][j-1]==0)
	    	{j-=1;
	    	square[i][j]=square[i][j+1]+1;
	    	a[i][j]=1;}
	    	break;
	    	
	    	case 3:
    		if(j+1<=9&&a[i][j+1]==0)
	    	{j+=1;
	    	square[i][j]=square[i][j-1]+1;
	    	a[i][j]=1;}
	    	break;
	    }
    }
    
	for(i=0;i<=9;i++)                    //��ӡrandom walk 
	{ 
	  j=0;
	  for(j=0;j<=9;j++)
	  printf("%c",square[i][j]);
	  printf("\n");
	} 
	return 0;
}
