#include<stdio.h>
#include<conio.h>
void quicksort(int [],int,int);
int partition(int [],int,int);

void main()
{
int arr[50],start,end,size,i;
clrscr();
printf("enter the no of elements:");
scanf("%d",&size);

for(i=0;i<size;i++)
scanf("%d",&arr[i]);

printf("the elements are:");
for(i=0;i<size;i++)
printf("%d",arr[i]);

quicksort(arr,0,size-1);

printf("the sorted elements are:");
for(i=0;i<size;i++)
printf("%d ",arr[i]);

getch();
}
void quicksort(int arr[],int start,int end)
{
int pindex;
if(start<end)
{
pindex=partition(arr,start,end);
quicksort(arr,start,pindex-1);
quicksort(arr,pindex+1,end);
}
}

int partition(int arr[],int start,int end)
{
int pivot,pindex,i,tmp;
pivot=arr[end];
pindex=start;
for(i=start;i<end;i++)
{
if(arr[i]<=pivot)
{
tmp=arr[i];
arr[i]=arr[pindex];
arr[pindex]=tmp;
pindex++;
}
}
tmp=arr[pindex];
arr[pindex]=arr[end];
arr[end]=tmp;
return pindex;
}