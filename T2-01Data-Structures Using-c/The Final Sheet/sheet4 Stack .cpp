#include<stdio.h>
#include<conio.h>
// Stack

// Structure of Linked List
struct Node {
	int data ;
	Node *next;
};

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

// Remove the Top Element of Stack (returns the removed element)
int Pop(Node **stack,int x){
	if(!isEmpty(*&stack)){
		Node *p = *stack;
		*stack=p->next;
		int data = p->data;
		delete p;
		return data;
	}
}

// Return the Top Element of Stack
int Top(Node **stack){
	return (*stack)->data;
}



// Count elements in the Stack
int Count(Node **stack){
	int counter = 0;
	Node *temp = Initialize(&temp) ;

	while(!isEmpty(*&stack)){
		int x = Top(*&stack);
		counter++;
		Push(&temp,x);
		Pop(*&stack);
	}

	while(!isEmpty(&temp)){
		int x = Top(&temp);
		Push(*&stack,x);
		Pop(&temp);
	}

	return counter;
}

// 1- Get max element of stack
int max(Node **stack){
	int max = Top(*&stack);
	Node *temp = Initialize(&temp) ;

	while(!isEmpty(*&stack)){
		int x = Top(*&stack);
		Push(&temp,x);
		if(x > max){
			max = x;
		}
		Pop(*&stack);
	}

	while(!isEmpty(&temp)){
		int x = Top(&temp);
		Push(*&stack,x);
		Pop(&temp);
	}

	return max;
}


//2- Get average of stack
float avg(Node **stack){
	int sum = 0 , counter = 0;
	Node *temp = Initialize(&temp) ;

	while(!isEmpty(*&stack)){
		int x = Top(*&stack);
		sum += x;
		counter++;
		Push(&temp,x);
		Pop(*&stack);
	}

	while(!isEmpty(&temp)){
		int x = Top(&temp);
		Push(*&stack,x);
		Pop(&temp);
	}

	return sum/counter;
}


//3- Check if 2 Stacks are equal
int isEqual(Node **stack1,Node **stack2){
	int equal = 1;
	Node *temp1 = Initialize(&temp1) , *temp2 = Initialize(&temp2);

	while(!isEmpty(*&stack1) && !isEmpty(*&stack2)){
		int x1 = Top(*&stack1);
		int x2 = Top(*&stack2);
		if(x1 != x2){
			equal = 0;
		}
		Push(&temp1,x1);
		Push(&temp2,x2);
		Pop(*&stack1);
		Pop(*&stack2);
	}

	if(!isEmpty(*&stack1)){
		int x1 = Top(*&stack1);
		equal = 0;
		Push(&temp1,x1);
	}

	if(!isEmpty(*&stack2)){
		int x2 = Top(*&stack2);
		equal = 0;
		Push(&temp2,x2);
	}

	while(!isEmpty(&temp1)){
		int x = Top(&temp1);
		Push(*&stack1,x);
		Pop(&temp1);
	}

	while(!isEmpty(&temp2)){
		int x = Top(&temp2);
		Push(*&stack2,x);
		Pop(&temp2);
	}

	return equal;
}

//4- Check if 2 Stacks are reverse to each other
int isReverse(Node **stack1,Node **stack2){
	int reverse = 1;
	Node *temp = Initialize(&temp) ;

	while(!isEmpty(*&stack1)){
		int x = Top(*&stack1);
		Push(&temp,x);
		Pop(*&stack1);
	}

	if(!isEqual(&temp,*&stack2)){
		reverse = 0;
	}

	while(!isEmpty(&temp)){
		int x = Top(&temp);
		Push(&*stack1,x);
		Pop(&temp);
	}

	return reverse;
}

//5- Check if the upper half equals the lower
int isUpperLower(Node **stack){
	int n = Count(*&stack) ;
	int sum1=0 , sum2=0 , counter=0 ;
	Node *temp = Initialize(&temp);

	if(n%2 != 0){
		return 0;
	}

	while(!isEmpty(*&stack)){
		int x = Top(*&stack);
		if(counter < n/2){
			sum1 += x;
			counter++;
		}
		else {
			sum2 += x;
		}
		Push(&temp,x);
		Pop(*&stack);
	}

	while(!isEmpty(&temp)){
		int x = Top(&temp);
		Push(*&stack,x);
		Pop(&temp);
	}

	if(sum1 == sum2){
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	printf("+===== Test Pushing 1 2 3 4 5 1 2 =====+\n");
	Node *stack1 = Initialize(&stack1);
	Push(&stack1,1);
	Push(&stack1,2);
	Push(&stack1,3);
	Push(&stack1,4);
	Push(&stack1,5);
	Push(&stack1,1);
	Push(&stack1,2);

	printf("\n\n* Max = %d",max(&stack1));
	//printf("\n* Min = %d",min(&stack1));
	printf("\n* Avg = %.2f",avg(&stack1));
	printf("\n* Number of elements = %d",Count(&stack1));

	printf("\n\n+===== Test Popping 2 elements =====+\n");
	Pop(&stack1);
	Pop(&stack1);
//	Display(&stack1);

	printf("\n\n+===== Test Searching for 2 =====+\n");
//	Display(&stack1);
//	int flag = Search(&stack1,2);

	printf("\n\n+===== Check if 2 Stacks are equal =====+\n");
	Node *stack2 = Initialize(&stack2);
	Push(&stack2,10);
	Push(&stack2,20);
	Push(&stack2,30);
	Push(&stack2,40);
	Push(&stack2,50);
	Push(&stack2,10);
	Push(&stack2,20);
	printf("Stack1: ");
//	Display(&stack2);
	printf("\n");
	Node *stack3 = Initialize(&stack3);
	Push(&stack3,10);
	Push(&stack3,20);
	Push(&stack3,30);
	Push(&stack3,40);
	Push(&stack3,50);
	Push(&stack3,10);
	Push(&stack3,20);
	printf("Stack2: ");
//	Display(&stack3);
	if(isEqual(&stack2,&stack3)){
		printf("\nStacks are Equal");
	}
	else {
		printf("\nStacks are Not Equal");
	}

	printf("\n\n+===== Check if 2 Stacks are reverse to each other =====+\n");
	Node *stack4 = Initialize(&stack4);
	Push(&stack4,1);
	Push(&stack4,2);
	Push(&stack4,3);
	Push(&stack4,4);
	Push(&stack4,5);
	printf("Stack1: ");
//	Display(&stack4);
	printf("\n");
	Node *stack5 = Initialize(&stack5);
	Push(&stack5,5);
	Push(&stack5,4);
	Push(&stack5,3);
	Push(&stack5,2);
	Push(&stack5,1);
	printf("Stack2: ");
//	Display(&stack5);
	if(isReverse(&stack4,&stack5)){
		printf("\nStacks are Reverse to each other");
	}
	else {
		printf("\nStacks are Not Reverse to each other");
	}

	printf("\n\n+===== Check if Upper half of stack equals the lower =====+\n");
	Node *stack6 = Initialize(&stack6);
	Push(&stack6,2);
	Push(&stack6,3);
	Push(&stack6,1);
	Push(&stack6,4);

	getch();
	return 0;
}
