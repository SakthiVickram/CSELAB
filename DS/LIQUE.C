#include<stdio.h>
#include<conio.h>
#define size 5

int q[size],front=-1,rear=-1,x,y;
void enqueue(int);
void dequeue();
void display();

void main()
{
while(1)
{
int op;
clrscr();
printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
printf("enter the option :");
scanf("%d",&op);
switch(op)
{
case 1:
printf("enter the element to be inserted:");
scanf("%d",&x);
enqueue(x);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
case 5:
printf(" f:%d r:%d",front,rear);
break;
default:
printf("invalid option");
break;
}
getch();
}
}

void enqueue(int x)
{
printf("element inserted");
if(rear==size-1)
{
printf("queue is full");
return;
}
if(front==-1)
front=0;
rear++;
q[rear]=x;
}

void dequeue()
{

if(front==-1)
{
printf("queue is empty");
return;
}
if(front==rear)
{
printf("element removed is %d",q[front]);
front=-1;
rear=-1;
return;
}
printf("element removed is %d",q[front]);
front++;
}

void display()
{
int fp=front,rp=rear;
if(front==-1)
{
printf("queue is empty");
return;
}
while(fp<=rp)
{
printf(" %d ",q[fp]);
fp++;
}
}
