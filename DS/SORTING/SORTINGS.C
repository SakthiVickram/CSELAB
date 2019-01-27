#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mergesort(int[],int,int);
void merge(int[],int,int,int);
void quicksort(int [],int,int);
int partition(int [],int,int);
void shellsort(int[],int);

void main()
{

int arr[100],n,i,op,j,temp;
while(1)
{
clrscr();
printf("enter the option:\n1.mergesort 2.quicksort 3.shellsort 4.insertion 5.selection 6.bubble");
scanf("%d",&op);
printf("enter the number of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("Array is:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
switch(op)
{
case 1:
mergesort(arr,0,n-1);
printf("The sorted array is:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
break;
case 2:
quicksort(arr,0,n-1);
printf("the sorted elements are:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
break;
case 3:
shellsort(arr,n);
case 4:

 for (i = 1; i < n; i++)      //moving from left to right in unsorted array 1 to n-1
   {
      temp = arr[i];                  //element to be moved into sorted portion
      j = i;
      while ((temp < arr[j-1]) && (j >0))      //moving from right to left in sorted array
      {
	 arr[j] = arr[j-1];                     //shift right
	 j = j - 1;
      }
      arr[j] = temp;
   }

   printf("the sorted elements are:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);

break;
case 5:
{
int s,pos,min;

for(i=0;i<n;i++)
{
min=arr[i];
pos=i;
for(j=i+1;j<n;j++)
{
if(arr[j]<min)
{
min=arr[j];
pos=j;
}
}
s=arr[i];
arr[i]=arr[pos];
arr[pos]=s;
}
printf("the sorted elements are:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
}
break;
case 6:
{
int s;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(arr[j]>arr[j+1])
{
  s=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=s;
}
}
}
printf("the sorted elements are:");
for(i=0;i<n;i++)
printf("%d ",arr[i]);
}
break;
case 7:
exit(0);
break;
}
getch();
}
}

void mergesort(int arr[],int l,int r)
{
if(l<r)
{
int m=l+(r-l)/2;
mergesort(arr,l,m);
mergesort(arr,m+1,r);

merge(arr,l,m,r);
}
}

void merge(int arr[],int l,int m,int r)
{
int i,j,k;

int n1=m-l+1;
int n2=r-m;
int l1[10],r1[10];

for(i=0;i<n1;i++)
{
l1[i]=arr[l+i];
}
for(j=0;j<n2;j++)
{
r1[j]=arr[m+1+j];
}
 i=0;
 j=0;
 k=l;
while(i<n1 && j<n2)
{
if(l1[i]<=r1[j])
{
arr[k]=l1[i];
i++;
}
else
{
arr[k]=r1[j];
j++;
}
k++;
}
while(i<n1)
{
arr[k]=l1[i];
i++;
k++;
}
while(j<n2)
{
arr[k]=r1[j];
j++;
k++;
}

}
void shellsort(int arr[], int n)
{
     int gap,i;
for ( gap = n/2; gap > 0; gap /= 2)
{

for (i = gap; i < n; i += 1)
{

int temp = arr[i];


int j;
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
	arr[j] = arr[j - gap];

arr[j] = temp;
	}
	}

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
















