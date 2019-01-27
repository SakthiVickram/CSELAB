#include<iostream>
#include<conio.h>
using namespace std;

class specs
{
protected:
char os[10];
int no;
int ram;
public:
virtual void display()=0;
virtual void get()=0;
};


class computerdetails:public specs
{
public:
char bname[15];
char mname[15];
float price;
void display();
void get();
};

void computerdetails::get()
{
cout<<"enter the brand name:"<<endl;
cin>>bname;
cout<<"enter the model name:"<<endl;
cin>>mname;
cout<<"enter the price:"<<endl;
cin>>price;
}

void computerdetails::display()
{
cout<<"brandname: "<<bname<<" model name: "<<mname<<" price: "<<price;
}
class specs2:public specs
{
public:
    char processor[15];
    void display();
    void get();
};

void specs2::get()
{
cout<<"enter the OS:"<<endl;
cin>>os;
cout<<"enter the ram size:"<<endl;
cin>>ram;
cout<<"enter the processor:";
cin>>processor;
}

void specs2::display()
{
    cout<<"Ram size:"<<ram<<endl;
    cout<<"OS:"<<os<<endl;
    cout<<"processor:"<<processor<<endl;
}


int main()
{
specs *s;
computerdetails ob;
ob.get();
s=&ob;
s->display();
specs2 ob2;
ob2.get();
s=&ob2;
s->display();

return 0;
}
