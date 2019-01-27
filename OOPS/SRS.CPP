#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>


int count();
const int size=5;

class specs
{
protected:
char os[15];
float hd;
int ram;
char processor[10];
char graphics[10];
int resolution;
public:
void getspecs();
void display();
};

class computersystem:public specs
{
   private:
char brand[15];
int no;
float price;
int period;
   public:
void getsys();
void display2();
void access(int);
int identify(char[],int,int,float,char[]);
friend void setdetails(computersystem);
};

void computersystem::getsys()
{

cin.ignore();
cout<<"enter the brand";
cin.getline(brand,20,'\n');
cout<<"enter the number:";
cin>>no;
cout<<"enter the price:";
cin>>price;
cout<<"enter the period:";
cin>>period;
cin.ignore();
cout<<"enter the operating system: ";
cin.getline(os,20,'\n');
cout<<"enter the harddisk:";
cin>>hd;
cout<<"enter the ram:";
cin>>ram;
cin.ignore();
cout<<"enter the processor:";
cin.getline(processor,20,'\n');
cout<<"enter the graphics:";
cin.getline(graphics,20,'\n');
cout<<"enter the resolution:";
cin>>resolution;

}

void computersystem::display2()
{
cout<<"Brandname     Serialno  WarrantyPeriod  Price  OperatingSystem  HardDiskCapacity "<<endl;
cout<<brand<<setw(5)<<no<<setw(10)<<period<<"years"<<setw(9)<<"RS"<<price<<setw(15)<<os<<setw(5)<<hd<<"TB"<<setw(5)<<endl;
cout<<endl;
cout<<"Ram  Processor  Graphics  Resolution"<<endl;
cout<<endl;
cout<<ram<<"GB"<<setw(10)<<processor<<setw(9)<<graphics<<setw(10)<<resolution<<endl;
cout<<"********************************************************************************";
}

void computersystem::access(int no)
{
cout<<no<<"."<<"brand:"<<brand<<endl;
}

int computersystem::identify(char bn[],int v,int s,float p1,char p[])
{
if(((strcmpi(bn,brand)==0) && (ram>=s) && (price<=p1)) && strcmpi(p,processor))
{
v=1;
}
return v;
}

class customer
{
char name[20];
int item;
char phone[15];
char address[20];
float amt;
public:
void getcustomerdetails(int);
void showcustomerdetails();
};

void customer::getcustomerdetails(int sno)
{
cout<<"Enter the Customer's Name:";
cin.ignore();
cin.getline(name,20,'\n');
item=sno;
cout<<"Enter the Mobile No:";
cin.getline(phone,15,'\n');
cout<<"Enter the Address:";
cin.getline(address,20,'\n');
cout<<"Enter the Amount:";
cin>>amt;
}

void customer::showcustomerdetails()
{
cout<<"Customer's Name:"<<name<<endl;
cout<<"Mobile No:"<<phone<<endl;
cout<<"Address:"<<address<<endl;
cout<<"Amount paid:"<<amt<<endl;
}

