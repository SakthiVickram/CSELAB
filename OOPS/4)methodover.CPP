#include<iostream>
#include<conio.h>
using namespace std;
inline void display(int capacity,int ram,int screen )
{
cout<<"capacity:"<<capacity<<endl;

cout<<" ram size:"<<ram<<endl;

cout<<"screen resolution:"<<screen<<endl;
}

void getspecification(int capacity,int ram,int screen,char os[],char processor[],char graphicscard[])
{
cout<<"capacity:";
cin>>capacity;
cout<<" ram size:";
cin>>ram;
cout<<"screen resolution:";
cin>>screen;
cout<<"operating system: ";
cin>>os;
cout<<"processor:";
cin>>processor;
cout<<"graphics card:";
cin>>graphicscard;
for(int i=0;i<110;i++)
cout<<"_";
cout<<"function overloading (int)"<<endl;
display(capacity,ram,screen);
}
void display(char a[],char b[],char c[])
{

cout<<"operating system: "<<a<<endl;

cout<<"processor:"<<b<<endl;

cout<<"graphics card:"<<c<<endl;

}
char* returnarr(char p[])
{
//cout<<"processor"<<p;
return p;
}


int main()
{

int capacity,ram,screen;
char os[10],processor[15],graphicscard[10];
char *ptr;
//clrscr();
getspecification(capacity,ram,screen,os,processor,graphicscard);
//printspecification();

cout<<"function overloading(char)"<<endl;
display(os,processor,graphicscard);
ptr=returnarr(processor);

//for(ptr=0;*ptr!='\0';ptr++)
//{
cout<<"return from array"<<endl;
cout<<ptr;
//}
//getch();
return 0;
}

