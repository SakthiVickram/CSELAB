#include<stdio.h>
#include<conio.h>
#include "fact.h"
void main()
{
int n;
long ans;
clrscr();
printf("Enter the number:");
scanf("%d",&n);
ans=factorial(n);
printf("factorial of %d is %d",n,ans);
getch();
}