void main()
{
computersystem ob[size],add;

while(1)
{
clrscr();
int op,c,sno,i,j;
cout<<"1.Connect To Database and Display\n2.ADD a New System\n3.Access\n4.Search By Brand\n5.Total No of Systems Available\n";
cout<<"6.Purchase System\n7.Identification Of System\n8.View Customer Details\n0.EXIT";
cin>>op;
switch(op)
{
case 1:    //Display all the available items
{
fstream fp;
fp.open("newdata.dat",ios::in);
for(i=0;i<count();i++)
{
fp.read((char*)&ob[i],sizeof(ob[i]));
//ob[i].getsys();
ob[i].display2();
}
fp.close();
break;
}
case 2:     //add a new system to database
{
fstream in;
in.open("newdata.dat",ios::app);
add.getsys();
in.write((char*)&add,sizeof(add));
in.close();
break;
}
case 3:   //connect and access
  {
 for(i=0;i<count();i++)
 ob[i].access(i+1);   //brands available
 break;
  }
case 4://search by record no
{
int no;
//cout<<"1.lenovo 2.dell 3.apple"<<endl;
for(i=0;i<count();i++)
 ob[i].access(i+1);   //brands available

cout<<"enter the record no"<<endl;
cin>>no;
no--;
if(no>count()-1)
{
cout<<"Item not found:"<<endl;
break;
}
int po;
cout<<"Item available:"<<endl;
fstream ops;
ops.open("newdata.dat",ios::in);
ops.seekg(no*sizeof(ob[no]),ios::beg);
po=ops.tellg();
cout<<"pos:"<<po<<endl;
ops.read((char*)&ob[no],sizeof(ob[no]));
ob[no].display2();
ops.close();
break;
}
case 5:    //count the no of items
{
c=count();
cout<<"No of items available:"<<c<<endl;
break;
}
case 6:    //Purchase a system
{

for(i=0;i<count();i++)
 ob[i].access(i+1);   //brands available
//cout<<"1.lenovo 2.dell 3.apple\n";
cout<<"Enter the No to Purchase:";
cin>>sno;
if(sno<=count())
{
cout<<setw(53)<<"Item Available For Purchase"<<endl;
}
else
{
cout<<setw(53)<<"Item Not Available For Purchase"<<endl;
break;
}
sno--;
//get the customer details for purchase

customer c;
c.getcustomerdetails(sno);

fstream cm;
cm.open("customer.dat",ios::app);
cm.write((char*)&c,sizeof(c));

fstream cr;
cr.open("newdata.dat",ios::in);
computersystem tp;

cr.seekg(sno*sizeof(ob[sno]),ios::beg);
cr.read((char*)&tp,sizeof(tp));
cm.write((char*)&tp,sizeof(tp));


cm.close();
cr.close();


//deleting the item

fstream or,ow;
or.open("newdata.dat",ios::in);
ow.open("temp.dat",ios::out);

//int i,j;

for(i=0;i<sno;i++)
{
or.read((char*)&ob[i],sizeof(ob[i]));
ow.write((char*)&ob[i],sizeof(ob[i]));
}
or.seekg(sizeof(ob[i]),ios::cur);
for(j=sno+1;j<count();j++)
{
or.read((char*)&ob[i],sizeof(ob[i]));
ow.write((char*)&ob[i],sizeof(ob[i]));
}

or.close();
ow.close();
remove("newdata.dat");
rename("temp.dat","newdata.dat");
cout<<setw(53)<<"Item purchased successfully";
break;
}
case 7:       //identification of system
{
int s ,v;
float p1;
char p[15],bn[15];
cout<<"Enter the user requirements"<<endl;
cout<<"Enter the brandname:";
cin.ignore();
cin.getline(bn,20,'\n');
cout<<"Enter the Minimum Ram size:";
cin>>s;
cout<<"Enter the Maximum price:";
cin>>p1;
cout<<"Enter the Maximum Processor:";
cin.ignore();
cin.getline(p,20,'\n');

for(i=0;i<count();i++)
{
v=0;
v=ob[i].identify(bn,v,s,p1,p);
if(v==1)
{
cout<<"Match found"<<endl;
cout<<"********************************************************************************"<<endl;
ob[i].display2();

break;
}
}
if(v==0)
cout<<"Match not found";
break;
}
case 8:
{
int ps;
cout<<"Customer's Details:"<<endl;    //customer database
fstream cd;
cd.open("customer.dat",ios::in);

customer rd;
cd.read((char*)&rd,sizeof(customer));
cd.read((char*)&ob[0],sizeof(ob[0]));
if(cd.eof())
{
cout<<"No customer details:";
break;
}
//ps=cd.tellg();
//cout<<pos<<" "<<cr.eof();
//cr.seekg(0,ios::beg);
//cout<<ps<<" "<<cd.eof();
while(!cd.eof())
{
rd.showcustomerdetails();
ob[0].display2();
cd.read((char*)&rd,sizeof(customer));
cd.read((char*)&ob[0],sizeof(ob[0]));
}
cd.close();

break;
}
case 0:
 exit(0);
 break;
}
getch();
}
}

int count()
{
int pos,rec;
fstream opc;
opc.open("newdata.dat",ios::in);
opc.seekg(0,ios::end);
pos=opc.tellg();
//cout<<"size of file is:"<<pos<<endl; //byte position
//cout<<"size of one record:"<<sizeof(computersystem)<<endl;
rec=pos/sizeof(computersystem);
return rec;
}