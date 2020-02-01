/**
*    Stack using a linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node
{
    int num;
    struct node *next;
};

struct node *createNode()
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    return n;
}


void push(struct node **s)
{
    struct node *n;
    n = createNode();
    if(n == NULL)
    {
        printf("No memory allocation\n");
    }
    printf("Enter data in Node\n");
    scanf("%d",&n->num);

    if(*s == NULL)
    {
        printf("First Node added to stack\n");
        n->next = *s;
        *s = n;
    }
    else
    {
        printf("Node added to stack\n");
        n->next = *s;
        *s = n;
    }
}

int isEmpty(struct node *s)
{
    return (s == NULL);
}


void pop(struct node **s)
{
    struct node *temp;
    if(isEmpty(*s))
        printf("Stack is empty\n");
    else
    {
        temp = *s;
        *s = temp->next;
        printf("popped value is %d\n",temp->num);
        free(temp);
    }
}

void peek(struct node **s)
{
    if(isEmpty(*s))
        printf("Stack is Empty\n");
    else
        printf("Peek value is %d\n",(*s)->num);
}


int main()
{
    struct node *startStack = NULL;
    int choice;

    while(1)
    {

        printf("/**************************************************************/\n\n");
        printf("1.Push data to stack\n");
        printf("2.Pop data from stack\n");
        printf("3.Peek value of stack\n");
        printf("4.exit\n");

        printf("choose operation\n");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : push(&startStack);     break;
            case 2 : pop(&startStack);      break;
            case 3 : peek(&startStack);    break;
            case 4 : exit(0);                      break;
            default :   printf("Choose valid operation\n");
        }
    }
}