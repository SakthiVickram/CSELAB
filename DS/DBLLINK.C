#include <stdio.h>
#include <conio.h>
void createlist(int);
void addbeg(int);
void addafter(int,int);
void delnode(int);
void display();
void reverse();
int count();
struct node
{
struct node *pre;
int data;
struct node *next;
}*head;
void main()
{
int n,m,po,i,ch;
head=NULL;
clrscr();
printf("1.createlist\n2.addbeg\n3.addafter\n4.delete\n5.display\n6.reverse\n7.exit\n");
printf("enter the choice:\n");
while(1)
{
scanf("%d",&ch);
switch(ch)
 {
 case 1:
 printf("enter no.of nodes \n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
    {
    printf("enter the element \n");
    scanf("%d",&m);
    createlist(m);
    }
 break;
 case 2:
 printf("enter the element \n");
 scanf("%d",&m);
 addbeg(m);
 break;
 case 3:
 printf("enter the position after which the element is to be entered \n");
 scanf("%d",&po);
 printf("enter the element \n");
 scanf("%d",&m);
 addafter(m,po);
 break;
 case 4:
 printf("enter the element to be deleted \n");
 scanf("%d",&m);
 delnode(m);
 break;
 case 5:
 display();
 break;
 case 6:
 reverse();
 break;
 case 7:
 exit(0);
 break;
 }
 getch();
 }
 }
void createlist(int m)
{
struct node *q,*temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=m;
temp->next=NULL;
temp->pre=NULL;
 if(head==NULL)
 {
    temp->pre=NULL;
    head=temp;
 }
 else
 {
    q=head;
    while(q->next!=NULL)
    {
       q=q->next;
    }
    q->next=temp;
    temp->pre=q;
 }
}
void addbeg(int m)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=m;
temp->next=head;
head->pre=temp;
temp->pre=NULL;
head=temp;
}
void addafter(int m,int po)
{
struct node *temp,*q;
int i;
q=head;
for(i=1;i<po;i++)
{
   q=q->next;
   if(q==NULL)
   {
   printf("the list is empty \n");
   return;
   }
}
temp=(struct node *)malloc(sizeof(struct node));
temp->data=m;
q->next->pre=temp;
temp->next=q->next;
temp->pre=q;
q->next=temp;

}
void delnode(int m)
{
struct node *temp,*q;
//removing first node
if(head->data==m)
{
   temp=head;
   head=head->next;
   head->pre=NULL;
   free(temp);
   return;
}
q=head;
//removing in-between nodes
while(q->next->next!=NULL)
{
   if(q->next->data==m)
   {
   temp=q->next;
   q->next=temp->next;
   temp->next->pre=q;
   free(temp);
   return;
   }
  q=q->next;
}
//removing last node
if(q->next->data==m)
{
   temp=q->next;
    free(temp);
     q->next=NULL;
     return;
}
}
void reverse()
{
struct node *p1,*p2;
p1=head;
p2=p1->next;
p1->next=NULL;
p1->pre=p2;
 while(p2!=NULL)
 {
    p2->pre=p2->next;
    p2->next=p1;
    p1=p2;
    p2=p2->pre;
 }
head=p1;
}
void display()
{
struct node *temp=head;
printf("List is:");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}

}

int count()
{
int s=1;
struct node *temp=head;
while(temp->next!=NULL)
{
s++;
temp=temp->next;
}

return s;
}










