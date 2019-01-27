#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
class search
{
private:
int a[100],s,size,f,l,r,m;
public:
void linear();
int binary();
void get();
};

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
cin>>s;
l=0;
r=size-1;
 while(l<=r)
 {
 m=l+(r-l)/2;
 //cout<<m;
 if(a[m]==s)
 return m;
 if(a[m]<s)
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
//cout<<"Enter the element to search:"<<endl;
//cin>>s;
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
start=clock();
//delay(4000);
ob.linear();
stop=clock();
break;
case 2:
ob.get();
start=clock();
v=ob.binary();
if(v==-1)
cout<<"Element not found"<<endl;
else
cout<<"Element found"<<endl;
//delay(4000);
stop=clock();
break;
case 0:
exit(1);
}
timetaken=(double)(stop-start)*1000/(CLOCKS_PER_SEC);
cout<<"time taken"<<timetaken;
getch();
}
}