#include<stdio.h>
#include<conio.h>
// Queue Implementation using Linked Lists by Mhmoudko

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

// Returns the front element
int Front(Queue *&q){
	if(!isEmpty(q)){
		return q->front->data;
	}
}

// Returns the rear element
int Rear(Queue *&q){
	if(!isEmpty(q)){
		return q->rear->data;
	}
}

// Prints the Queue (Just for Testing)
void Print(Queue *&q){
	if(!isEmpty(q)){
		Node *p = q->front;
		while(p != NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
	else {
		printf("Empty Queue");
	}
}

// Prints the Queue (Correct Implementations)
void Display(Queue *&q){
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q)){
		int x = Front(q);
		printf("%d ",x);
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
}

// Counts the elements in the Queue
int Count(Queue *&q){
	int counter = 0;
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q)){
		int x = Front(q);
		counter++;
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
	
	return counter;
}

// Returns the max element in the queue
int max(Queue *&q){
	int max = Front(q);
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q)){
		int x = Front(q);
		if(x > max){
			max = x;
		}
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
	
	return max;
}

// Returns the min element in the queue
int min(Queue *&q){
	int min = Front(q);
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q)){
		int x = Front(q);
		if(x < min){
			min = x;
		}
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
	
	return min;
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

// Returns the average of the queue
int Search(Queue *&q , int target){
	int counter = 0 , found = -1;
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q)){
		int x = Front(q);
		counter++;
		if(x == target){
			found = counter;
		}
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
	
	return found;
}

// Check if 2 Queues are equal
int isEqual(Queue *&q1 , Queue *&q2){
	int equal = 1;
	Queue *temp1 = new Queue();
	Initialize(temp1);
	Queue *temp2 = new Queue();
	Initialize(temp2);
	
	while(!isEmpty(q1) && !isEmpty(q2)){
		int x1 = Front(q1);
		int x2 = Front(q2);
		if(x1 != x2){
			equal = 0;
		}
		Add(temp1,x1);
		Add(temp2,x2);
		Remove(q1);
		Remove(q2);
	}
	
	if(!isEmpty(q1) || !isEmpty(q2)){
		equal = 0;
	}
	
	while(!isEmpty(q1) && !isEmpty(q2)){
		int x1 = Front(q1);
		int x2 = Front(q2);
		Add(q1,x1);
		Add(q2,x2);
		Remove(temp1);
		Remove(temp2);
	}
	
	return equal;
}

// ================================
// stack operations:
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
// Remove the Top Element of Stack
void Pop(Node **stack){
	if(!isEmpty(*&stack)){
		Node *p = *stack;
		*stack=p->next;
		delete p;
	}
}
// Return the Top Element of Stack
int Top(Node **stack){
	return (*stack)->data;
}
// ================================

// Check if 2 Queues are reverse to each other
int isReverse(Queue *&q1 , Queue *&q2){
	int reverse = 1;
	Node *tempStack = Initialize(&tempStack) ;
	Queue *temp = new Queue();
	Initialize(temp);
	
	while(!isEmpty(q1)){
		int x = Front(q1);
		Push(&tempStack,x);
		Remove(q1);
	}
	
	while(!isEmpty(&tempStack)){
		int x = Top(&tempStack);
		Add(temp,x);
		Pop(&tempStack);
	}
	
	if(!isEqual(temp,q2)){
		reverse = 0;
	}

	while(!isEmpty(temp)){
		int x = Front(q1);
		Push(&tempStack,x);
		Remove(temp);
	}
	
	while(!isEmpty(&tempStack)){
		int x = Top(&tempStack);
		Add(q1,x);
		Pop(&tempStack);
	}
	
	return reverse;
}

// Check if the upper half equals the lower
int isUpperLower(Queue *&q){
	int n = Count(q) ;
	int sum1=0 , sum2=0 , counter=0 ;
	Queue *temp = new Queue();
	Initialize(temp);
	
	if(n%2 != 0){
		return 0;
	}
	
	while(!isEmpty(q)){
		int x = Front(q);
		if(counter < n/2){
			sum1 += x;
			counter++;
		}
		else {
			sum2 += x;
		}
		Add(temp,x);
		Remove(q);
	}
	
	while(!isEmpty(temp)){
		int x = Front(temp);
		Add(q,x);
		Remove(temp);
	}
	
	if(sum1 == sum2){
		return 1;
	}
	else {
		return 0;
	}
}

// Swap the first & last element in Queue
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

// Delete the nth element from a queue
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

