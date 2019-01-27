#include <stdio.h>
#include <conio.h>
int tsize,p;

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
  printf("it is a prime no:%d\n",i);
  p=i;
  }
 }
 printf("largest prime no is:%d\n",p);
}

void main()
{
    int key,arr[20],hash[20],i,n,s,op,j,k,el ;
    clrscr() ;
    printf ("Enter the size of the hash table:  ");
    scanf ("%d",&tsize);
    findprime();
    printf ("\nEnter the number of elements: ");
    scanf ("%d",&n);


    for (i=0;i<tsize;i++)
 hash[i]=-1 ;

    printf ("Enter Elements: ");
    for (i=0;i<n;i++)
    {
 scanf("%d",&arr[i]);
    }

    do
    {
 printf("\n\n1.Linear Probing\n2.Quadratic Probing \n 3.Double Hashing \n4.Exit \nEnter your option: ");
 scanf("%d",&op);
 switch(op)
 {
 case 1:
     for (i=0;i<tsize;i++)
     hash[i]=-1 ;

     for(k=0;k<n;k++)
     {
  key=arr[k] ;
  i = hasht(key);
  while (hash[i]!=-1)
{
      i = rehashl(i);
  }
  hash[i]=key ;
     }
     printf("\nThe elements in the array are:");
     for (i=0;i<tsize;i++)
     {
  printf("\n  Element at position %d:%d",i,hash[i]);
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
     printf("\nThe elements in the array are: ");
     for (i=0;i<tsize;i++)
     {
  printf("\n Element at position %d: %d",i,hash[i]);
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
     printf("\nThe elements in the array are: ");
     for (i=0;i<tsize;i++)
     {
  printf("\n Element at position %d: %d",i,hash[i]);
     }
     break ;


 }
    }while(op!=4);

    getch() ;
}
