#include<stdio.h>
#include<stdlib.h>
struct node {
	char data;
	struct node* next;
	struct node* prev;
};
struct node* addLast(struct node* head, char c)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* last = head;
	temp->data = c;
	temp->next = NULL;
	if (head == NULL)
	{
		temp->prev = NULL;
		head = temp;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->prev = last;
	}
	return head;
}
void plaindrom(struct node* head,int n)
{
	struct node* p = head;
	struct node* q = p;
	int cnt=0;
	int i;
	while (q->next != NULL)
		q = q->next;
	for (  i = 0; i < n / 2; i++)
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->prev;
			cnt++;
		}
	}
	if (cnt == n/ 2)
		printf(" is Palindrom ");
	else
		printf(" not Palidrom ");
}
void print(struct node* head)
{
	if (head == NULL)
		printf("the list is empty \n");
	else
	{
		while (head != NULL)
		{
			printf("%c", head->data);
			head = head->next;
		}
	}
	
}

void main()
{
	struct node *head=NULL;
	int n = 5;
	printf("The Length of the Word is : %d \n",n);
    head=addLast(head,'s');
	head=addLast(head,'e');
	head=addLast(head,'k');
	head=addLast(head,'e');
	head=addLast(head,'s');
	printf("The Word ");
    print(head);
	plaindrom(head,n);

}