// Delete elements below the average of the queue
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

// Extract even values from a queue to another queue
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

// Reverse a queue
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
	Display(q1);
	
	printf("\n\n* Max = %d",max(q1));
	printf("\n* Min = %d",min(q1));
	printf("\n* Avg = %.2f",avg(q1));
	printf("\n* Number of elements = %d",Count(q1));
	
	printf("\n\n+===== Test Removing 2 elements =====+\n");
	Remove(q1);
	Remove(q1);
	Display(q1);
	
	printf("\n\n+===== Test Searching for 4 =====+\n");
	Display(q1);
	int flag = Search(q1,4);
	if(flag==-1){
		printf("\nNot Found");
	}
	else {
		printf("\nFound at place %d",flag);
	}
	
	printf("\n\n+===== Check if 2 Queues are equal =====+\n");
	Queue *q2 = new Queue();
	Initialize(q2);
	Add(q2,10);
	Add(q2,20);
	Add(q2,30);
	Add(q2,40);
	Add(q2,50);
	Add(q2,10);
	Add(q2,20);
	printf("Queue1: ");
	Display(q2);
	printf("\n");
	Queue *q3 = new Queue();
	Initialize(q3);
	Add(q3,10);
	Add(q3,20);
	Add(q3,30);
	Add(q3,40);
	Add(q3,50);
	Add(q3,10);
	Add(q3,20);
	printf("Queue2: ");
	Display(q3);
	if(isEqual(q2,q3)){
		printf("\nQueues are Equal");
	}
	else {
		printf("\nQueues are Not Equal");
	}
	
	printf("\n\n+===== Check if 2 Queues are reverse to each other =====+\n");
	Queue *q4 = new Queue();
	Initialize(q4);
	Add(q4,1);
	Add(q4,2);
	Add(q4,3);
	Add(q4,4);
	Add(q4,5);
	printf("Queue1: ");
	Display(q4);
	printf("\n");
	Queue *q5 = new Queue();
	Initialize(q5);
	Add(q5,5);
	Add(q5,4);
	Add(q5,3);
	Add(q5,2);
	Add(q5,1);
	printf("Queue2: ");
	Display(q5);
	if(isReverse(q4,q5)){
		printf("\nQueues are Reverse to each other");
	}
	else {
		printf("\nQueues are Not Reverse to each other");
	}
	
	printf("\n\n+===== Check if Upper half of queue equals the lower =====+\n");
	Queue *q6 = new Queue();
	Initialize(q6);
	Add(q6,2);
	Add(q6,3);
	Add(q6,1);
	Add(q6,4);
	printf("Queue: ");
	Display(q6);
	if(isUpperLower(q6)){
		printf("\nUpper Half equals the lower");
	}
	else {
		printf("\nUpper Half not equals the lower");
	}
	
	printf("\n\n+===== Swap the first & last element in queue =====+\n");
	printf("Before: ");
	Display(q6);
	SwapFL(q6);
	printf("\nAfter: ");
	Display(q6);
	
	printf("\n\n+===== Test Deleting element 3 =====+\n");
	printf("Before: ");
	Display(q6);
	del(q6,3);
	printf("\nAfter: ");
	Display(q6);
	
	printf("\n\n+===== Delete all elements below the average in queue =====+\n");
	Queue *q7 = new Queue();
	Initialize(q7);
	Add(q7,1);
	Add(q7,2);
	Add(q7,100);
	Add(q7,110);
	Add(q7,120);
	Add(q7,130);
	Add(q7,140);
	Add(q7,3);
	Add(q7,4);
	printf("Before: ");
	Display(q7);
	printf("\nAvg: %.2f",avg(q7));
	delBelowAvg(q7);
	printf("\nAfter: ");
	Display(q7);
	
	printf("\n\n+===== Extract even values to another queue =====+\n");
	Queue *q8 = new Queue();
	Initialize(q8);
	Add(q8,1);
	Add(q8,2);
	Add(q8,3);
	Add(q8,4);
	Add(q8,5);
	Add(q8,6);
	Add(q8,7);
	Add(q8,8);
	Add(q8,9);
	printf("Queue: ");
	Display(q8);
	printf("\nExtracted: ");
	Queue *q9 = new Queue();
	Initialize(q9);
	q9 = extractEven(q8);
	Display(q9);
	
	printf("\n\n+===== Test Reversing a queue =====+\n");
	printf("Before: ");
	Display(q8);
	reverse(q8);
	printf("\nAfter: ");
	Display(q8);
	
	getch();
	return 0;
}
