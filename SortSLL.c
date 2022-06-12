#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
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
void Sort(struct node *head) 
{ 
    bool swapped; 
    struct node *ptr1; 
    if (head == NULL) 
        printf("List Not Exist\n"); 
  
    do
    { 
        swapped = false; 
        ptr1 = head; 
  
        while (ptr1->next != NULL) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = true; 
            } 
            ptr1 = ptr1->next; 
        } 
         
    } 
    while (swapped); 
} 

struct node *minToFront(struct node **head)
{
    struct node *p, *q, *k;
    p = q = *(head);
    if(*(head) == NULL)
      return *(head);
       
      while(p->next != NULL)
      {
          if(p->data > p->next->data && q->data > p->next->data)
          {
             k = p;
             q = p->next;
          }
             p = p->next;
      }
      k->next = q->next;
      q->next = *(head);
      *(head) = q;
      return *(head);
} 

void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
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
void main()
{
	struct node* head = NULL;
	
	head = addFront(head, 17);
	head = addFront(head, 13);
    head = addFront(head, 5);
	head = addFront(head, 12);
	head = addFront(head, 45);
    printList(head);
    printf("putting the  min element in front....\n");
    minToFront(&head);
    printList(head);
    printf("After Sorting....\n");
    Sort(head);
    printList(head);
	
}