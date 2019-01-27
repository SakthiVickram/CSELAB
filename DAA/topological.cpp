#include <iostream>

using namespace std;
int stacks[10],sp=-1,no,cost[10][10];

void dfs(int ,char [] );
void push(int );


int main()
{
int i,j,v;
char colour[10];

  cout<<"Enter the number of vertices:";
   cin>>no;
    cout<<"Enter the adjacency matrix:";
    for(i=0;i<no;i++)
    {
        for(j=0;j<no;j++)
        {
            cin>>cost[i][j];

        }
    }
    for(i=0;i<no;i++)
        colour[i]='w';

        for(i=0;i<no;i++)
        {
            if(colour[i]=='w')
                 {
                     v=i;
                    dfs(v,colour);
                 }


        }

      for(i=0;i<=sp;i++)
        cout<<stacks[i]<<" ";

    return 0;
}

void dfs(int v,char colour[] )
{
int i;

    colour[v]='g';
    for(i=0;i<no;i++)
    {
        if(cost[v][i]==1)
        {
        if(colour[i]=='w')
        dfs(i,colour);

        }
    }
    colour[v]='b';
    push(v);
}

void push(int v)
{
    sp++;
    stacks[sp]=v;
}
