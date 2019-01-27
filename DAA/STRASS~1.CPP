#include<iostream.h>
#include<conio.h>


void main()
{
int a[2][2],b[2][2],c[2][2],i,j;
int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
int p1,p2,p3,p4,p5,p6,p7;

clrscr();
 cout<<"Enter the Matrix A"<<endl;
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
	cin>>a[i][j];
    }
}
cout<<"Enter the Matrix B"<<endl;
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
	cin>>b[i][j];
    }
}

s1=b[0][1] -b[1][1];
s2=a[0][0]+a[0][1];
s3=a[1][0]+a[1][1];
s4=b[1][0]-b[0][0];
s5=a[0][0]+a[1][1];
s6=b[0][0]+b[1][1];
s7=a[0][1]-a[1][1];
s8=b[1][0]+b[1][1];
s9=a[0][0]-a[1][0];
s10=b[0][0]+b[0][1];

p1=a[0][0]*s1;
p2=s2*b[1][1];
p3=s3*b[0][0];
p4=a[1][1]*s4;
p5=s5*s6;
p6=s7*s8;
p7=s9*s10;

c[0][0]=p5+p4-p2+p6;
c[0][1]=p1+p2;
c[1][0]=p3+p4;
c[1][1]=p5+p1-p3-p7;

cout<<" Matrix C"<<endl;
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
	cout<<c[i][j]<< " ";
    }
    cout<<endl;
}

getch();
}
