#include<stdio.h>
#include<conio.h>
// Circular Double Linked List Implementation by Mhmoudko

// Structure for the Node
struct Node {
	int data ;
	Node *next;
	Node *prev;
};

// Initialize the Linked List
void initialize(Node *&head){
	head = NULL;
}

// !!! Count elements in the Linked List
int count(Node *&head){
	if(head == NULL){
		return 0;
	}
	
	Node *p = head ;
	int counter = 0 ;
	do{
		counter++;
		p=p->next;
	}
	while(p != head);
	return counter;
}

// !!! Insert at Head
void insertHead(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = temp;
	temp->prev = temp;
	
	if(head == NULL){
		head = temp ;
		return;
	}
	
	Node *p = head->prev;
	p->next = temp;
	temp->prev = p;
	temp->next = head;
	head->prev = temp;
	head = temp;
}

// !!! Insert at End
void insert(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = temp;
	temp->prev = temp;
	
	if(head == NULL){
		head = temp ;
		return;
	}
	
	Node *p = head->prev;
	p->next = temp;
	temp->prev = p;
	temp->next = head;
	head->prev = temp;
}

// !!! Insert at the nth place
void insert(Node *&head,int x,int n){
	if(n==0 || n==1){
		insertHead(head,x);
		return;
	}
	else if(n == count(head)){
		insert(head,x);
		return;
	}
	else if(n > count(head)){
		return;
	}
	
	Node *temp = new Node();
	temp->data = x;
	temp->next = temp;
	temp->next = temp;
	
	Node *p = head;
	for(int i=0 ; i<n-2 ; i++){
		p=p->next;
	}
	Node *q = p->next;
	p->next = temp;
	temp->next=q;
	temp->prev=p;
}

// !!! Delete the nth element from the Linked List
void del(Node *&head ,int n){
	if(head == NULL){
		return;
	}
	else if(n > count(head)){
		return;
	}
	
	Node *p = head;
	if(n==1 || n==0){
		head=p->next;
		delete p;
		return;
	}
	
	for(int i=0 ; i<n-2 ; i++){
		p=p->next;
	}
	Node *q = p->next;
	p->next = q->next ;
	if(n == count(head)){
		p = q->next;
		p->prev = q->prev;
	}
	delete q;
}

// !!! Display the Linked List
void display(Node *&head){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}
	
	Node *p = head;
	do{
		printf("%d ",p->data);
		p=p->next;
	}
	while(p != head);
}

// !!! Display the nth element in the Linked List
int display(Node *&head,int n){
	if(head == NULL || count(head)==1){
		return 0;
	}
	
	Node *p = head;
	int counter = 1 ;
	do{
		p=p->next;
		counter++;
	}
	while(p != head && counter !=n);
	return p->data;
}

// Display Part of the Linked List
void display(Node *&head,int p1,int p2){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}
	else if( p1>count(head) || p2>count(head)){
		return;
	}
	else if(p1<=0 || p2<=0){
		return;
	}
	else if(p2>p2){
		return;
	}
	
	Node *p = head;
	for(int i=0 ; i<p1-1 ; i++){
		p=p->next;
	}
	int diff = p2-p1+1;
	for(int i=0 ; i<diff ; i++){
		printf("%d ",p->data);
		p=p->next;
	}
}

// !!! Search for a number in the Linked List
int search(Node *&head,int x){
	int place = 1;
	if(head == NULL){
		return 0;
	}
	
	Node *p = head;
	do{
		place++;
		if(p->data == x){
			return place;
		}
		p=p->next;
	}while(p != head);
	
	return 0;
}

// !!! Max element in the Linked List
int max(Node *&head){
	if(head == NULL){
		return 0;
	}
	
	int max = head->data;
	Node *p = head ;
	do {
		if(p->data > max){
			max = p->data;
		}
		p=p->next;
	}
	while(p != head);
	return max;
}

// !!! Min element in the Linked List
int min(Node *&head){
	if(head == NULL){
		return 0;
	}
	
	int min = head->data;
	Node *p = head ;
	do{
		if(p->data < min){
			min = p->data;
		}
		p=p->next;
	}
	while(p != head);
	return min;
}

// !!! Average of the Linked List
float average(Node *&head){
	if(head == NULL){
		return 0;
	}
	
	int sum = 0 , counter = 0 ;
	Node *p = head ;
	do{
		counter++;
		sum += p->data;
		p=p->next;
	}
	while(p != head);
	return sum/counter;
}

// Copy Number of elements from an array to a linked list
void copy(int a[],int n,Node *&head){
	for(int i=0 ; i<n ; i++){
		insert(head,a[i]);
	}
}

// !!! Concatenate 2 Linked Lists
void cat(Node *&head , Node *head2){
	if(head==NULL || head2==NULL){
		return ;
	}
	
	Node *p = head->prev;
	Node *q = head2->prev;
	head2->prev = p;
	p->next = head2;
	q->next = head;
	head->prev = q;
}

// !!! Reverse the Linked List (NEEDS REVISION)
void reverse(Node *&head){
	Node *current = head , *p = NULL;
	do{
		p = current->next;
		current->next = current->prev;
		current->prev = p;
		current = p;
	}
	while(current != head);
}

