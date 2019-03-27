#include<stdio.h>
void quick_sort(int *low,int *high);
int *split(int *low,int *high);
int main(){
	int n,i;
	printf("Enter number of digits to be sorted: ");
	scanf("%d",&n);
	int numbers[n];                                     //C99
	printf("Enter digits to be sorted: ");
	for(i=0;i<n;i++)
	scanf("%d",&numbers[i]);
	quick_sort(&numbers[0],&numbers[i-1]);
	printf("Sorted number: ");
	for(i=0;i<n;i++)
	printf("%d ",numbers[i]);
	printf("\n");
	return 0;
}

void quick_sort(int *low,int *high){
	int *middle;
	if(low>=high)
	return;
	middle=split(low,high);
	quick_sort(low,middle-1);
	quick_sort(middle+1,high);
}

int *split(int *low,int *high){
	int part_number=*low;
	for(;;){	
		while(low<high&&part_number<=*high)            //be careful!!!notice the order
			high--;
			if(low>=high)
			break;
            *low++=*high;
            
            while(low<high&&*low<=part_number)
			low++;
		    if(low>=high)
			break;
			*high--=*low;
	}
	*high=part_number;
	return high;
}
