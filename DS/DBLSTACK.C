#include<stdio.h>
#include<conio.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void top1();
void top2();
int s1=-1,s2=10,a[10],x1,x2,y1,y2,op;
void main()
{
while(1)
{
clrscr();
printf("1.PUSH1\n2.PUSH2\n3.POP1\n4.POP2\n5.TOP1\n6.TOP2 \n 0.EXIT\n");
printf("select an option:");
scanf("%d",&op);
switch(op)
{
case 1:
printf("enter the element :");
scanf("%d",&x1);
push1(x1);
break;
case 2:
printf("enter the element :");
scanf("%d",&x2);
push2(x2);
break;
case 3:
y1=pop1();
printf("popped element of1 :%d",y1);
break;
case 4:
y2=pop2();
printf("popped elementof 2 :%d",y2);
break;
case 5:
top1();
break;
case 6:
top2();
break;
case 0:
exit(0);
break;
default :
printf("invalid option");
}
getch();
}
}

void push1(int x1)
{
if(s1<s2-1)
{
s1++;
a[s1]=x1;
}
else
{
printf("stack overflow");
}
}
void push2(int x2)
{
if(s1<s2-1)
{
s2--;
a[s2]=x2;
}
else
{
printf("stack overflow");
}
}

int pop1()
{
if(s1>=0)
{
y1=a[s1];
s1--;
return y1;
}
else
{
printf("stack empty");
}
}
int pop2()
{
if(s2<10)
{
y2=a[s2];
s2++;
return y2;
}
else
{
printf("stack empty");
}
}
void top1()
{
printf("top element of 1 is:%d",a[s1]);
}
void top2()
{
printf("top element of 2 is:%d",a[s2]);
}



