#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 50

typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];	
}Graph;

void init_graph(Graph* G, int n, int m)
{
	G->n=n;
	G->m=m;
	for(int i=1; i<=n; i++)
	 for(int j=1; j<=m;j++)
	 {
	 	G->A[i][j] = 0;
	 }
}

void add_edge(Graph* G, int e, int x, int y)
{
	G->A[x][e]=1;
	G->A[y][e]=1;
}

int degree(Graph* G, int x)
{
	int deg=0;
	for(int e=1; e<=G->m; e++)
	{
		if(G->A[x][e]==1)
		deg++;
	}
	return deg;
}

int main()
{
	int n,m,u,v,e;
	scanf("%d%d", &n,&m);
	Graph G;
	init_graph(&G,n,m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d%d",&u,&v);
			add_edge(&G,j,u,v);
		}
	
	int max = degree(&G,1);
	int max_ver=1;
	for(int e=1; e<=n; e++)
	{
		if(degree(&G,e)>max)
		{
			max = degree(&G,e);
			max_ver=e;
		}
	}
	
	printf("%d %d", max_ver, max);
}
