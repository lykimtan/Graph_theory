#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct{
    int n,m;
    int A[MAX_VERTICES][MAX_ELEMENTS];
}Graph;

void init_graph(Graph* G, int n, int m)
{
    G->n = n;
    G->m = m;
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
    G->A[i][j]=0;
}

void add_edge(Graph* G, int e, int x, int y)
{
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

int adjacent(Graph* G, int x, int y)
{
    int e;
    for(e=1; e<=G->m; e++)
    if(G->A[x][e]==1 && G->A[y][e]==1)
    return 1;
     return 0;
}
int parent[MAX-VERTICES];
int mark[MAX_VERTICES];
void DFS(Graph* G, int u)
{
    printf("%d \n", u);
    mark[u] =1;
    for(int v =1; v<= G->n; v++)
    if(adjacent(G,u,v) && mark[v]==0)
    DFS(G,v);
}

int main()
{
	freopen("dt.txt","r",stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n,m);
	
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G,e, u, v);
	}
	
	for(int i=1; i<=G.n; i++)
	{
		if(mark[i]==0)
		DFS(&G,i);
	}
}
