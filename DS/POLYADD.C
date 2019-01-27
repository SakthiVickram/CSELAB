#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void append(int,int,int);
void show(int*);
void polyadd();
struct node
{
int coeff;
int pow;
struct node *next;
}*h1,*h2,*h3;

void main()
{

//get the values of linked list 1
int co,po,i,c;
clrscr();
h1=h2=h3=NULL;
printf("1.append1\n2.append2\n3.polyadd\n4.exit\n");
while(1)
{
printf("enter the choice:");
scanf("%d",&c);
switch(c)
{
case 1:
{
printf("Link 1:\n");
printf("enter the coeff :\n");
scanf("%d",&co);
printf("enter the power:\n");
scanf("%d",&po);
append(co,po,1);
break;
}
//get the values of linked list 2
case 2:
{
printf("Link 2:\n");
printf("enter the coeff:\n");
scanf("%d",&co);
printf("enter the power:\n");
scanf("%d",&po);
append(co,po,2);
break;
}
case 3:
{
printf("Link 1:");
show(h1);
printf("Link 2:");
show(h2);
polyadd();
printf("Link 3:");
show(h3);
break;
}
case 4:
exit(0);
}
getch();
}
}

void append(int co,int po ,int no)
{
struct node *temp,*r;
temp=(struct node *)malloc(sizeof(struct node));

temp->coeff=co;
temp->pow=po;
if(no==1)
r=h1;
if(no==2)
r=h2;
if(no==3)
r=h3;

if(h1==NULL && no==1)
{
h1=temp;
h1->next=NULL;
}
else if(h2==NULL && no==2)
{
h2=temp;
h2->next=NULL;
}
else if(h3==NULL && no==3)
{
h3=temp;
h3->next=NULL;
}
else
{
while(r->next!=NULL)
r=r->next;
temp->next=NULL;
r->next=temp;
}
printf("exit append\n");
}

void show(int *h)
{
struct node *s=h;
while(s!=NULL)
{
printf("%dx^%d ",s->coeff,s->pow);
s=s->next;
}
printf("\n");
}


void polyadd()
{
int k,l,m,n;
struct node *s,*t;
s=h1,t=h2;

while(s!=NULL && t!=NULL )
{
if(s->pow > t->pow)
{
   k=s->coeff;
   m=s->pow;
   append(k,m,3);
   s=s->next;
 }
if(s->pow < t->pow)
{
 l=t->coeff;
 n=t->pow;
 append(l,n,3);
 t=t->next;
}
//s->pow==t->pow
else
{
   int u,v;
   u=s->coeff+t->coeff;
   v=s->pow;
  append(u,v,3);
  s= s->next;
  t= t->next;
}
}
while(s!=NULL)
{
append(s->coeff,s->pow,3);
s=s->next;
}
while(t!=NULL)
{
append(t->coeff,t->pow,3);
t=t->next;
}
}