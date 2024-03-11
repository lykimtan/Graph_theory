#include <stdio.h>

#define INFINITY 9999
#define MAXN 100

typedef struct{
	int u,v;
	int w;
}Edge;

typedef struct {
	int n,m;
	Edge edges[1000];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w)
{
	G->edges[G->m].u=u;
	G->edges[G->m].v = v;
	G->edges[G->m].w=w;
	G->m++;
}

int pi[MAXN];
int p[MAXN];

void BellmanFord(Graph* G, int s)
{
	int i,it,j;
	for(i=1; i<=G->n; i++)
	{
		pi[i]=INFINITY;
	}
	pi[s]=0;
	p[s]=-1;
	
	for(it =1; it<=G->n; it++)
	{
		for(int k=0; k<G->m; k++)
		{
			int u = G->edges[k].u;
			int v = G->edges[k].v;
			int w = G->edges[k].w;
			if(pi[u] + w < pi[v])
			{
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
		
	}
	
	int negative_cycle = 0;
		for(int k=0; k<G->m; k++)
		{
			int u = G->edges[k].u;
			int v = G->edges[k].v;
			int w = G->edges[k].w;
			if(pi[u] + w < pi[v])
			{
				negative_cycle=1;
				break;
			}
		}
		
	if(negative_cycle ==1) printf("YES");
		else printf("NO");
}

int main()
{
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e,s;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	scanf("%d",&s);
	
	BellmanFord(&G,s);
	

}
