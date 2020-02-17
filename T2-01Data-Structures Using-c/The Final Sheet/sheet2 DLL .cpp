#include<stdio.h>
#include<conio.h>

// !!! Structure for the Node
struct Node {
	int data ;
	Node *next;
	Node *prev;
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


//1- !!! Insert at Head
void insertHead(Node *&head,int x){
	Node *temp = new Node();
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;

	if(head == NULL){
		head = temp;
		return;
	}

	head->prev = temp;
	temp->next = head;
	head = temp;
}

// !!! Insert Sorted
void insertSorted(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;

	Node *p = head;
	Node *q = NULL;
	while(p != NULL && x>p->data){
		q = p;
		p=p->next;
	}

	if(q == NULL){
		if(head != NULL){
			temp->next = head;
			head->prev = temp;
		}
		head = temp;
	}
	else {
		q->next = temp;
		if(p!=NULL){
			temp->next = p;
			p->prev = temp;
		}
		temp->prev = q;
	}
}

// !!! Insert at End
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
	temp->prev=p;
}

// 1- !!! Delete the nth element from the Linked List
void del(Node *&head ,int n){
	if(head == NULL){
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

//1- Display the Linked List
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


//2-Swap Nodes Data
void swap(Node *&head,int n1 , int n2){

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

//6- Check if sorted or not
int checkSorted(Node *&head){
	int sorted = 1;
	if(head == NULL){
		return 0;
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
	printf("\nDo You want it to be sorted? (Yes=1 , No=0)\n");
	printf("Choice: ");
	scanf("%d",&s);

	printf("\n+===Enter elements details===+\n");
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
	printf("\nList: ");
	display(head3);
	printf("\n+============================+");

	printf("\n\n+===Test Searching for 5===+");
	printf("\nList: ");
	display(head3);
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
	printf("\nResult: ");
	display(head2);
	printf("\n+============================+");

	printf("\n\n+===Test Displaying from element2 to element6===+");
	printf("\nList: ");
	display(head2);
	printf("\nList: ");
	printf("\n+============================+");

	printf("\n\n+===Test Reversing the Linked List===+");
	printf("\nList: ");
	display(head2);
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

	printf("\n\n+===Test Destroying the Linked List===+");
	printf("\nList: ");
	display(head3);
	destroy(head3);
	printf("\nList: ");
	display(head3);
	printf("\n+============================+");

	getch();
	return 0;
}
