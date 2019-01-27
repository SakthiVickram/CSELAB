#include<stdio.h>
#include<conio.h>
#define size 5

int q[size],front=-1,rear=-1,x,i;
void enqueue(int);
void dequeue();
void display();
void round();

void main()
{
while(1)
{
int op;
clrscr();
printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n6.round");
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
case 6:
round();
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
if((rear+1)%size==front)
{
printf("queue is full");
return;
}
if(front==-1)
front=0;
printf("element inserted\n");
rear=(rear+1)%size;
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
front=(front+1)%size;
}

void display()
{
int fp=front,rp=rear;
if(front==-1)
{
printf("queue is empty");
return;
}
else if(fp<=rp)
{
for(i=fp;i<=rp;i++)
  {
printf(" %d ",q[i]);
  }
}
else
{
while(fp<=size-1)
  {
printf(" %d ",q[fp]);
fp++;
  }
fp=0;
while(fp<=rp)
  {
printf("%d",q[fp]);
fp++;
  }
}
}

void round()
{
int s=2,bal;
while(front!=-1)
{
bal=q[front]-s;
dequeue();
if(bal<=0)
printf("task in %d completed",front);
else
enqueue(bal);
}

}