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
 char regno[15];
 };

 void quicksort(student[],int,int,int);
int partition(student[],int,int,int);

 void mergesort(student[],student[],int,int,int);
 void merge(student[],student[],int,int,int);

 void getdetails(student o[],int size)
 {
 char str[25],str2[25];
 for(int i=0;i<size;i++)

 {
 cout<<"Enter the name:";
 gets(str);
 strcpy(o[i].name,str);
 cout<<"Enter the regno:";
// cin>>ob[i].regno;
 gets(o[i].regno);
 //strcpy(ob[i].regno,str2);
 cout<<"Enter the CGPA:";
 cin>>o[i].cgpa;
 }

 }
 void display(student o[],int size)
 {
	 cout<<"display"<<endl;
 for(int i=0;i<size;i++)
 {
 cout<<"Name:"<<o[i].name<<endl;
 cout<<"Regno:"<<o[i].regno<<endl;
 cout<<"CGPA:"<<o[i].cgpa<<endl;
 }
 }

 void main()
 {
 int size1,op,size2;
 student ob[10],oc[10];
 clrscr();
 cout<<"Enter the number of students for CSE department";
 cin>>size1;
 cout<<"Enter the number of students for IT department";
 cin>>size2;
 cout<<"Enter the details of CSE students:"<<endl;
 getdetails(ob,size1);
 cout<<"Enter the details of IT students:"<<endl;
 getdetails(oc,size2);
 cout<<"CSE Student Details"<<endl;
 display(ob,size1);
 cout<<"IT Student Details"<<endl;
 display(oc,size2);
 while(1)
 {
 cout<<"1.sortbyname 2.sortbycgpa 3.sortbyregno 0.EXIT ";
 cin>>op;
 switch(op)
 {
 case 1:
 quicksort(ob,0,size1-1,0);     //sortbyname
 quicksort(oc,0,size2-1,0);
 mergesort(ob,oc,size1,size2,0);
 break;
 case 2:
 quicksort(ob,0,size1-1,1);    //sortbycgpa
 quicksort(oc,0,size2-1,1);
 mergesort(ob,oc,size1,size2,1);
 break;
 case 3:
 quicksort(ob,0,size1-1,2);      //sortbyregno
 quicksort(oc,0,size2-1,2);
 mergesort(ob,oc,size1,size2,2);
 break;
 case 0:
 exit(1);
 }
 display(ob,size1);
 display(oc,size2);

 //mergesort(ob,oc,size1,size2,1);
// cout<<"After merge sort";
// display(ob,size1);
// display(oc,size2);


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
if(ch==0)
strcpy(pivot,ob[end].name);
pindex=start;
if(ch==1)
piv=ob[end].cgpa;
if(ch==2)
strcpy(pivot,ob[end].regno);
//piv=ob[end].regno;
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
if((strcmp(ob[i].regno,pivot)<0)&&(ch==2))
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

void mergesort(student ob[],student oc[],int s1,int s2,int ch)
{
merge(ob,oc,s1,s2,ch);
}

void merge(student ob[],student oc[],int s1,int s2,int ch)
{
int i,j,k;

student l1[10],r1[10];

for(i=0;i<s1;i++)
{
l1[i]=ob[i];
}
for(j=0;j<s2;j++)
{
r1[j]=oc[j];
}
 i=0;
 j=0;
 k=0;
while(i<s1 && j<s2)
{

if ( ( (l1[i].cgpa<=r1[j].cgpa)  && (ch==1) ) || ( (strcmp(l1[i].name,r1[j].name)<0) &&(ch==0) ) ||( (strcmp(l1[i].regno,r1[j].regno)<0)  && (ch==2) )  )
{
  if(k<s1)
ob[k]=l1[i];
else
oc[k-s1]=l1[i];
i++;
}
else
{
 if(k<s1)
 ob[k]=r1[j];
 else
 oc[k-s1]=r1[j];
 j++;
}

k++;

}

while(i<s1)
{
  if(k<s1)
  ob[k]=l1[i];
  else
  oc[k-s1]=l1[i];
 i++;
 k++;
}
while(j<s2)
{
  if(k<s1)
ob[k]=r1[j];
else
oc[k-s1]=r1[j];
j++;
k++;
 }

}


