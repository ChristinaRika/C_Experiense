#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct member {
	int id;         //student's id
	char name[20];  //student's name
	float score;      //student's score
	struct member *next;
}StdInfo;

void Insert(void);//insert one student's information
void Delete(void);//delete one student's information
void Change(void);//change one student's information
void Search(void);//search one student's information
void Sort_And_Print(void);//sort all students' information and print
void Print(struct member *ptr);//print one student's information
StdInfo *FindId(int id);
int ReadLine(char Str[], int Len);

StdInfo *first = NULL;            //head node

int main() {
	char code;
	for (;;) {
		printf("Enter operation code(q:quit  i:insert  s:search  c:change  p:print d:delete): ");
		scanf(" %c", &code);
		while (getchar() != '\n');
		switch (tolower(code)) {              //accept lower and upper letter
		case 'q':exit(EXIT_SUCCESS);
		case 'i':Insert(); break;
		case 's':Search(); break;
		case 'c':Change(); break;
		case 'p':Sort_And_Print(); break;
		case 'd':Delete();break;
		default:printf("Code error!Please enter a right code!\n"); break;
		}
		system("pause");
	}
	return 0;
}

void Print(struct member *ptr) {
	printf("Student ID: %d\nStudent Name: %s\nStudent Score: %.1f\n", ptr->id, ptr->name, ptr->score);
	return;
}

void Insert(void) {
	StdInfo *cur, *pre, *new_node;
	new_node = (StdInfo *)malloc(sizeof(StdInfo));
	if (new_node == NULL)                             //fail to allocate space
	{
		printf("Data is full,can't store student's information.\n");
		return;
	}
	printf("Enter student's id to insert: ");
	scanf("%d", &new_node->id);
	for (cur = first, pre = NULL;
		cur != NULL && cur->id!=new_node->id;
		pre = cur, cur = cur->next);
	if (cur != NULL && cur->id == new_node->id)              //check if student already exits
	{
		printf("Student already exits.\n");
		free(new_node);
		return;
	}
	printf("Enter student's name: ");
	ReadLine(new_node->name,20);
	printf("Enter student's score: ");
	scanf("%f", &new_node->score);
	new_node->next = cur;
	if (pre == NULL)                          //only an empty head
		first = new_node;
	else
		pre->next = new_node;
	printf("Insert successfully!\n");
	return;
}

void Change(void) {
	int id;
	StdInfo *ptr;
	char code;
	printf("Enter student's id to change: ");
	scanf("%d", &id);
	ptr = FindId(id);
	if (ptr == NULL)                //fail to find this student
	{
		printf("Fail to find this student.\n");
		return;
	}
	Print(ptr);
	printf("Sure to change(y/n)? \n");
	scanf(" %c", &code);
	if (tolower(code) == 'n')
		;
	else if (tolower(code) != 'y')
		printf("Code error!\n");
	else
	{
		printf("Enter student's new id: ");
		scanf("%d", &ptr->id);
		printf("Enter student's new name: ");
		ReadLine(ptr->name,20);
		printf("Enter student's new score: ");
		scanf("%f", &ptr->score);
		printf("Change information successfully!\n");
	}
	return;
}

StdInfo *FindId(int id) {
	StdInfo *ptr;
	for (ptr = first; ptr != NULL && ptr->id != id; ptr = ptr->next);//over searching all
	return ptr;
}

void Search(void) {
	int id;
	StdInfo *ptr;
	printf("Enter student's id to search: ");
	scanf("%d", &id);
	ptr = FindId(id);
	if (ptr == NULL)
	{
		printf("Fail to find this student.\n");             //fail to find this student
		return;
	}
	Print(ptr);                                             //print what be found
	return;
}

void Delete(void) {
	StdInfo *pre,*cur;
	int id;
	char code;
	printf("Enter student's id to delete: ");
	scanf("%d", &id);
	for (cur = first, pre = NULL; cur != NULL && cur->id != id; pre = cur, cur = cur->next);
	if (cur == NULL) {
		printf("Fail to find this student.\n");
		return;
	}                                      
	Print(cur);                              //find student's information,print it.
	printf("sure to delete?(Y/N)\n");
	scanf(" %c", &code);
	if (tolower(code) == 'n')
		;
	else if (tolower(code) != 'y')
		printf("Code error!\n");
	else
	{
		if(cur->next==NULL||pre==NULL)
			free(cur);
		else
		{
			pre->next = cur->next;
			free(cur);
		}
		printf("Delete information successfully!\n");
	}
	return;
}

void Sort_And_Print(void) {
	StdInfo *cur, *tail, *ptr;
	int flag;
	for (tail = first ; tail != NULL; tail = tail->next); //move tail to the end of linked list
	for (ptr = first; ptr->next != tail;) {                          //outer loop
		for (flag = 0, cur = first; cur->next != tail; cur = cur->next) {                //inner loop
			if (cur->score > cur->next->score)
			{
				int temp_id;
				float temp_score;
				char temp_name[20];
				temp_id = cur->id; temp_score = cur->score; strcpy(temp_name, cur->name);
				cur->id = cur->next->id; cur->score = cur->next->score; strcpy(cur->name, cur->next->name);
				cur->next->id = temp_id; cur->next->score = temp_score; strcpy(cur->next->name, temp_name);
				flag = 1;
			}
		}
		tail = cur;                                 //move tail ahead
		if (flag == 0)                               //already in order
			break;
	}
	for (ptr = first; ptr != NULL; ptr = ptr->next)
		Print(ptr);
	return;
}

int ReadLine(char str[], int n) {
	int ch, i = 0;
	while (isspace(ch = getchar()));//escape the space of the head or the tail space of last time.
	while (ch != '\n'&&ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}