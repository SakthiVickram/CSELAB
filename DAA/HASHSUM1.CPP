#include <iostream.h>
#include <conio.h>
int tsize,p;

int search(int,int[],int,int[]);
int hasht(int key)
{
 int i ;
 i = key%tsize ;
 return i;
}

//-------LINEAR PROBING-------
int rehashl(int key)
{
 int i ;
 i = (key+1)%tsize ;
 return i ;
}

//-------QUADRATIC PROBING-------
int rehashq(int key, int j)
{
 int i ;
 i = (key+(j*j))%tsize ;
 return i ;
}
//-------DOUBLE HASHING----------
int rehashd(int key,int j,int el)
{
int i;

i = (key+j*(p-(el%p)))%tsize ;
 return i ;

}
void findprime()
{
  int no,i,j,f;
   no=tsize;
   for(i=2;i<=no-1;i++)
 {
    f=1;
   for(j=2;j<=i/2;j++)
  {
   if(i%j==0)
   {
    f=0;
   break;
   }
  }
  if(f==1)
  {
  cout<<"it is a prime no\n"<<i;
  p=i;
  }
 }
 cout<<"largest prime no is\n"<<p;
}

void main()
{
    int key,arr[20],hash[20],i,n,s,op,j,k,el,hits[20],h=0,v;
    clrscr() ;
    cout<<"Enter the size of the hash table:  ";
    cin>>tsize;
    findprime();
    cout<<"\nEnter the number of elements: ";
    cin>>n;


    for (i=0;i<tsize;i++)
 hash[i]=-1 ;

    cout<<"Enter Elements: ";
    for (i=0;i<n;i++)
    {
    cin>>arr[i];
    }

    do
    {
 cout<<"\n\n1.Linear Probing\n2.Quadratic Probing \n 3.Double Hashing \n4.Exit \nEnter your option: ";
 cin>>op;
 switch(op)
 {
 case 1:
     for (i=0;i<tsize;i++)
     hash[i]=-1 ;
      v=0;
     for(k=0;k<n;k++)
     {
     h=0;
  key=arr[k] ;
  i = hasht(key);
  while (hash[i]!=-1)
{
      i = rehashl(i);
      h++;
  }

  if(h!=0)
  hits[v++]=h;
  hash[i]=key;


     }
     cout<<"\nThe elements in the array are:";
     for (i=0;i<tsize;i++)
     {
	 cout<<"\n  Element at position "<<i<<":"<<hash[i]<<endl;
     }

     for(i=0;i<v;i++)
     cout<<"hits"<<hits[i]<<endl;
     int sum,ans,bool;
     cout<<"enter the sum:";
     cin>>sum;
     for(i=0;i<tsize;i++)
     {

      if(sum>=hash[i])
      ans=sum-hash[i];
      else
      continue;

       bool=search(ans,hash,v,hits);

       if(bool==1)
       {
       cout<<"Pair Found:"<<hash[i]<<"and"<<ans<<endl;

	}
     }

     break ;

 case 2:
     for (i=0;i<tsize;i++)
  hash[i]=-1 ;

     for(k=0;k<n;k++)
     {
  j=1;
  key=arr[k] ;
  i = hasht(key);
  while (hash[i]!=-1)
  {
      i = rehashq(i,j);
      j++ ;
  }
  hash[i]=key ;
     }
     cout<<"\nThe elements in the array are: ";
     for (i=0;i<tsize;i++)
     {
    cout<<"\n Element at position"<<i<<":"<<hash[i];
     }
     break ;
    case 3:

    for (i=0;i<tsize;i++)
  hash[i]=-1;

     for(k=0;k<n;k++)
     {
  j=1;
  el=arr[k] ;
  i = hasht(el);
  while (hash[i]!=-1)
  {
      i = rehashd(i,j,el);
      j++ ;
  }
  hash[i]=el;
     }
     cout<<"\nThe elements in the array are: ";
     for (i=0;i<tsize;i++)
     {
  cout<<"\n Element at position"<<i <<":"<<hash[i];
     }
     break ;


 }
    }while(op!=4);



    getch();
}

int search(int se,int hash[],int v,int hits[])
{
int ind,hind,f=0,j;
    // cout<<"Enter the elment to search:";
    // cin>>se;
    ind=hasht(se);
     if(hash[ind]==se)
     {
 //    cout<<"Element found at: "<<ind;
     f=1;
     hash[ind]=-1; //empty it
     }
     else
     {
       for(j=0;j<v;j++)
	{
	hind=(ind+hits[j])%tsize;
	 if(hash[hind]==se)
	 {
	 f=1;
      //	 cout<<"Element found at: "<<hind;
	 hash[hind]=-1;
	 break;
	 }

       }
    // if(f==0)
    // cout<<"Element not found";

     }

  return f;
}
