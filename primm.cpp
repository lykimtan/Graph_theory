#include <stdio.h>

typedef struct{
	int A[100][100];
	int n;
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	for(int i=1; i<=G->n;i++)
	for(int j=1;j<=G->n;j++)
	G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y, int w)
{
	G->A[x][y] = w;
}
int adjacent(Graph* G, int x, int y)
{
	return G->A[x][y] != 0;
}

#define oo 9999
int pi[100];
int p[100];
int mark[100];

int prim(Graph* G, Graph* T, int s)
{
	int i,u,x,v;
	for(v=1;v<=G->n;v++)
	{
		pi[v] = oo;
		p[v] = -1;
		mark[v] = 0;
	}
	
	pi[s] = 0;
	
	for(i=1; i<=G->n;i++)
	{
		int min_dist = oo;
		for(x=1; x<=G->n;x++)
		if(mark[x] == 0 && pi[x] < min_dist)
		{
			min_dist = pi[x];
			u = x;
		}
		
		mark[u] = 1;
		
		for(v=1; v<=G->n;v++)
			if(adjacent(G,u,v))
			{
				if(mark[v] == 0 && pi[v] > G->A[u][v])
				{
					pi[v] = G->A[u][v];
					p[v] = u;
				}
			}
		
	}
	
	init_graph(T,G->n);
	int sum=0;
	
	for(u=1; u<=G->n;u++)
	{
		if(p[u]!=-1)
		{
			int w = G->A[p[u]][u];
			add_edge(T,p[u],u,w);
			sum+=w;
		}
	}
	return sum;
}

int main()
{
	Graph G,T;
	int n,m,e,v,w;
	freopen("prim.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(int i=1; i<=m;i++)
	{
		scanf("%d%d%d",&e,&v,&w);
		add_edge(&G,e,v,w);
	}
	
	int sum = prim(&G,&T,1);
	
	printf("%d\n",sum);
	
	for(int i=1; i<=T.n;i++)
	for(int j=1; j<=T.n;j++)
	{
		if(T.A[i][j]!=0)
		{
			printf("%d %d %d\n",i,j,T.A[i][j]);
		}
	}
}
