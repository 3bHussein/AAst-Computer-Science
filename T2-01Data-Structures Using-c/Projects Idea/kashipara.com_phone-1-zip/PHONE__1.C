#include<stdio.h>
#include<conio.h>
struct phoneDir
{
  char userName[30];
  char userMobile[10];
};
int main()
{
struct phoneDir dir[100];
int i,ch;
int count=0;
int n;
char search_name[20];
char search_mobile[20];
clrscr();

do
{
printf("1.Add Contacts\n");
printf("2.Edit Contact\n");
printf("3.Delete Contact\n");
printf("4.Search Contact\n");
printf("5.Display Contact\n");
printf("0.Exit\n");
printf("Enter Your Choice\n");
scanf("%d",&ch);
//Adding Contact
if(ch==1)
{
printf("Enter how many contact you want to save??\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter UserName\n");
fflush(stdin);
gets(dir[i].userName);
printf("Enter UserMobile\n");
fflush(stdin);
gets(dir[i].userMobile);
count++;
}
if(count>0)
{
printf("Contact Saved!!!!\n");
printf("=======================\n");
}
else
{
printf("Contact Not Saved!!!!");
}
printf("===================\n");
}
//Edit Contact
else if(ch==2)
{
printf("Enter name to search contact\n");
fflush(stdin);
gets(search_name);
printf("%s\n",search_name);
for(i=0;i<n;i++)
{
if(strcmp(dir[i].userName,search_name)==0)
{
printf("Enter New Name\n");
fflush(stdin);
gets(dir[i].userName);
printf("Enter New Mobile No.\n");
fflush(stdin);
gets(dir[i].userMobile);
printf("Contact Updated!!!");
printf("========================\n");
}
}
}
//Deleting Contact
else if(ch==3)
{
int found=0;
int index=0;
 printf("Enter name to search\n");
 fflush(stdin);
 gets(search_name);
 for(i=0;i<n;i++)
 {
   if(strcmp(dir[i].userName,search_name)==0)
   {
   found=1;
    index=i;
   }
 }
 if(found==1)
 {
 for(i=found;i<n-1;i++)
 {
  dir[i]=dir[i+1];
 }
 printf("Contact Deleted\n");
 printf("======================\n");
 for(i=0;i<n-1;i++)
 {
printf("%s\t%s\t\n",dir[i].userName,dir[i].userMobile);
 }
 n--;
 printf("===========================\n");
 }
 else
 {
 printf("Contact Not Deleted");
 }
}

//Searching contact
else if(ch==4)
{
 int sb_choice;
 int count_search=0;
 printf("1.search by name\n");
 printf("2.search by number\n");
 scanf("%d",&sb_choice);
 if(sb_choice==1)
 {
  char srch_name[20];
  printf("Enter name to search\n");
  fflush(stdin);
  gets(srch_name);
  for(i=0;i<n;i++)
  {
    if(strcmp(dir[i].userName,srch_name)==0)
    {
     count_search++;
     printf("%s\t%s\t\n",dir[i].userName,dir[i].userMobile);
     printf("============================\n");
    }
  }
  if(count_search==0)
  {
   printf("no data found\n");
  }
 }
 else if(sb_choice==2)
 {
 char search_number[12];
  printf("Enter number to search\n");
  fflush(stdin);
  gets(search_number);
  for(i=0;i<n;i++)
  {
    if(strcmp(dir[i].userMobile,search_number)==0)
    {
       count_search++;
       printf("%s\t%s\t\n",dir[i].userName,dir[i].userMobile);
       printf("========================\n");
    }
  }
  if(count_search==0)
  {
   printf("No contact found");
  }

 }
}
//Displaying Contact
else if(ch==5)
{
for(i=0;i<n;i++)
{
printf("%s\t%s\t\n",dir[i].userName,dir[i].userMobile);
printf("===============================\n");
}
}
else if(ch==0)
{exit(0);
}
}

while(ch!=8);
getch();
return 0;
}