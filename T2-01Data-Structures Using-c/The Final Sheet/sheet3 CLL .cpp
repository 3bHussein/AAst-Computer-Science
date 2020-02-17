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
//6-insert into sort
// !!! Insert Sorted
void insertSorted(Node*& head, int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;

	Node* p = head;
	Node* q = NULL;
	while (p != NULL && x > p->data) {
		q = p;
		p = p->next;
	}

	if (q == NULL) {
		if (head != NULL) {
			temp->next = head;
			head->prev = temp;
		}
		head = temp;
	}
	else {
		q->next = temp;
		if (p != NULL) {
			temp->next = p;
			p->prev = temp;
		}
		temp->prev = q;
	}
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





// 4- !!! Check if sorted or not
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

// 5- !!! Display Elements Above Average
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

//8- !!! Check if mirror or not (assuming even number of elements)
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
//	display(head);
	printf("\n+============================+");

	printf("\n\n* Number of Elements: %d",count(head));
	printf("\n* Avg: %.2f",average(head));
//	printf("\n* Max: %d",max(head));
//	printf("\n* Min: %d",min(head));
//	printf("\n* Second Element is: %d",display(head,2));
	if(checkSorted(head)==1){
		printf("\n* The Linked List is Sorted");
	}
	else {
		printf("\n* The Linked List is not Sorted");
	}

	printf("\n\n+===Mirror or Not?===+\n");
	printf("The List : ");
//	display(head);
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
//	copy(a,5,head2);
	printf("The Array: ");
	for(int i=0 ; i<7 ;i++){
		printf("%d ",a[i]);
	}
	printf("\nThe List : ");
//	display(head2);
	printf("\n+============================+");


	printf("\n\n+===Test Inserting 1 2 3 at Head===+");
	Node* head3 ;
	initialize(head3);
	insertHead(head3,1);
	insertHead(head3,2);
	insertHead(head3,3);
	printf("\nList: ");
//	display(head3);
	printf("\n+============================+");


	printf("\n\n+===Test Inserting 5 in the second place===+");
	printf("\nList: ");
//	display(head3);
//	insert(head3,5,2);
	printf("\nList: ");
//	display(head3);
	printf("\n+============================+");

	printf("\n\n+===Test Searching for 5===+");
	printf("\nList: ");
//	display(head3);
//	int place = search(head3,5);
	printf("\n+============================+");

	printf("\n\n+===Test Deleting the second place===+");
	printf("\nList: ");
//	display(head3);
//	del(head3,2);
	printf("\nList: ");
//	display(head3);
	printf("\n+============================+");

	printf("\n\n+===Test Concatenating List1 with List2===+");
	printf("\nList1 : ");
//	display(head2);
	printf("\nList2 : ");
//	display(head);
//	cat(head2,head);
	printf("\nResult: ");
//	display(head2);
	printf("\n+============================+");

	printf("\n\n+===Test Displaying from element2 to element6===+");
	printf("\nList: ");
//	display(head2);
	printf("\nList: ");
//	display(head2,2,6);
	printf("\n+============================+");

	printf("\n\n+===Test Reversing the Linked List===+");
	printf("\nList: ");
//	display(head2);
//	reverse(head2);
	printf("\nList: ");
//	display(head2);
	printf("\n+============================+");

	getch();
	return 0;
}
