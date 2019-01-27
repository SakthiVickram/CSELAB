#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class hardware
{
public:
char item1[10];
char item2[10];
char cpu[10];
char graphicscard[10];
int price;
void get();
};
void show(hardware ob)
{
cout<<"Item 1:"<<ob.item1<<endl;
cout<<"Item 2:"<<ob.item2<<endl;
cout<<"CPU:"<<ob.cpu<<endl;
cout<<"Graphics card:"<<ob.graphicscard<<endl;
cout<<"Price:"<<ob.price<<endl;
}
void modify(hardware *ob)
{
int op;
char ch;
cout<<"To Modify press the following";
cout<<"1.item1 2.item2 3.cpu 4.Graphics card 5.price 6.exit 7.show";
cin>>ch;
while(ch=='y')
{
cin>>op;
switch(op)
 {
case 1:
cout<<"item1";
cin>>ob->item1;
break;
case 2:
cout<<"Item 2:";
cin>>ob->item2;
break;
case 3:
cout<<"CPU:";
cin>>ob->cpu;
break;
case 4:
cout<<"Graphics card:";
cin>>ob->graphicscard;
case 5:
cout<<"Price:";
cin>>ob->price;
break;
case 6:
break;
case 7:
ch='n';
break;
}
}
}
void hardware::get()
{
cout<<"enter the object 1 values:";
cout<<"Item 1:";
cin>>item1;
cout<<"Item 2:";
cin>>item2;
cin.ignore();
cout<<"CPU:";
cin.get(cpu,10);
cin.ignore();
//cin>>cpu;
cout<<"Graphics card:";
cin>>graphicscard;
cout<<"Price:";
cin>>price;
}

hardware obj2()
{
hardware it2;
cout<<"Object 2 values:\n";
cout<<"item 1";
cin>>it2.item1;
cout<<"item 2";
cin>>it2.item2;
cout<<"cpu:";
cin>>it2.cpu;
cout<<"Graphics card:";
cin>>it2.graphicscard;
cout<<"Price:";
cin>>it2.price;

return it2;
}


void main()
{
hardware it,rt;
clrscr();
it.get();
show(it);
modify(&it);
show(it);
cout<<"return objects";
rt=obj2();
cout<<"display 2nd objects:";
show(rt);

getch();
}