#include<iostream>

using namespace std;
int m[10][10],topo[10],n,pred[10],s[10],e[10],time,top=0;
char color[10];
void push(int x);
int pop();
void display();
void dfs();
void dfsvisit(int u);
int  main()
{
 int i,j,z;

 cout<<"\n Enter the number of vertices->";
 cin>>n;
 cout<<"\n enter the adjacency matrix";
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   cout<<"\n for m["<<i<<"]["<<j<<"]->";
   cin>>m[i][j];
  }
 }
 cout<<"\n the adjacency matrix is:\n";
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   cout<<m[i][j]<<"\t";
  }
  cout<<"\n";
 }
 dfs();
 cout<<"\nVERTEX\tSTART\tEND\tPRED\n";
 for(i=0;i<n;i++)
 {
  cout<<i<<"\t"<<s[i]<<"\t"<<e[i]<<"\t"<<pred[i]<<"\n";
 }
 cout<<"\nthe topological order is:";
 for(i=0;i<n;i++)
 {
  z=pop();
  cout<<z<<"->";
 }
 return 0;
 }

void dfs()
{
 int i,j;
 for(i=0;i<n;i++)
 {
  color[i]='w';
  pred[i]=-1;
 }
 time=0;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(m[i][j]==1)
   {
    if(color[i]=='w')
    {
     dfsvisit(i);
    }
   }
  }
 }
}

void dfsvisit(int u)
{
 int i,j ;
 color[u]='g';
 s[u]=++time;
 for(i=0;i<n;i++)
 {
  if(m[u][i]==1)
   {
    if(color[i]=='w')
    {
     pred[i]=u;
     dfsvisit(i);
     }
    }
   }
   color[u]='b';
   e[u]=++time;
   push(u);
 }

void push(int x)
{

 topo[top]=x;
 top=top+1;
}

int pop()
{
 int y;
 top=top-1;
 y=topo[top];
 return y;
}















