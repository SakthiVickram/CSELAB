#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 10
int w,i,len,sp=-1,k,res;
char y,a[size],ch[15],exp[15],o1p,o2p;
void push(char);
char pop();
char top();
int isoperand(char);
int isoperator(char);
int weight(char);
int checkprecedence(char,char);
int sempty();
void operation(char,int,int);
void main()
{
clrscr();
  printf("enter the infix expression");
  gets(exp);

  for(len=0;exp[len]!='\0';len++);
  printf("length of expression:%d\n",len);
for(i=0,k=-1;i<len;++i)
 {
   if(isoperand(exp[i]))
   {
   printf("%d.operand\n",i);

 exp[++k]=exp[i];
   }
   else if(exp[i]=='(')
   {
   push(exp[i]);
   }
   else if(exp[i]==')')
   {

   while( !sempty()  &&  top()!='(' )
   {
   exp[++k]=pop();
   pop();
   }
   pop();
   }


   else //if(isoperator(exp[i]))
  {
  printf("%d.operator\n",i);
  while( !sempty() && exp[i]!='(' && checkprecedence(top(),exp[i]))
    {

   exp[++k]=pop();
    }

    push(exp[i]);
    }
}
while( !sempty())
{
exp[++k]=pop();
}
exp[++k]='\0';

printf("postfix expression:%s\n",exp);



for(i=0;exp[i]!='\0';i++)
{
if (isoperand(exp[i]))
{

push(exp[i]);
printf("%d.operand:%c\n",i,exp[i]);
}
else if(isoperator(exp[i]))
{

o1p=pop();
o2p=pop();

printf("%d %c %d \n",o2p-48,exp[i],o1p-48);
operation(exp[i],o1p,o2p);
}
}

getch();
}



int isoperand(char c)
{
if(c>='0' && c<='9')
return 1;
if(c>='a' && c<='z	')
return 1;
if(c>='A' && c<='z')
return 1;
return 0;
}


int isoperator(char c)
{
if(c=='+'|| c=='-' || c=='*' || c=='/')
return 1;
else
return 0;
}


int weight(char op)
{
int w=-1;
switch(op)
{
case '+':
case '-':
w=1;
break;
case '*':
case '/':
w=2;
break;
}
return w;
}


int checkprecedence(char op1,char op2)
{
int op1w=weight(op1);
int op2w=weight(op2);
if(op1w>=op2w)
return 1;
else
return 0;
}

int sempty()
{
if(sp==-1)
return 1;
else
return 0;
}

void push(char x)
{
sp++;
if(sp==size)
{
printf("stack full");
sp--;
}
else
{
a[sp]=x;
}
}

char pop()
{

y=a[sp];
if(sp==-1)
{
//printf("stack empty");
}
else
{
sp--;
return y;
}
}


char top()
{
return a[sp];
}

void operation(char c,int e,int d)
{

      d=d-48;
      e=e-48;
switch(c)
{
case '+':
res=d+e;
break;
case '-':
res=d-e;
break;
case '*':
res=d*e;
break;
case '/':
res=d/e;
break;
}

printf("final answer: %d\n",res);
res=res+48;
push(res);
}


