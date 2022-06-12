
#include <stdio.h> 
#include <stdlib.h> 
  
struct StackNode { 
    int data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode* top) 
{ 
    return !top; 
} 
  
void push(struct StackNode** top, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *top; 
    *top = stackNode; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop(struct StackNode** top) 
{ 
    if (isEmpty(*top)) 
        return NULL; 
    struct StackNode* temp = *top; 
    *top = (*top)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek(struct StackNode* top) 
{ 
    if (isEmpty(top)) 
        return NULL; 
    return top->data; 
} 
  
int main() 
{ 
    struct StackNode* top = NULL; 
  
    push(&top, 3); 
    push(&top, 2);
	int x=pop(&top)*pop(&top);
	printf("the x value is : %d\n",x);
	push(&top,x);
	push(&top,5);
	push(&top,6);
	x=pop(&top)*pop(&top);
	printf("the x value is : %d\n",x);
	push(&top,x);
	x=pop(&top)+pop(&top);
	printf("the x value is : %d\n",x);
	push(&top,x);
    return 0; 
    
}