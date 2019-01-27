#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
class specs
{
protected:
char os[15];
int hd;
int ram;
char processor[10];
private:
char graphics[10];
int resolution;
public:
void getdetails();
void display();
specs()
{
cout<<"specs objects created"<<endl;
}
};
void specs::getdetails()
{
cout<<"enter graphics and resolution"<<endl;
cin>>graphics>>resolution;
}
void specs::display()
{
cout<<"graphics and resolution"<<graphics<<" "<<resolution;
}

class hardware
{
protected:
char item1[10];
char item2[10];
int ram;
hardware()
{
cout<<"hardware objects created"<<endl;
}

};

class computer:private specs,private hardware        //Multiple inheritance
{
private:
char name[10];
int no;
float price;
public:
void getdetails(); //overriding the getdetails in specs
void display();     //overriding the display in specs
computer()
{
cout<<"computer class objects created"<<endl;
}

};
void computer::getdetails()
{
cout<<"enter the specification details:"<<endl;
cout<<"operating system:"<<endl;
cin>>os;
cout<<"harddisk:"<<endl;
cin>>hd;
cout<<"Ram:"<<endl;
cin>>specs::ram;
specs::getdetails();  //accessing the overriding base class methods
cout<<"processor:"<<endl;
cin>>processor;
cout<<"enter the hardware parts:"<<endl;
cout<<"Item1:"<<endl;
cin>>item1;
cout<<"Item2:"<<endl;
cin>>item2;
cout<<"enter the computer details:"<<endl;
cout<<"Name:"<<endl;
cin>>name;
cout<<"NO:"<<endl;
cin>>no;
cout<<"Price:"<<endl;
cin>>price;
}
void computer::display()
{
cout<<"the specification details:"<<endl;
cout<<"operating system: "<<os;
cout<<" harddisk: "<<hd;
cout<<" Ram: "<<specs::ram;
specs::display();
cout<<" processor: "<<processor<<endl;
cout<<" the hardware parts: "<<endl;
cout<<" Item1: "<<item1;
cout<<" Item2: "<<item2<<endl;
cout<<" the computer details: "<<endl;
cout<<" Name: "<<name;
cout<<" NO: "<<no;
cout<<" Price: "<<price;
}

//Multi level inheritance
class customer
{
protected:
char name[10];
long int no;
};
class customerbt:public customer
{
protected:
float amountpaid;
time_t t;
public:
customerbt()
{
t=time(0);
}
};
class service:public customerbt
{
public:
void get();
void print();
};
void service::get()
{

cout<<"enter the Customer Name and number:"<<endl;
cin>>name>>no;
cout<<"enter the amount paid:"<<endl;
cin>>amountpaid;
print();
}
void service::print()
{
cout<<"the Customer Name and number:"<<name<<" "<<no<<endl;
cout<<"the amount paid: "<<amountpaid<<endl;
cout<<"date of purchase:"<<ctime(&t);
}


int  main()
{
//clrscr();
computer dell;
dell.getdetails();
dell.display();

service no1;
no1.get();


getch();
}















