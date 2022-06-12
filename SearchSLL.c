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
struct node *erase(struct node *head,int key)
{
    if(head==NULL)
    return head;
    else
    {
        struct node *temp=head;
        if(head->data==key)
        {
        head=head->next;
        free(temp);
        }
        else
        {
            while(temp->next!=NULL &&temp->next->data!=key)
            temp=temp->next;
            if(temp->next==NULL)
            return head;
            struct node *del=temp->next;
            temp->next=del->next;
            free(del);
        }
        return head;
    }
    
}
bool search(struct node* head, int x) 
{ 
    struct node* current = head;   
    while (current != NULL) 
    { 
        if (current->data == x)
        {
            printf("The value of Element is indeed : %d\n",current->data);
            return true; 
        }
        current = current->next; 
    } 
    return false; 
} 
struct node* destoy(struct node *head)
{
	if(head==NULL)
	return head;
	destoy(head->next);
	free(head);
}
bool srh(struct node* head, int x) 
{ 
    if (head == NULL) 
        return false;
    if (head->data == x)
    {
        printf("The value of Element is indeed : %d\n",head->data);
        return true; 
    }
    return srh(head->next, x); 
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
	head = addFront(head, 5);
	head = addFront(head, 17);
	head = addFront(head, 23);
	head = addFront(head, 11);
	head = addFront(head, 45);
	search(head, 23)? printf("Yes\n") : printf("No\n");
    srh(head, 101)? printf("Yes") : printf("No\n"); 
	//printList(head);
    head = erase(head,23);
   //head = destoy(head);
	printf("The Modified List is : \n");
	printList(head);
}