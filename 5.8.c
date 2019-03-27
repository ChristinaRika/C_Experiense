//air departure
#include<stdio.h>
 int main()
 {
 	int a,b,c;
 	printf("Enter a 24-houur time: ");
 	scanf("%d:%d",&a,&b);
 	printf("Closest departure time is ");
 	c=60*a+b;
 	if(c<522)
 	{
 		if(c>158)
 	printf("8:00 a.m.,arriving at 10:16 a.m.");//480
 	else 
	 printf("9:45 p.m.,arriving at 11:58 p.m.");
 	}
 	else if(c<641)
 	printf("9:43 a.m.,arriving at 11:52 a.m. \n");//583
 	else if(c<723)
 	printf("11:19 a.m.,arriving at 1:31 p.m. \n");//679
 	else if(c<804)
 	printf("12:47 p.m.,arriving at 3:00 p.m. \n");//767
 	else if(c<893)
 	printf("2:00 p.m.,arriving at 4:08 p.m. \n");//840
 	else if(c<1043)
 	printf("3:45 p.m.,arriving at 5:55 p.m. \n");//945
 	else if(c<1223)
 	printf("7:00 p.m.,arriving at 9:20 p.m. \n");//1140
 	else
 	printf("9:45 p.m.,arriving at 11:58 p.m. \n");//1305
 	return 0;
 }
 