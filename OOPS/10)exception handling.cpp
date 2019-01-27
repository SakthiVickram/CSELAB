#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    try{
    int ram;
    char  os[15];
    cout<<"Enter the ram size:";
    cin>>ram;
    cin.ignore();
    cout<<"Enter the operating system:";
    cin.getline(os,15,'\n');
    if(ram>20)
    throw "Invalid ram size";
    cout<<"ram size is:"<<ram<<endl;
   if((!strcmpi(os,"windows 7")) )
    throw "Older Version";
    cout<<"operating system:"<<os;
}
catch(const char  *msg)
{
    cout<<"Error "<<msg;
}
return 0;
}
