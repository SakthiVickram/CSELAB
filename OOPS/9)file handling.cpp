#include <iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
class customer
{
char name[20];
char location[15];
char phone[15];
int no;
char address[20];
public:
void getcustomerdetails();
void writecustomerdetails();
};
void customer::getcustomerdetails()
{
    cout<<"Enter the Customer no:";
    cin>>no;
cout<<"Enter the Customer's Name:";
cin.ignore();
gets(name);
cout<<"Enter the Mobile No:";
gets(phone);
cout<<"Enter the Address:";
gets(address);
cout<<"Enter the destination:";
gets(location);
}
void customer::writecustomerdetails()
{
fstream cus;
cus.open("customers.dat",ios::app);
cus<<"Customer's NO:"<<no<<endl;
cus<<"Customer's Name:"<<name<<endl;
cus<<"Mobile No:"<<phone<<endl;
cus<<"Address:"<<address<<endl;
cus<<"Item :"<<location<<endl;
cus.close();
}
int main()
{
    char ch,str[50];
    while(ch!='n')
    {
        customer ob;
    ob.getcustomerdetails();
    ob.writecustomerdetails();
    cout<<"press y to add customer's and n to quit";
    cin>>ch;
    }
fstream c;
c.open("customers.dat",ios::in);
if(c.fail())
    cout<<"error open";
while(!c.eof())
{
    c.getline(str,50,'\n');
    cout<<str<<endl;
    }
    c.close();
   return 0;
}
