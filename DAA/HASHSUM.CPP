#include <iostream.h>
#include <conio.h>
int tsize,p;

int search(int,int[]);
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


void main()
{
    int key,arr[20],hash[20],i,n,s,op,j,k,h=0;
    clrscr() ;
    cout<<"Enter the size of the hash table:  ";
    cin>>tsize;
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
 cout<<"\n\n1.Linear Probing\n0.Exit \nEnter your option: ";
 cin>>op;
 switch(op)
 {
 case 1:
     for (i=0;i<tsize;i++)
     hash[i]=-1 ;

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

  hash[i]=key;
  cout<<"hits"<<h<<endl;

     }
     cout<<"\nThe elements in the array are:";
     for (i=0;i<tsize;i++)
     {
	 cout<<"\n  Element at position "<<i<<":"<<hash[i]<<endl;
     }


     int sum,ans,bool,flag=0;
     cout<<"enter the sum:";
     cin>>sum;
     for(i=0;i<tsize;i++)
     {

      if(sum>=hash[i] && hash[i]!=-1)
      ans=sum-hash[i];
      else
      continue;

       bool=search(ans,hash);

       if(bool==1 && hash[i]!=-1)
       {
       cout<<"Pair Found:"<<hash[i]<<" and "<<ans<<endl;
	flag=1;
	}
     }
     if(flag==0)
     cout<<"Pair Not Found";
     break ;
   }
    }while(op!=0);



    getch();
}

int search(int se,int hash[])
{
int ind,hind=0,f=0,j;
    // cout<<"Enter the elment to search:";
    // cin>>se;
    ind=hasht(se);
     if(hash[ind]==se)
     {
 //    cout<<"Element found at: "<<ind;
     f=1;
     hash[ind]=-1; //empty it
    // ind++;
     }
     else
     {
       for(j=0;j<tsize-1;j++)
	{
	hind=rehashl(hind);
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
