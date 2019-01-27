#include<stdio.h>
#include<conio.h>
#define size 5

int q[size],front=-1,rear=-1,x,i,j,no[5]={1,2,3,4,5},ptr=0;
void enqueue(int);
void dequeue(int);
void display();
void round();


void main()
{
/*i=0,j=1;
while(i<size)
{
no[i]=j;
i++;
j++;
} */

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
dequeue(x);
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
//printf("element inserted\n");
rear=(rear+1)%size;
q[rear]=x;
}

void dequeue(int c)
{

if(front==-1)
{
printf("queue is empty");
return;
}
if(front==rear)
{
//printf("element removed is %d",q[front]);
front=-1;
rear=-1;
return;
}
//printf("element removed is %d",q[front]);
front=(front+1)%size;
ptr=(ptr+1)%(c+1);
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
int s=3,bal,pos,i,c=4;

while(front!=-1)
{
bal=q[front]-s;

if(bal<=0)
{
printf("Job No %d Completed\n",no[ptr]);
dequeue(c);
ptr=ptr-1;
for(i=ptr;i<c;i++)
{
no[i]=no[i+1];
}
c--;
/*for(i=0;i<=c;i++)
{
printf("no arrary elem:%d\t",no[i]);
} */

}
else
{
printf("Job No %d Waiting\n",no[ptr]);
dequeue(c);
enqueue(bal);
}
}
//for(i=0;i<size;i++)
//{
//printf("3 no arrary elem:%d",no[i]);
//}

}