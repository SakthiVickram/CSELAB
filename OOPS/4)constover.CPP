#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
class computersystemdetails
{
public:
string brandname;
string modelname;
int  serialnumber;
float itemprice;
public:
computersystemdetails(string,string);
computersystemdetails(int ,float);
void displaydetails();
void display();
};
 computersystemdetails::computersystemdetails(string b,string m )
{
brandname=b;
modelname=m;
}
computersystemdetails::computersystemdetails(int s,float p)
{
    serialnumber=s;
    itemprice=p;
}
void computersystemdetails::displaydetails()
{
cout<<"BRAND NAME:";
cout<<brandname<<endl;
cout<<"MODEL NAME:";
cout<<modelname<<endl;

}
void computersystemdetails::display()
{
    cout<<"SERIAL NO:";
cout<<serialnumber<<endl;
cout<<"ITEM PRICE:";
cout<<itemprice<<endl;
}
int main()
{
    string brandname,modelname;
    int serialnumber;
    float itemprice;
    cout<<"BRAND NAME:";
cin>>brandname;
cout<<"MODEL NAME:";
cin>>modelname;
cout<<"SERIAL NO:";
cin>>serialnumber;
cout<<"ITEM PRICE:";
cin>>itemprice;
computersystemdetails ob(brandname,modelname);
computersystemdetails ob2(serialnumber,itemprice);
ob.displaydetails();
ob2.display();
return 0;
}

