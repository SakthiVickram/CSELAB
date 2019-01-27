#include<iostream>
#include<conio.h>
using namespace std;
class date
{
public:
float amount;
date()
{
cout<<"object forbalance created"<<endl;
}
~date()
{
cout<<"object for balance deleted:"<<endl;
}
};
class customer
{
date *pt;
public:
char name[10];
char address[30];
int phoneno;
customer()
{
cout<<"customer object created :"<<endl;
}
~customer()
{
cout<<"customer  object deleted:";
}
};
int main()
{
customer *no1=new customer();
delete no1;
getch();
}
