#include<stdio.h>
#include<conio.h>
int y,num,x,s[5],size=5,sp=-1;
void push(int );
int pop();
void top();
void main()
{
while(1)
{
 clrscr();
printf("1.PUSH\n2.POP\n3.TOP\n0.Exit\n");
printf("\n\nSelect Option : ");
scanf("%d",&num);
switch(num)
{
case 1:
printf("enter the element :");
scanf("%d",&x);
push(x);
break;
case 2:
y=pop();
printf("popped element:%d",y);
break;
case 3:
top();
break;
case 0:
exit(0);
break;
default:
printf("\n\nInvalid Option ");
}
getch();
}
}
void push(int a)
{
sp++;
if(sp==size)
{
printf("stack overflow");
sp--;
}
else
{
s[sp]=a;
}
}
int pop()
{
y=s[sp];
if(sp==-1)
{
printf("stack empty");
return ;
}
else
{
sp--;
return y;
}
}
void top()
{
printf("top element :%d",s[sp]);
}

