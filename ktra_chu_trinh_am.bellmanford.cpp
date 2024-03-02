#include <stdio.h>

#define MAX_ELEMENTS 100
#define MAX_VERTICES 100
#define INFINITY 99999
int pi[MAX_VERTICES];
int p[MAX_VERTICES];

typedef struct{
	int u,v;
	int w;
}Edge;

typedef struct{
	int n,m;
	Edge edges[MAX_VERTICES];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w)
{
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w =w;
	G->m++;
}

//giai thuat bell_man_ford
void BellmanFord(Graph* G, int s)
{
	int i,it,k;
	for(i=1; i<=G->n;i++)
	{
		pi[i]=INFINITY;
	}
	
	pi[s]=0;
	p[s]=-1; //truoc dinh s khong co dinh nao ca
	
	//lap n hoac n-1 lan deu duoc
	for(it =1; it<G->n; it++)
	{
		//duyet qua va cap nhat neu thoa
		for(k=0; k<=G->m;k++)
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
		
		for(k=0; k<G->m;k++)
		{
			int u = G->edges[k].u;
			int v = G->edges[k].v;
			int w = G->edges[k].w;
			if(pi[u] + w < pi[v])
			{
				printf("negative cycle");
				return;
			}
			else {
			    printf("ok");
			    return;
			}
		}
		
	}
}


int main()
{
 	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	BellmanFord(&G,1);
	
}


