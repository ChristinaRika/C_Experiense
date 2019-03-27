#include<stdio.h>
#include<string.h>
int main(){
	char smallest_word[21],largest_word[21];
	char instant[21],ssr[21];
	printf("Enter word: ");
	scanf(" %s",smallest_word);
	printf("Enter word: ");
	scanf(" %s",largest_word);	
	if(strcmp(smallest_word,largest_word)>0)
	{strcpy(instant,largest_word);
	strcpy(largest_word,smallest_word);
	strcpy(smallest_word,instant);}
	
	while(strlen(smallest_word)!=4&&strlen(largest_word)!=4){
	printf("Enter word: ");
	scanf(" %s",ssr);
	if(strcmp(ssr,smallest_word)<0)
	strcpy(smallest_word,ssr);
	if(strcmp(ssr,largest_word)>0)
	strcpy(largest_word,ssr);
	if(strlen(ssr)==4)
	break;
	}
	printf("\nSmallest word: %s\n",smallest_word);
	printf("Largest word: %s\n",largest_word);
	return 0;
}

