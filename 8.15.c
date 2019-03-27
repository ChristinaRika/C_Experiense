#include<stdio.h>
int main()
{
	char sentence[80];
	int i=0,j=0,m;
	printf("Enter message to be encrypted: ");
	do{
		sentence[j]=getchar();
		i++;
	}while(sentence[j++]!='\n');
	j=0;
	printf("Enter shift amount (1-25): ");
	scanf("%d",&m);
	while(j<i){
		if(sentence[j]>='a'&&sentence[j]<='z')
		sentence[j]=(sentence[j]-'a'+m)%26+'a';
		j++;
	}
	j=0;
	while(j<i){
		if(sentence[j]>='A'&&sentence[j]<='Z')
		sentence[j]=(sentence[j]-'A'+m)%26+'A';
		j++;
	}
	printf("Encrypted message: ");
	for(j=0;j<i;j++)
	printf("%c",sentence[j]);
	return 0;

}
