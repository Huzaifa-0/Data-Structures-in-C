#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* addFront(struct node* head ,int key)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	head = temp;
	return head;

}
void printList(struct node* head)
{
	if (head == NULL)
		printf("List Not Exist\n");
	else
	{
		while (head != NULL)
		{
			printf("%d\t", head->data);
			head = head->next;
		}
		printf("\n");
	}
}
struct node* lastFirst(struct node* head)
{
	struct node* temp = head;
	struct node* last;
	if (head == NULL)
		return NULL;
	else
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = head;
		head = last;
	}
	return head;
}

void main()
{
	struct node* head = NULL;
	head = addFront(head, 5);
	head = addFront(head, 17);
	head = addFront(head, 23);
	head = addFront(head, 11);
	head = addFront(head, 45);
	printList(head);
	head=lastFirst(head);
	printf("The Modified List is : \n");
	printList(head);
}