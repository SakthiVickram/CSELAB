#include<stdio.h>
#include<conio.h>

void mergesort(int[],int,int);
void merge(int[],int,int,int);

void main()
{

int arr[10],n,i,arr_size;
clrscr();
//printf("enter the number of elements:");
//scanf("%d",&n);
for(i=0;i<=9;i++)
scanf("%d",&arr[i]);
arr_size = sizeof(arr)/sizeof(arr[0]);
printf("size :%d",arr_size);
printf("Array is:");
for(i=0;i<9;i++)
printf("%d",arr[i]);

mergesort(arr,0,arr_size-1);

printf("The sorted array is:");
for(i=0;i<=9;i++)
printf("%d ",arr[i]);

getch();
}

void mergesort(int arr[],int l,int r)
{

printf("%d %d ",l,r);
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
for(j=0;i<n2;j++)
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















