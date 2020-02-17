#include<stdio.h>
#include<conio.h>
//1-1
struct Node {
	int data ;
	Node *next;
};

//1-2 Initialize the Linked List
void initialize(Node *&head){
	head = NULL;
}

//1-3 Destroy the Linked List
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


//2-1 Insert at Head
void insertHead(Node *&head,int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

//2-2 Insert at End
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

//2-3 Insert at the nth place
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
//3-1Given a 1D array of element, create a linked list from the array(one new node per element, adding the node to the end of the list each time
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
Node* arrayToList(int arr[], int n)
{
	Node* head = NULL;
	for (int i = 0; i < n; i++)
		insert(&head, arr[i]);
	return head;
}

















//4-1 Count elements in the Linked List
int count(Node*& head) {
	Node* p = head;
	int counter = 0;
	while (p != NULL) {
		counter++;
		p = p->next;
	}
	return counter;
}

//4-2 Max element in the Linked List
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

//4-2 Min element in the Linked List
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

//4-2 Average of the Linked List
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
//5-2 Swap Nodes Data
void swap(Node*& head, int n1, int n2) {
	if (head == NULL || count(head) == 1) {
		return;
	}
	else if (n1 > count(head) || n2 > count(head)
		|| n1 == 0 || n2 == 0) {
		return;
	}

	Node* p = head;
	Node* q = head;
	for (int i = 0; i < n1 - 1; i++) {
		p = p->next;
	}
	for (int i = 0; i < n2 - 1; i++) {
		q = q->next;
	}
	int temp = p->data;
	p->data = q->data;
	q->data = temp;
}



//5-4 Reverse the Linked List
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
//5-5 Concatenate 2 Linked Lists
void cat(Node*& head, Node* head2) {
	if (head == NULL || head2 == NULL) {
		return;
	}

	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = head2;
}


void main()
{

	int i;
	int num;
	struct  Node* first, * nw, * pre, * new1, * count;
	clrscr();
	printf("\n Enter the number of node you want to create: ");
	scanf("%d", &num);
	first->next = NULL;
	nw = first;
	for (i = 0; i < num; i++)
	{
		nw->next = (struct Node*) malloc(sizeof(struct Node));
		nw = nw->next;
		printf("\n Enter the node: %d: ", i + 1);
		scanf("%d", &nw->data);
		nw->next = NULL;
	}
	new1 = first;
	for (; new1->next != NULL; new1 = new1->next)
	{
		for (count = new1->next; count != NULL; count = count->next)
		{
			if (new1->data > count->data)
			{
				int temp = new1->data;
				new1->data = count->data;
				count->data = temp;
			}
		}
	}
	//3-2Given an unsorted array, create a sorted list by creating a new node for each array element, and inserting it into its appropriate position in the list.

	nw = first->next;
	printf("\n After sorting the Linked list is as follows:\n");
	while (nw)
	{
		printf("%d\t", nw->data);
		nw = nw->next;
	}
	getch();
}
