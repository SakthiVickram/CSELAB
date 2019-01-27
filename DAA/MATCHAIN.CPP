#include<iostream.h>
#include<conio.h>
#include<limits.h>
int **m,**s;
void matrix_mult_chain(int *p,int n)
{
 int j,k,i,l,q;
 m=new int*[n+1];
 s=new int*[n+1];
 for(i=0;i<n;i++)
 {
 m[i]=new int[n+1];
 s[i]=new int[n+1];
 }
 for(i=0;i<n+1;i++)
 {
  for(j=0;j<n+1;j++)
  {
   m[i][j]=0;
   s[i][j]=0;
  }
 }
 for(i=0;i<n;i++)
  m[i][i]=0;
 for(l=2;l<=n;l++)
 {
   for(i=1;i<=n-l+1;i++)
   {
	  j=i+l-1;
	  m[i][j]=INT_MAX;
	  for(k=i;k<=j-1;k++)
	  {
	   q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	   if(q<m[i][j]&&q>0)
	   {
	m[i][j]=q;
	s[i][j]=k;
	   }
	  }
  }
 }
 cout<<'\n';
 for(i=1;i<n+1;i++)
 {
  for(j=1;j<n+1;j++)
  {
   cout<<m[i][j]<<"\t";
  }
 cout<<'\n';
}
 cout<<'\n';
 for(i=1;i<n+1;i++)
 {
  for(j=1;j<n+1;j++)
  {
   cout<<s[i][j]<<"\t ";
  }
 cout<<'\n';
}
}
void mult(int i,int j)
{
   if(i==j)
   {
	cout<<"A"<<i;
   }
   else
   {
	cout<<"( ";
	int k=s[i][j];
	mult(i,k);
	mult(k+1,j);
	cout<<")";

   }
}
void main()
{
 int n;
 int p[]={5,10,3,12,5,50,6};
 clrscr();
 n=6;
 matrix_mult_chain(p,n);
 mult(1,n);
 getch();
}
