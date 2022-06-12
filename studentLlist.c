#include<stdio.h>

struct student {
	int no;
	char name[40];
	int age;
	struct student* next;
};
typedef struct student node;
node* head, * newNode;
node* createList()
{
	int n, k;
	node* head, * p;
	printf("How many students in the List\n");
	scanf("%d", &n);
	for (k = 0; k < n; k++)
	{
		if (k == 0)
		{
			head = (node*)malloc(sizeof(node));
			p = head;
		}
		else
		{
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
		}
		printf("Enter %d. student number :\n ", k + 1);
		scanf("%d", &p->no);
		printf("Enter %d. student name :\n ", k + 1);
		scanf("%s", p->name);
		printf("Enter %d. student age :\n ", k + 1);
		scanf("%d", &p->age);
	}
	p->next = NULL;
	return head;
}
void traverseList(node* head)
{
	int counter = 1;
	node* p;
	p = head;
	while (p != NULL)
	{
		printf("%d - %d  %s %d \n", counter, p->no, p->name, p->age);
		p = p->next;
		counter++;
	}
}
node* addNode(node* head)
{
	int stdNo;
	node* p, * q;
	node* newNode= (node*)malloc(sizeof(node));
	printf("Enter new student number :\n ");
	scanf("%d", &p->no);
	printf("Enter new student name :\n ");
	scanf("%s", p->name);
	printf("Enter new student age :\n ");
	scanf("%d", &p->age);
	printf("Enter std number that new record will add it before\n\n");
	printf("press 0 to add to the end of the list\n");
	scanf("%d", stdNo);
	p = head;
	if (p->no == stdNo)
	{
		newNode->next = p;
		head = newNode;
	}
	else
	{
		while (p->next != NULL && p->no != stdNo)
		{
			q = p;
			p = p->next;
		}
		if (p->no == stdNo)
		{
			q->next = newNode;
			newNode->next = p;
		}
		else if (p->next == NULL)
		{
			p->next = newNode;
			newNode->next = NULL;
		}
	}
	return head;
}
node* deleteNode(node* head)
{
	int stdNo;
	node* p, * q;
	printf("Enter std number that will be deleted\n");
	scanf("%d", &stdNo);
	p = head;
	if (p->no == stdNo)
	{
		head =p->next;
		free(p);
	}
	else
	{
		while (p->next != NULL && p->no != stdNo)
		{
			q = p;
			p = p->next;
		}
		if (p->no == stdNo)
		{
			q->next = p->next;
			free(p);
		}
		else if (p->next == NULL)
		{
			printf("no node found to remove");
		}
	}
	return head;
}
int main(void)
{
	node* head;
	int sel = 0;
	printf("1.Create List  2.Traverse List  3.Add Node  4.Delete Node  5.Exit\n");
	while (1)
	{
		printf("Selection [1-5]?\n");
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:head = createList();
			printf("adress : %x\n", head);
			traverseList(head);
			break;
		case 2: traverseList(head);
			break;
		case 3:head = addNode(head);
			traverseList(head);
			break;
		case 4:head = deleteNode(head);
			traverseList(head);
			break;
		case 5:exit(0);
		}
	}
}
