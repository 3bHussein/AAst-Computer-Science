# -Data-Structures-using-C

                                            This Frist File in This REPOSITORIES


                                                AAst reference Point
https://drive.google.com/drive/folders/1ieIlDsVhrT_wxeeGJtZgPYnIQDrNS__j?usp=sharing

    //**************************************************************<br>
    //All Operation with Any LinkedList:<br>
    //1-Create,Initialize New List<br>
    //2-Create New Node<br>
    //3-Insert Node into Tail<br>
    //4-Insert Node into Head<br>
    //5-Insert Node into n Position<br>
    //6-Display List<br>
    //7-Destroy a List node by node<br>
    //8-Make A Copy into New List <br>
    //9-Count a Number in List<br>
    //10-Find The Max,min,average in List<br>
    //11-Move Node To n Position<br>
    //12-Swap Two Node (With Move Data)<br>
    //13-Swap Two Node (without Move Data)<br>
    //14-Reverse List<br>
    //15-Concatenate Two LikedList<br>
    //16-Combine Two Sort List into New List<br>
    //17-Check if a List is Sort<br>
    //18-Check if a  Circular double List is Sort<br>
    //19-Display all element above the Average in List<br>
    //20-Insert into Sort List <br>
    //21-Display All prime element in List<br>
    //22-Check if a circular is mirror or not<br>
    //23-Dispose a double List<br>

<br>


    //**************************************************************<br>
    //All Operation with Any Stack:<br>
    //1-Create,Initialize New Stack<br>
    //2-Find The Max,min,average in Stack<br>
    //3-Check if two Stack are equal<br>
    //4-check if two Stack are reverse<br>
    //5-check if the sum of the upper half of a Stack is the same as the sum of the lower half<br>

<br>









# Singly LinkedList
    #include<stdio.h>
    #include<stdlib.h>
    #include<conio.h>
    //Create Single List
    typedef struct node{
    int Data;
    struct node *next;}

    //Head,Tail Abstract or Global Variable
    *Head,*Tail;

    //Create New Node
    struct node * Createsnode(int data){
        struct node * ptr=NULL;
        ptr=(struct node *)mallco(sizeof(struct node));
        if(ptr){
            ptr->Data=data;
            ptr->next=NULL;
        }
        return ptr;
    }

    //Insert Node into Tail
    void insertIntoTail(int data,struct node * ptr){   
        ptr=Createsnode(data);
        if(ptr){
            if(Head==NULL){
                Head=Tail=ptr;
            }
            else{
                Tail->next=ptr;
                ptr->next=Tail;
                Tail=ptr;
            }
           
        }
        }
    //4-Insert Node  into Head
    void insertIntoHead(int data,struct node * ptr){
        ptr=Createsnode(data);
        if(ptr){
            if(Head==NULL){
                Head=Tail=ptr;
            }
            else{
                ptr->next=Head;
                Head=ptr;
            }
        }
    }

    //5-Insert into n Position
    void insertIntoPositions(int data,struct node * ptr,int location){
        int i;
        struct node * temp=NULL;
        struct node * ptr=NULL;
        ptr=Createsnode(data);
        if(ptr){
            if(Head==NULL){
                Head==Tail=ptr
            }
           else if(location==0){
            ptr->next=Head;
            Head=ptr;   
            }

            else{
                temp=Head;
                for(i=0;i<location-1;i++){
                    temp=temp->next;
                }
                ptr->next=temp->next;
                temp->next=ptr;
            }
        }}

    //6-Display List

    void DisplayList (struct node * s){
        int i=0;
        if(s){
            while(s){
            printf("Element %d is : %d \n",i, s->Data);
            s = s->next;
            i++;
            }
        }
    }

    






<Br>


                                                  # Reverse Singly linked list
                                                  
![RGIF2](https://user-images.githubusercontent.com/39864308/73269719-04617200-41e6-11ea-8cfc-00130779ddac.gif)
