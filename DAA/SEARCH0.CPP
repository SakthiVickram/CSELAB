#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
class search
{
private:
int a[100],s,size,f,l,r,m,x;
public:
void linear();
int binary();
void get();
void sort();
};
void search::sort()
{
int temp,i,j;
for (i = 1; i < size; i++)      //moving from left to right in unsorted array 1 to n-1
   {
      temp = a[i];                  //element to be moved into sorted portion
      j = i;
      while ((temp < a[j-1]) && (j >0))      //moving from right to left in sorted array
      {
	 a[j] = a[j-1];                     //shift right
	 j = j - 1;
      }
      a[j] = temp;
   }
   cout<<"sorted array";
   for(i=0;i<size;i++)
   cout<<" "<<a[i];
}
void search::linear()
{
cout<<"Enter the element to search:"<<endl;
cin>>s;
for(int i=0;i<size;i++)
{
f=0;
if(a[i]==s)
{
f=1;
cout<<"Element found"<<endl;
break;
}
}
if(f==0)
cout<<"Element not found"<<endl;
}

int search::binary()
{
cout<<"Enter the element to search";
cin>>x;
l=0;
r=size-1;
 while(l<=r)
 {
 m=l+(r-l)/2;
 //cout<<m;
 if(a[m]==x)
 return m;
 if(a[m]<x)
 l=m+1;
 else
 r=m-1;
 }
return -1;
}

void search::get()
{
cout<<"Enter the size:"<<endl;
cin>>size;
cout<<"Enter the elements:"<<endl;
for(int i=0;i<size;i++)
cin>>a[i];
}

void main()
{
int ch,v;
clock_t start,stop;
double timetaken;
search ob;
clrscr();
while(1)
{
cout<<"1.linear 2.binary 0.exit";
cin>>ch;
switch(ch)
{
case 1:
//cout<<"case 1:";
ob.get();
ob.sort();
start=clock();
ob.linear();
stop=clock();
break;
case 2:
//ob.get();
start=clock();
v=ob.binary();
if(v==-1)
cout<<"Element not found"<<endl;
else
cout<<"Element found"<<endl;
stop=clock();
break;
case 0:
exit(1);
}
timetaken=(double)(stop-start)/CLOCKS_PER_SEC;
cout<<"time taken"<<timetaken;
getch();
}
}