#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Create ADT Node
//define a basic linked list structure
 struct snode{
    int Data;
    struct snode * next;
};

struct snode *Head;
struct snode *Tail;

//initialize an empty list
void emptylist(struct snode *s){
printf("Empty List");
}



//create node
struct snode * createnode(int data){
struct snode *ptr =NULL;
ptr=(struct snode *)malloc(sizeof(struct snode));
if (ptr)
	{
		ptr->Data = data;
		ptr->next = NULL;
 }
}
//End
//insert NewNode
int AddNode(int data,struct snode *ptr)
{
	int retval = 0;
	ptr = createnode(data);
	if (ptr)
	{
		if (Head == NULL)
		{
			Head = ptr;
			Tail = ptr;
		}
		else
		{
			Tail->next = ptr;
			Tail = ptr;
		}
		retval = 1;

	}
	return retval;
}
//End
//Create Node in First List
int AddNodeFirst(int data,struct snode *ptr)
{
	int retval = 0;
	struct snode * x =Head->next;
	ptr = createnode(data);
	if (ptr)
	{
		if (Head == NULL)
		{
			Head = ptr;
			Tail = ptr;
		}
		else
		{
		    ptr->next=Head;
		    Head=ptr;

			//ptr->
		//	Tail = ptr;
		}
		retval = 1;

	}
	return retval;
}
//End

//destroy a list node by node
void Destroynode(){

   struct snode * temp;
 //   temp=head->next;
   while(temp->next!=NULL){
    temp=temp->next;
    free(temp);
   }
}
//End
//print list
void printlist(struct snode *s){
    int i=0;
while(s){

    printf("Element %d is : %d \n",i, s->Data);
		s = s->next;
		i++;
}
printf("\nNumber of list is :%d \n",i);
}
//End
void mergetwolist(struct snode *s,struct snode *a){
while(s){
    s=s->next;
}
s->next=a;
}
//ENd
//Get the max value in list
void getmax()
{
   // ptr=Head;
   struct snode * temp=Head;

int max=temp->Data;

if (temp !=NULL){
while(temp){
        temp=temp->next;

if(max< temp->Data){
max=temp->Data;
}
  temp=temp->next;
}

printf("The Max in list is :%d\n",max);
}
}
//ENd

//Get the min value in list
void getmin()
{

int min;
struct snode * temp=Head;
min=temp->Data;

if (temp !=NULL){
while(temp){
        temp=temp->next;

if(min> temp->Data){
    min=temp->Data;
}
  temp=temp->next;
}

//printf("The Min in list is :%d\n",min);

printf("The Min in list is :%d\n",min);

}
}
//ENd
/* Function to reverse the linked list */
  void reverse()
{
	struct snode* prev = NULL;
	struct snode* current = Head;
	struct snode* next = NULL;
	while (current != NULL) {
		// Store next
		next = current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	Head = prev;
	printf("reverse List ...\n");
    while(Head){

         printf("Element  is : %d \n", Head->Data);
		Head = Head->next;
    }
}
//ENd


int main(){
struct snode * ptr;
struct snode * ps;
AddNode(95,ptr);

AddNode(71,ps);

AddNode(7,ptr);
AddNode(5,ptr);
AddNode(51,ptr);
AddNodeFirst(110,ptr);
struct snode *a = Head;
struct snode * b =Head;
b=a;
//structe
printf("List NO1\n");
	 printlist(a);
//printf("List NO2\n");
	// printlist(b);


	// mergetwolist(a,b);
//	 printlist(a);




	// getmin();
  //  getmax();
    //    getmax();
        reverse();
	// getmaxa(a);
}
