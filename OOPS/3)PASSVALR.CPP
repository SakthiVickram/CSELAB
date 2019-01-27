#include<iostream>
#include<conio.h>
using namespace std;
void tax(float,float);
void tax2(float*,float *);
char *pass(char[],char[]);

int main()
{
float dell,lenovo;
char processor[15];
char os[15],*ptr;
cout<<"Enter the price of dell and lenovo:";
cin>>dell>>lenovo;
tax(dell,lenovo);
cout<<"After pass by values:"<<endl;
cout<<"price of dell" <<dell<<"  price of lenovo"<<lenovo<<endl;
tax2(&dell,&lenovo);
cout<<"After pass by reference:"<<endl;
cout<<"price of dell" <<dell<<"  price of lenovo"<<lenovo<<endl;
cout<<"Enter the processor "<<endl;
cin.ignore();
cin.getline(processor,15);
cout<<"enter the operating system"<<endl;
///cin.ignore();
cin.getline(os,15);
ptr=pass(processor,os);
cout<<"operating system :"<<ptr;
return 0;
}
void tax(float a,float b)
{
a=a+a*0.18;
b=b+b*0.18;
}
void tax2(float*d,float *e)
{
 (*d)=(*d)+(*d)*0.18;
 (*e)=(*e)+(*e)*0.18;
 }
 char *pass (char a[],char b[])
 {
     cout<<"processor:"<<a<<endl;
     return b;

 }
