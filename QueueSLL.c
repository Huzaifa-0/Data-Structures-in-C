// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 

struct Queue { 
    int key;
    struct Queue *front, *rear,* next; 
}; 
  
// A utility function to create a new linked list node. 
struct Queue* newNode(int k) 
{ 
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
// The function to add a key k to q 
void enQueue(struct Queue** q, int k) 
{ 
    // Create a new LL node 
    struct Queue* temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if ((*q)->rear == NULL) { 
        (*q)->front = (*q)->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    (*q)->rear->next = temp; 
    (*q)->rear = temp; 
} 
  
// Function to remove a key from given queue q 
int deQueue(struct Queue** q) 
{ 
    // If queue is empty, return NULL. 
    if ((*q)->front == NULL) 
        return NULL; 
  
    // Store previous front and move front one node ahead 
    struct Queue* temp = (*q)->front; 
   int x=temp->key;
    free(temp); 
  
    (*q)->front = (*q)->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if ((*q)->front == NULL) 
        (*q)->rear = NULL; 
    return x; 
} 
  
// Driver Program to test anove functions 
int main() 
{ 
    struct Queue* q = createQueue(); 
    enQueue(&q, 10); 
    enQueue(&q, 20); 
    deQueue(&q); 
    deQueue(&q); 
    enQueue(&q, 30); 
    enQueue(&q, 40); 
    enQueue(&q, 50); 
printf("the dequeue is :%d\n",deQueue(&q));
    return 0; 
} 