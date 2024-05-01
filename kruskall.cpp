#include <stdio.h>
typedef struct{
	int u,v;
	int w;
}Edge;

typedef struct{
	int n,m;
	Edge edges[100];
}Graph;

void swap(Edge *a, Edge* b)
{
	Edge temp = *a;
	*a = *b;
	*b = temp;
}

void init_graph(Graph* G, int n)
{
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int x, int y, int w)
{
	G->edges[G->m].u = x;
	G->edges[G->m].v = y;
	G->edges[G->m].w = w;
	G->m++; 
}

int adjacent(Graph* G, int u, int v)
{
    for(int i=1; i<=G->n;i++)
    {
    	if((G->edges[i].u == u && G->edges[i].u == v))
    	return 1;
	}
	return 0;
}

void bubble_sort(Edge edge[], int m)
{
	int i,j;
	for(i=0; i<=m;i++)
	for(j=m-1; j>i;j--)
	{
		if(edge[j-1].w > edge[j].w)
		swap(&edge[j-1],&edge[j]);
	}
}

int parent[100];
int findRoot(int u)
{
	if(parent[u] == u) return u;
	return findRoot(parent[u]);
}

int kruskal(Graph* G, Graph* T)
{
	bubble_sort(G->edges,G->m);
	init_graph(T,G->n);
	for(int u=1; u<=G->n;u++)
	parent[u] = u;
	
	int sum_w = 0;
	
	for(int e = 0; e<G->m;e++)
	{
		int u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if(root_u != root_v)
		{
			add_edge(T,u,v,w);
			parent[root_v]  = root_u;
			sum_w+=w;
		}
	}
	
	bubble_sort(T->edges,T->m);
	return sum_w;
}

int main()
{
	Graph G,T;
	int n,m,e,v,w,u;
	freopen("kruskal.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=0; e<m;e++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	
	printf("%d\n",kruskal(&G,&T));
	
  for(e=0; e<T.m;e++)
    {
        if(T.edges[e].u < T.edges[e].v )
        printf("%d %d %d\n",T.edges[e].u,T.edges[e].v, T.edges[e].w);
        else
         printf("%d %d %d\n",T.edges[e].v,T.edges[e].u, T.edges[e].w);
        
    }
	
}
