#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define INFINITY 99999

typedef struct{
	int n;
	int L[MAXN][MAXN];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n;
	int i,j;
	for(i=1; i<=n;i++)
		for(j=1;j<=n;j++)
		{
			G->L[i][j] = NO_EDGE;
		}
}

void add_edge(Graph* G, int x, int y, int w)
{
	G->L[x][y] = w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(Graph* G, int s)
{
	int i,j,it;
	for(i=1; i<=G->n; i++)
	{
		pi[i]=INFINITY;
		mark[i] = 0;
	}
	pi[s] = 0;
	p[s] =-1;
	
	for(it=1; it<=G->n; it++)
	{
		//1. Tim i co mark[i]=0 va pi[i] nho nhat
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++)
			if(mark[j]==0 && pi[j]<min_pi)
			{
				min_pi = pi[j];
				i=j;
			}	
		mark[i]=1;
		//cap nhat pi va p cua cac dinh ke cua i(neu thoa)
		
		for(j=1; j<=G->n; j++)
		if(G->L[i][j] != NO_EDGE && mark[j]==0)
		{
			if(pi[i] + G->L[i][j] < pi[j])
			{
				pi[j]=pi[i] + G->L[i][j];
				p[j]=i;
			}
		}
	}
}

int main()
{
	freopen("dt.txt","r",stdin);
	Graph G;
	int n,m,w,v,u,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	for(v=1; v<=m; v++)
	{
		scanf("%d%d%d",&u,&e,&w);
		add_edge(&G,u,e,w);
	}
	
	Dijkstra(&G,1);
	
	printf("%d ", pi[n]);
}


