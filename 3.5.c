//4*4array
#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	int f,g,h,i,j;
	int k,l,m,n,o;
	int p,a1,a2,a3;
	int a4,b1,b2,b3,b4;
	int c1,c2;
	printf("Enter the numbers from 1 to 16 in any order: ");
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p);
	a1 = a+b+c+d;a2 = e+f+g+h;a3 = i+j+k+l;a4 = m+n+o+p;
	b1 = a+e+i+m;b2 = b+f+g+h;b3 = c+g+k+o;b4 = d+h+l+p;
	c1 = a+f+k+p;c2 = d+g+j+m;
	printf("Row sums: %d %d %d %d\n",a1,a2,a3,a4);
	printf("Column sums: %d %d %d %d\n",b1,b2,b3,b4);
	printf("Diagonal sums: %d %d\n",c1,c2);
	return 0;
}
