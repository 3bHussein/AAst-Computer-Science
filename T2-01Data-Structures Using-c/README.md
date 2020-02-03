# -Data-Structures-using-C

                                            This Frist File in This REPOSITORIES


                                                AAst reference Point
https://drive.google.com/drive/folders/1ieIlDsVhrT_wxeeGJtZgPYnIQDrNS__j?usp=sharing

    //**************************************************************
    //All Operation with Any LinkedList:
    //1-Create,Initialize New List
    //2-Create New Node
    //3-Insert Node into Tail
    //4-Insert Node into Head
    //5-Insert Node into n Position
    //6-Display List
    //7-Destroy a List node by node
    //8-Make A Copy into New List Not Done
    //9-Count a Number in List
    //10-Find The Max,min,average in List
    //11-Move Node To n Position
    //12-Swap Two Node (With Move Data)
    //13-Swap Two Node (without Move Data)
    //14-Reverse List
    //15-Concatenate Two LikedList
    //16-Combine Two Sort List into New List
    //17-Check if a List is Sort
    //18-Check if a  Circular double List is Sort
    //19-Display all element above the Average in List
    //20-Insert into Sort List 
    //21-Display All prime element in List
    //22-Check if a circular is mirror or not
    //23-Dispose a double List

<br>


    //**************************************************************
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
        printf("The Numer Node in List is : %d",i);
    }

    //7-Destroy a List node by node<br>
    void Destroynode(struct node * temp){
      while(temp->next!=NULL){
       temp=temp->next;
       free(temp);
     }
    } 
    

    //9-Count a Number in List<br>
    void CountList(struct node *s){
        int i =0;
        if(s){
            while(s){
                s=s->next;
                i++;
            }
                    printf("The Numer Node in List is : %d",i);

        }
    }
     
     //10-Find The Max
    void Max(struct node * s){
        s=Head;
        int max =Head->Data;
        if(s!=NULL){
            while(s){
                if(s->Data>max){
                    max=s->Data;
                }
                s=s->next;
            }
        }
        printf("The Max Value in List is %d :,max);
    }

     //10-Find The min
    void Max(struct node * s){
        s=Head;
        int min =Head->Data;
        if(s!=NULL){
            while(s){
                if(s->Data<min){
                    max=s->Data;
                }
                s=s->next;
            }
        }
        printf("The Min Value in List is %d :,min);
    }







<Br>


                                                  # Reverse Singly linked list
                                                  
![RGIF2](https://user-images.githubusercontent.com/39864308/73269719-04617200-41e6-11ea-8cfc-00130779ddac.gif)
