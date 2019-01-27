#include<stdio.h>
#include<conio.h>
void main()
{
int n,a[100],i,j,min,s,pos;
clrscr();
printf("enter the no of elements");
scanf("%d",&n);
printf("enter the numbers");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
min=a[i];
pos=i;
for(j=i+1;j<n;j++)
{
if(a[j]<min)
{
min=a[j];
pos=j;
}
}
s=a[i];
a[i]=a[pos];
a[pos]=s;

}
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
getch();
}
