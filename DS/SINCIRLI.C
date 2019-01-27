#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void append(int);
void addbeg(int);
void addafter(int,int);
void display();
void delnode(int);
int count();
void reverse();
struct node
{
int data;
struct node *next;
};
struct node *head;
void main()
{

 int op,num,loc;
 clrscr();
 head=NULL;
printf("enter the option:\n");
printf("1.append 2.addbeg 3.addafter 4.display 5.delnode 6.exit 7.reverse\n ");

while(1)
{

scanf("%d",&op);
switch(op)
{
case 1:
printf("enter the element for append:");
scanf("%d",&num);
append(num);
break;
case 2:
printf("enter the element to be inserted in the beginning:");
scanf("%d",&num);
addbeg(num);
break;
case 3:
printf("enter the element and location to be inserted:");
scanf("%d %d",&num,&loc);
addafter(num,loc);
break;
case 4:
display();
break;
case 5:
printf("enter the element to be deleted");
scanf("%d",&num);
delnode(num);
break;
case 6:
exit(0);
case 7:
reverse();
break;
}
getch();
}
}




void append(int num)
{
struct node *temp,*r;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
r=head;
  if(head==NULL)
  {
  head=temp;
  head->next=head;
  }
  else
  {
  while(r->next!=head)
  r=r->next;
  temp->next=head;
  r->next=temp;
  }
}

void addbeg(int num)
{
struct node *temp,*r;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
r=head;
while(r->next!=head)
r=r->next;


if(head==NULL)
  {
  head=temp;
  head->next=head;
  }
else
  {
  temp->next=head;
  head=temp;
  r->next=head;
  }

}

void addafter(int num,int loc)
{
int i,c;
struct node *temp,*pre,*cur;
cur=head;
  // c=count();
  // printf("count answer:%d",c);
  if(loc>count()||loc<0)
  {
  printf("insertion is not possible");
  return;
  }

if(loc==0)
{
addbeg(num);
return;
}
else
{
  for(i=1;i<=loc;i++)
  {
  pre=cur;
  cur=cur->next;
  }

temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
pre->next=temp;
temp->next=cur;
return;

}
}

void display()
{
struct node *temp=head;
printf("List is:");
while(temp->next!=head)
{
printf("%d ",temp->data);
temp=temp->next;
}
printf("%d ",temp->data);
}


int count()
{
int s=1;
struct node *temp=head;
while(temp->next!=head)
{
s++;
temp=temp->next;
}

return s;
}



void delnode(int num)
{
struct node *pre,*cur;
cur=head;
while (cur!=NULL)
{
if(cur->data==num)
{
  if(cur==head)
  {
  head =cur->next;
  free(cur);
  return;
  }
  else
  {
  pre->next=cur->next;
  free(cur);
  return;
  }
}
  else
  {
  pre=cur;
  cur=cur->next;
  }
}
printf("The list is empty element not found");
}

void reverse()
{
struct node *cur,*pre,*temp;
cur=head;
pre=NULL;
while(cur->next!=head)
{
temp=cur->next;
cur->next=pre;
pre=cur;
cur=temp;
}
head=pre;
}
