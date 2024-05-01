#include <stdio.h>
typedef struct{
	int u, v;
	int w;
}Edge;

typedef struct{
	int n,m;
	Edge edges[100];
}Graph;

int swap(Edge* a, Edge* b)
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

void add_edge(Graph* G, int u, int v, int w)
{
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

int adjacent(Graph* G, int u, int v)
{
	for(int i=1; i<=G->n;i++)
	{
		if((G->edges[i].u == u && G->edges[i].v == v)) 
		return 1;
	}
	return 0;
}





void bubble_sort(Edge edges[], int m)
{
	int i,j;
	for(i=0; i<=m-2;i++)
	for(j=m-1; j>=i+1;j--)
	{
		if(edges[j-1].w > edges[j].w)
		swap(&edges[j-1],&edges[j]);
	}
}
int parent[100];

int findRoot(int u)
{
	if(parent[u]==u)
	return u;
	
	return findRoot(parent[u]);
}


int Kruskal(Graph* G, Graph* T)
{
	bubble_sort(G->edges,G->m);
	init_graph(T,G->n);
	for(int u=1; u<=G->n;u++)
	parent[u] =u;
	int sum_w = 0;
	
	for(int e=0; e<G->m;e++)
	{
	 	int u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		if(root_u != root_v){
			add_edge(T,u,v,w);
			parent[root_v] = root_u;
			sum_w +=w;
		}	
	}
	return sum_w;
}

int main()
{
	Graph G,T;
	int n,m,u,v,w,e;
	freopen("kruskal.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(e=1; e<=m;e++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	
	bubble_sort(G.edges,m);
	
	for(e=0;e<m;e++)
	{
		printf("%d %d %d\n",G.edges[e].u, G.edges[e].v, G.edges[e].w);
	}
//	int sum_w = Kruskal(&G,&T);
//	printf("Tong trong so cua cay T la: %d\n",sum_w);
//	for(e=0; e<T.m; e++)
//	printf("(%d, %d): %d\n", T.edges[e].u,T.edges[e].v, T.edges[e].w);
//	return 0;
}
