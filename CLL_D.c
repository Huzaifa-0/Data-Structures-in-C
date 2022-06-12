#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* insertLast(struct node* head, int n) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) 
    {
    	temp->data = n;
        temp->next = temp->prev = temp; 
        head = temp; 
    }
    struct node* last=head->prev;  
    temp->data = n;
    temp->next = head; 
    last->next = head->prev = temp; 
    temp->prev = last; 
    return head;
}
void printList(struct node* head)
{
	struct node *temp=head;
	if (head == NULL)
		printf("List Not Exist\n");
	else
	{
		while (temp->next!=head)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d ", temp->data);
		printf("\n");
	}
}
void removeDuplicates(struct node *head) 
{ 
    struct node *p, *q,*last,*dup; 
    p = head;
	last=head->prev;
    while (p != last ) 
    { 
        q = p->next; 
        while (q != head ) 
        { 
            if (p->data == q->data) 
            { 
                dup = q; 
                q->prev->next=q->next;
				q->next->prev=q->prev;
				q=q->next;
                free(dup); 
				last=head->prev;
            } 
            else 
                q = q->next; 
        } 
        p = p->next; 
    } 
} 

void main()
{
	struct node *head=NULL;
	head=insertLast(head, 5);
    head=insertLast(head, 3);
    head=insertLast(head, 1);
    head=insertLast(head, 7);
    head=insertLast(head, 3);
    head=insertLast(head, 3);
    head=insertLast(head, 7);
    head=insertLast(head, 5);
	printf("Created Circular Doubly Linked List is: \n"); 
	printList(head);
	removeDuplicates(head);
	printf("The New Circular Doubly Linked List is: \n");
	printList(head);
}