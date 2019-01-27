#include<stdio.h>
#include<conio.h>
#include<string.h>
#define size 10
int w,i,len,sp=-1,k;
char y,a[size],ch[15],exp[15];
void push(char);
char pop();
char top();
int isoperand(char);
int isoperator(char);
int weight(char);
int checkprecedence(char,char);
int sempty();
void main()
{
clrscr();
  printf("enter the infix expression");
  gets(exp);

  for(len=0;exp[len]!='\0';len++);
  printf("%d",len);
for(i=0,k=-1;i<len;++i)
 {
   if(isoperand(exp[i]))
   {
   printf("operand\n");
  // ch[i]=exp[i];
 // strcat(post,ch+i);
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
   //ch[i] = top();
   //strcat(post,ch);
   pop();
   }
   pop();
   }


   else //if(isoperator(exp[i]))
  {
  printf("operator\n");
  while( !sempty() && exp[i]!='(' && checkprecedence(top(),exp[i]))
    {
    //printf("is it working");
   //w=weight(exp[i]);
  //printf("%d",w);
 // ch[i] = top();
 // strcat(post,ch);
   exp[++k]=pop();
    }
    push(exp[i]);
    }
}
while( !sempty())
{
  //ch[i] = top();
 //strcat(post,ch);
exp[++k]=pop();
}
exp[++k]='\0';
puts(exp);
for(sp=0;sp<5;sp++)
printf("in stack:%c",a[sp]);
	/*scanf("%d",&x);
push(x);
printf("%d",a[sp]);
y=pop();
printf("%d",y); */



getch();
}



int isoperand(char c)
{
if(c>='0' && c<='9')
return 1;
if(c>='a' && c<='z')
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
char pop ()
{

y=a[sp];
if(sp==-1)
printf("stack empty");
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