// Swap Nodes Data
void swap(Node *&head,int n1 , int n2){
	if(head == NULL || count(head)==1){
		return ;
	}
	else if(n1 > count(head) || n2 > count(head)
		|| n1 == 0 || n2 == 0){
		return;
	}
	
	Node *p = head;
	Node *q = head;
	for(int i=0 ; i<n1-1 ; i++){
		p=p->next;
	}
	for(int i=0 ; i<n2-1 ; i++){
		q=q->next;
	}
	int temp = p->data;
	p->data = q->data;
	q->data = temp;
}

// !!! Check if sorted or not
int checkSorted(Node *&head){
	int sorted = 1;
	if(head == NULL){
		return 0;
	}
	else if(count(head)==1){
		return 1;
	}
	
	Node *p = head;
	do{
		int x = p->data;
		p = p->next ;
		if(x>p->data){
			sorted =0;
		}
	}
	while(p->next != head);
	return sorted;
}

// !!! Display Elements Above Average
void aboveAVG(Node *&head){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}
	
	int avg = average(head);
	
	Node *p = head;
	do{
		if(p->data > avg){
			printf("%d ",p->data);
		}
		p=p->next;
	}
	while(p != head);
}

// !!! Check if mirror or not (assuming even number of elements)
int mirror(Node *&head){
	int m = 1 ;
	if(head == NULL){
		return 0;
	}
	
	Node *n = head;
	Node *p = head->prev;
	do{
		if(n->data != p->data){
			m = 0;
			break;
		}
		n=n->next;
		p=p->prev;
	}while(p->next != n);
	return m;
}

int main(){
	Node* head ;
	initialize(head);
	
	int n;
	printf("Enter Number of elements: ");
	scanf("%d",&n);
	
	printf("\n+===Enter elements details===+\n");
	for(int i=0 ; i<n ; i++){
		int x ;
		printf("Enter element #%d: ",i+1);
		scanf("%d",&x);
		insert(head,x);
	}
	printf("+============================+");
	
	printf("\n\n+===Displaying Linked List===+\n");
	display(head);
	printf("\n+============================+");
	
	printf("\n\n* Number of Elements: %d",count(head));
	printf("\n* Avg: %.2f",average(head));
	printf("\n* Max: %d",max(head));
	printf("\n* Min: %d",min(head));
	printf("\n* Second Element is: %d",display(head,2));
	if(checkSorted(head)==1){
		printf("\n* The Linked List is Sorted");
	}
	else {
		printf("\n* The Linked List is not Sorted");
	}
	
	printf("\n\n+===Mirror or Not?===+\n");
	printf("The List : ");
	display(head);
	int m = mirror(head);
	if(m==1){
		printf("\nMirror");
	}
	else {
		printf("\nNot Mirror");
	}
	printf("\n+============================+");
	
	printf("\n\n+===Above Average===+\n");
	aboveAVG(head);
	printf("\n+============================+");
	
	printf("\n\n+===Test Copying 5 elements from Array to Linked List===+\n");
	Node* head2 ;
	initialize(head2);
	int a[] = {5,3,6,1,7,4,4};
	copy(a,5,head2);
	printf("The Array: ");
	for(int i=0 ; i<7 ;i++){
		printf("%d ",a[i]);
	}
	printf("\nThe List : ");
	display(head2);
	printf("\n+============================+");
	
	
	printf("\n\n+===Test Inserting 1 2 3 at Head===+");
	Node* head3 ;
	initialize(head3);
	insertHead(head3,1);
	insertHead(head3,2);
	insertHead(head3,3);
	printf("\nList: ");
	display(head3);
	printf("\n+============================+");
	
	
	printf("\n\n+===Test Inserting 5 in the second place===+");
	printf("\nList: ");
	display(head3);
	insert(head3,5,2);
	printf("\nList: ");
	display(head3);
	printf("\n+============================+");
	
	printf("\n\n+===Test Searching for 5===+");
	printf("\nList: ");
	display(head3);
	int place = search(head3,5);
	if(place==0){
		printf("\nNot Found");
	}
	else {
		printf("\nFound at place: %d",place);	
	}
	printf("\n+============================+");
	
	printf("\n\n+===Test Deleting the second place===+");
	printf("\nList: ");
	display(head3);
	del(head3,2);
	printf("\nList: ");
	display(head3);
	printf("\n+============================+");
	
	printf("\n\n+===Test Concatenating List1 with List2===+");
	printf("\nList1 : ");
	display(head2);
	printf("\nList2 : ");
	display(head);
	cat(head2,head);
	printf("\nResult: ");
	display(head2);
	printf("\n+============================+");
	
	printf("\n\n+===Test Displaying from element2 to element6===+");
	printf("\nList: ");
	display(head2);
	printf("\nList: ");
	display(head2,2,6);
	printf("\n+============================+");
	
	printf("\n\n+===Test Reversing the Linked List===+");
	printf("\nList: ");
	display(head2);
	reverse(head2);
	printf("\nList: ");
	display(head2);
	printf("\n+============================+");
	
	printf("\n\n+===Test Swapping 2nd & 5th element===+");
	Node* head4 ;
	initialize(head4);
	insert(head4,1);
	insert(head4,2);
	insert(head4,3);
	insert(head4,4);
	insert(head4,5);
	insert(head4,6);
	printf("\nList: ");
	display(head4);
	swap(head4,2,5);
	printf("\nList: ");
	display(head4);
	printf("\n+============================+");
	
	getch();
	return 0;
}
