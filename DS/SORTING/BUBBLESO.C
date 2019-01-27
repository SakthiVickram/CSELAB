#include<stdio.h>
#include<conio.h>
void main()
{
int s,i,j,a[100],n;
clrscr();
printf("enter the no of elements");
scanf("%d",&n);
printf("enter the numbers");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
  s=a[j];
  a[j]=a[j+1];
  a[j+1]=s;
}
}
}
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
getch();
}
