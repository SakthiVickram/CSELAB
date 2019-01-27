 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>

 class student
 {
 public:
 char name[15];
 float cgpa;
 int regno;

 };

 void quicksort(student[],int,int,int);
int partition(student[],int,int,int);

 void getdetails(student ob[],int size)
 {
 char str[25],str2[25];
 for(int i=0;i<size;i++)
 {
 cout<<"Enter the name:";
 gets(str);
 strcpy(ob[i].name,str);
 cout<<"Enter the regno:";
 cin>>ob[i].regno;
// gets(str2);
 //strcpy(ob[i].regno,str2);
 cout<<"Enter the CGPA:";
 cin>>ob[i].cgpa;
 }
 }
 void display(student ob[],int size)
 {
	 cout<<"display"<<endl;
 for(int i=0;i<size;i++)
 {
 cout<<"Name:"<<ob[i].name<<endl;
 cout<<"Regno:"<<ob[i].regno<<endl;
 cout<<"CGPA:"<<ob[i].cgpa<<endl;
 }
 }

 void main()
 {
 int size,op;
 student ob[10];
 clrscr();
 cout<<"Enter the number of students";
 cin>>size;
 getdetails(ob,size);
 display(ob,size);
 while(1)
 {
 cout<<"1.sortbyname 2.sortbycgpa 3.sortbyregno 0.EXIT ";
 cin>>op;
 switch(op)
 {
 case 1:
 quicksort(ob,0,size-1,0);     //sortbyname
 break;
 case 2:
 quicksort(ob,0,size-1,1);    //sortbycgpa
 break;
 case 3:
 quicksort(ob,0,size-1,2);      //sortbyregno
 break;
 case 0:
 exit(1);
 }
 display(ob,size);
 getch();
 }
 }


void quicksort(student ob[],int start,int end,int ch)
{
int pindex;
if(start<end)
{
pindex=partition(ob,start,end,ch);
quicksort(ob,start,pindex-1,ch);
quicksort(ob,pindex+1,end,ch);
}
}

int partition(student ob[],int start,int end,int ch)
{

int pindex,i,tmp,piv;
char pivot[15];
student t;
strcpy(pivot,ob[end].name);
pindex=start;
if(ch==1)
piv=ob[end].cgpa;
if(ch==2)
piv=ob[end].regno;
for(i=start;i<end;i++)
{
if((strcmp(ob[i].name,pivot)<0)&&(ch==0))
{
t=ob[i];
ob[i]=ob[pindex];
ob[pindex]=t;
pindex++;
}
else if((ob[i].cgpa<=piv)&&(ch==1))
{
t=ob[i];
ob[i]=ob[pindex];
ob[pindex]=t;
pindex++;
}
else if((ob[i].regno<=piv)&&(ch==2))
{
t=ob[i];
ob[i]=ob[pindex];
ob[pindex]=t;
pindex++;
}


}
t=ob[pindex];
ob[pindex]=ob[end];
ob[end]=t;
return pindex;
}



