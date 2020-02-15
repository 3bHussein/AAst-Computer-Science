#include<stdio.h>
#include<conio.h>

struct Node {
	int data ;
	Node *next;
};

// Initialize the Linked List
void initialize(Node *&head){
	head = NULL;
}

// Destroy the Linked List
void destroy(Node *&head){
	if(head == NULL){
		return;
	}

	Node *p = head;
	while(head != NULL){
		p = head->next;
		delete head;
		head = p;
	}
}

// Count elements in the Linked List
int count(Node *&head){
	Node *p = head ;
	int counter = 0 ;
	while(p != NULL){
		counter++;
		p=p->next;
	}
	return counter;
}

// Insert at Head
void insertHead(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

// Insert Sorted
void insertSorted(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;

	Node *p = head;
	Node *q = NULL;
	while(p != NULL && x>p->data){
		q = p;
		p=p->next;
	}

	if(q == NULL){
		temp->next = head;
		head = temp;
	}
	else {
		q->next = temp;
		temp->next =p;
	}

}

// Insert at End
void insert(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;

	if(head == NULL){
		head = temp ;
		return;
	}

	Node *p = head;
	while(p->next != NULL){
		p=p->next;
	}
	p->next=temp;
}

// Insert at the nth place
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
	temp->next = NULL;

	Node *p = head;
	for(int i=0 ; i<n-2 ; i++){
		p=p->next;
	}
	Node *q = p->next;
	p->next = temp;
	temp->next=q;
}

// Delete the nth element from the Linked List
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
	delete q;
}

// Display the Linked List
void display(Node *&head){
	if(head == NULL){
		printf("Empty Linked List");
		return;
	}

	Node *p = head;
	while(p != NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}

// Display the nth element in the Linked List
int display(Node *&head,int n){
	if(head == NULL || count(head)==1){
		return 0;
	}

	Node *p = head;
	int counter = 1 ;
	while(p != NULL && counter !=n){
		p=p->next;
		counter++;
	}
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

// Search for a number in the Linked List
int search(Node *&head,int x){
	int place = 0;
	if(head == NULL){
		return 0;
	}

	Node *p = head;
	while(p != NULL){
		place++;
		if(p->data == x){
			return place;
		}
		p=p->next;
	}

	return 0;
}

// Max element in the Linked List
int max(Node *&head){
	if(head == NULL){
		return 0;
	}

	int max = head->data;
	Node *p = head ;
	while(p != NULL){
		if(p->data > max){
			max = p->data;
		}
		p=p->next;
	}
	return max;
}

// Min element in the Linked List
int min(Node *&head){
	if(head == NULL){
		return 0;
	}

	int min = head->data;
	Node *p = head ;
	while(p != NULL){
		if(p->data < min){
			min = p->data;
		}
		p=p->next;
	}
	return min;
}

// Average of the Linked List
float average(Node *&head){
	if(head == NULL){
		return 0;
	}

	int sum = 0 , counter = 0 ;
	Node *p = head ;
	while(p != NULL){
		counter++;
		sum += p->data;
		p=p->next;
	}
	return sum/counter;
}

// Copy Number of elements from an array to a linked list
void copy(int a[],int n,Node *&head){
	for(int i=0 ; i<n ; i++){
		insert(head,a[i]);
	}
}

// Concatenate 2 Linked Lists
void cat(Node *&head , Node *head2){
	if(head==NULL || head2==NULL){
		return ;
	}

	Node *p = head;
	while(p->next != NULL){
		p=p->next;
	}
	p->next=head2;
}

// Reverse the Linked List
void reverse(Node *&head){
	Node *p = head , *next , *prev;
	prev = NULL ;
	while(p != NULL){
		next = p->next ;
		p->next = prev;
		prev = p;
		p = next;
	}
	head = prev;
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

// Check if sorted or not
int checkSorted(Node *&head){
	int sorted = 1;
	if(head == NULL){
		return 0;
	}
	else if(count(head)==1){
		return 1;
	}

	Node *p = head;
	while(p->next != NULL){
		int x = p->data;
		p = p->next ;
		if(x>p->data){
			sorted =0;
		}
	}
	return sorted;
}

int main(){
	Node* head ;
	initialize(head);

	int n;
	printf("Enter Number of elements: ");
	scanf("%d",&n);

	int s ;
	printf("\nDo You want it to be inserted in sorted order?\n");
	printf("(Yes=1 , No=0) Choice: ");
	scanf("%d",&s);

	printf("\n+===Enter elements details (Integers)===+\n");
	for(int i=0 ; i<n ; i++){
		int x ;
		printf("Enter element #%d: ",i+1);
		scanf("%d",&x);
		if(s==0){
			insert(head,x);
		}
		else {
			insertSorted(head,x);
		}
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
	display(head3);
	cat(head2,head3);
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
	printf("\nList: ");
	display(head2);
	swap(head2,2,5);
	printf("\nList: ");
	display(head2);
	printf("\n+============================+");

	printf("\n\n+===Test Destroying the Linked List===+");
	printf("\nList: ");
	display(head2);
	destroy(head2);
	printf("\nList: ");
	display(head2);
	printf("\n+============================+");

	getch();
	return 0;
}
