#include<stdio.h>
#include<conio.h>
// Queue

// Structure for Linked List
struct Node {
	int data ;
	Node *next;
};

// Structure for Queue
struct Queue {
	Node *front , *rear;
};

// Initialize the Queue
void Initialize(Queue *&q){
	q->front = NULL;
	q->rear = NULL;
}
// Remove the Top Element of Stack
void Pop(Node **stack){
	if(*&stack!=NULL){
		Node *p = *stack;
		*stack=p->next;
		delete p;
	}
}
// Return the Top Element of Stack
int Top(Node **stack){
	return (*stack)->data;
}
// Check if the Queue is empty
int isEmpty(Queue *&q){
	if(q->front == NULL && q->rear == NULL){
		return 1;
	}
	else {
		return 0;
	}
}

// Insert element into the queue's rear
void Add(Queue *&q , int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;

	if(isEmpty(q)){
		q->rear = q->front = temp;
		return ;
	}

	Node *p = q->front;
	while(p->next != NULL){
		p=p->next;
	}
	p->next = temp;
	q->rear = temp;
}

// Removes the queue's front element
void Remove(Queue *&q){
	Node *p = q->front;
	if(q->front == NULL){
		return;
	}
	if(q->front == q->rear){
		q->front = q->rear = NULL;
	}
	else {
		q->front = q->front->next;
	}
	delete p;
}






// ================================
// Initializes the stack
Node* Initialize(Node **stack){
	*stack = NULL;
	return *stack;
}
// Check if stack is empty
int isEmpty(Node **stack){
	if(*stack == NULL){
		return 1;
	}
	else {
		return 0;
	}
}
// Insert Element at Top of Stack
void Push(Node **stack ,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = *stack;
	*stack = temp;
}

// Returns the front element
int Front(Queue *&q){
	if(!isEmpty(q)){
		return q->front->data;
	}
}
//1- Swap the first & last element in Queue
void SwapFL(Queue *&q){
	Node *tempStack1 = Initialize(&tempStack1);
	Node *tempStack2 = Initialize(&tempStack2);

	int first = Front(q);
	Remove(q);
	while(!isEmpty(q)){
		int x = Front(q);
		Push(&tempStack1,x);
		Remove(q);
	}

	int last = Top(&tempStack1);
	Pop(&tempStack1);
	while(!isEmpty(&tempStack1)){
		int x = Top(&tempStack1);
		Push(&tempStack2,x);
		Pop(&tempStack1);
	}

	Add(q,last);
	while(!isEmpty(&tempStack2)){
		int x = Top(&tempStack2);
		Add(q,x);
		Pop(&tempStack2);
	}
	Add(q,first);
}

//2- Delete the nth element from a queue
void del(Queue *&q , int n){
	int counter = 0;
	Queue *temp = new Queue();
	Initialize(temp);

	while(!isEmpty(q)){
		int x = Front(q);
		counter++;
		if(counter == n){
			Remove(q);
		}
		else {
			Add(temp,x);
			Remove(q);
		}
	}

	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
}
// Returns the average of the queue
float avg(Queue *&q){
	int sum = 0 , counter = 0 ;
	Queue *temp = new Queue();
	Initialize(temp);

	while(!isEmpty(q)){
		int x = Front(q);
		counter++;
		sum += x;
		Add(temp,x);
		Remove(q);
	}

	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}

	return sum/counter;
}

// 3- Delete elements below the average of the queue
void delBelowAvg(Queue *&q){
	float average = avg(q);
	Queue *temp = new Queue();
	Initialize(temp);

	while(!isEmpty(q)){
		int x = Front(q);
		if(x < average){
			Remove(q);
		}
		else {
			Add(temp,x);
			Remove(q);
		}
	}

	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
}

//4- Extract even values from a queue to another queue
Queue* extractEven(Queue *&q){
	Queue *even = new Queue();
	Initialize(even);
	Queue *temp = new Queue();
	Initialize(temp);

	while(!isEmpty(q)){
		int x = Front(q);
		if(x%2 ==0){
			Add(even,x);
		}
		Add(temp,x);
		Remove(q);
	}

	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}

	return even;
}

// 5-Reverse a queue
void reverse(Queue *&q){
	Node *tempStack = Initialize(&tempStack);

	while(!isEmpty(q)){
		int x = Front(q);
		Push(&tempStack,x);
		Remove(q);
	}

	while(!isEmpty(&tempStack)){
		int x = Top(&tempStack);
		Add(q,x);
		Pop(&tempStack);
	}
}

int main(){
	printf("+===== Test Adding 1 2 3 4 5 =====+\n");
	Queue *q1 = new Queue();
	Initialize(q1);
	Add(q1,1);
	Add(q1,2);
	Add(q1,3);
	Add(q1,4);
	Add(q1,5);


	getch();
	return 0;
}
