#include <stdio.h>

typedef struct{
	int n;
	 int A[100][100];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	for(int i=1; i<=n;i++)
	for(int j=1; j<=n;j++)
	G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y, int w)
{
	G->A[x][y] = w;
	G->A[y][x = w;
}

void adjacent(Graph* G, int x, int y)
{
	return G->A[x][y] != 0;
}
#define INFINITY 99999
int pi[100];
int  p[100];
int mark[100];

int prim(Graph* G, Graph* T, int s)
{
	int i,j,v,x;
	for(u=1; u<=G->n;u++)
	{
		pi[u] = INFINITY;
		p[u] = -1;
		mark[u] = 0;
	}
	pi[s] = 0;
	
	for(i=1; i<=G->n;i++)
	{
		int min_dist = INFINITY;
		for(x=1; x<=G->n;x++)
		if(mark[x]==0 && pi[x] < min_dist)
		{
			min_dist = pi[x];
			u = x;
		}
		
		mark[u] = 1;
		
		for(v=1; v<=G->n;v++)
		{
			if(G->A[u][v]!=0)
			{
				if(mark[v] == 0 && pi[v] > G->A[u][v])
				{
					pi[v] = G->A[u][v];
					p[v] = u;
				}
			}
		}
	}
	
	init_graph(T,G->n);
	int sum = 0;
	
	for(u=1; u<=G->n;u++)
	{
		if(p[u]!=-1)
		{
			int w = G->A[p[u]][u];
			add_edge(T,p[u],u,w);
			sum+=w
		}
	}
	return sum;
}

int main()
{
	Graph G,T;
	int n,m,e,v;
	freopen("prim.txt","r",stdin);
	init_graph(&G,n);
	for(int i=1; i<=m;i++)
	{
		scanf("%d%d%d",&e,&v,&w);
		add_edge(&G,e,v,w);
	}
	
	printf("%d ", prim(&G,&T,1));
	
}
