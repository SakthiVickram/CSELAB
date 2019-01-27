#include <iostream.h>
#include <string.h>

#define V 6


class queue
{
public:
int x,q[20],f,r;
queue()
{
f=-1;
r=-1;
}

void push(int x)
{
if(f==-1)
f=0;
r++;
q[r]=x;
}

int front()
{
return q[f];
}
void pop()
{
 if(f==r)
 {
 f=-1,r=-1;
 }
 if(empty())
 return ;
 f++;

}
int empty()
{
if(f==-1)
return 1;
return 0;
}

};

int min(int x,int y)
{
   if(x>y)
   return y;
   else
   return x;
}

int bfs(int rGraph[V][V], int s, int t, int parent[])
{
	
	int visited[V],i;
      
	 for(i=0;i<V;i++)
	 visited[i]=0;
	
	queue q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v=0; v<V; v++)
		{
			if (visited[v]==0 && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = 1;
			}
		}
	}

	
	if(visited[t]==1)
	return 1;
	else
	return 0;
}


int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	
	int rGraph[V][V]; 
	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V]; 

	int max_flow = 0; 
	
	while (bfs(rGraph, s, t, parent))
	{
		
		int path_flow = 1000;
		for (v=t; v!=s; v=parent[v])
		{

			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		
		for (v=t; v != s; v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		
		max_flow += path_flow;
	}


	return max_flow;
}

// Driver program to test above functions
int main()
{
	// Let us create a graph shown in the above example
	int graph[V][V] = { 		       	{0, 16, 13, 0, 0, 0},
						{0, 0, 10, 12, 0, 0},
						{0, 4, 0, 0, 14, 0},
						{0, 0, 9, 0, 0, 20},
						{0, 0, 0, 7, 0, 4},
						{0, 0, 0, 0, 0, 0}
					};

	cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

	return 0;
}
