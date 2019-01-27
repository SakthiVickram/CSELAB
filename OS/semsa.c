#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
void producer();
void consumer();
int wait(int);
int signal(int);
int main()
{i
nt n;
printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
while(1)
{p
rintf("\nENTER YOUR CHOICE\n");
scanf("%d",&n);
switch(n)
{c
ase 1:
if((mutex==1)&&(empty!=0))
producer();
else
printf("BUFFER IS FULL");
break;
case 2:
if((mutex== 1)&&(full!=0))
consumer();
else
printf("BUFFER IS EMPTY");
break;
Page 1
semaphores.c
case 3:
exit(0);
break;
}}}i
nt wait(int s)
{r
eturn(--s);
}i
nt signal(int s)
{r
eturn(++s);
}v
oid producer()
{m
utex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\nproducer produces theitem%d",x);
mutex=signal(mutex);
}v
oid consumer()
{m
utex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("\n consumer consumes item%d",x);
x--;
mutex=signal(mutex);
}