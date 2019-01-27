 #include<iostream>
#include<conio.h>
using namespace std;

class customerbt
{
public:
char name[10];
float amountpaid;
float servicetax;
customerbt()
{
cout<<"object for bt created:"<<endl;
}

~customerbt()
{
cout<<"object for bt  deleted "<<endl;
}
};

class customer
{
    customerbt ob;    //composition
public:
char name[10];
char address[30];
int phoneno[10];
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
//clrscr();
customer *no1=new customer();
delete no1;
getch();
}
