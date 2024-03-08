#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define INFINITY 999999
typedef struct{
	int n;
	int L[MAXN][MAXN];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	int i,j;
	for(i=1; i<=n ;i++)
		for(j=1; j<=n; j++)
		 G->L[i][j]=NO_EDGE;
}

void add_edge(Graph* G, int x,int y, int w)
{
	G->L[x][y]=w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(Graph* G, int s)
{
	int i,j,it;
	for(i=1; i<=G->n; i++)
	{
		pi[i] = INFINITY;
		mark[i]=0;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it=1; it<=G->n; it++)
	{
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++)
		if(mark[j]==0 && pi[j]< min_pi)
		{
			min_pi = pi[j];
			i=j;
		}
		mark[i]=1;
		for(j=1; j<=G->n; j++)
		 if(G->L[i][j] !=NO_EDGE && mark[j]==0)
		 {
		 	if(pi[i] + G->L[i][j] < pi[j])
		 	{
		 		pi[j] = pi[i] + G->L[i][j];
		 		p[j] = i;
			 }
		 }
	}
}


int main()
{
	Graph G;
	int x,y,n,m,v,e,i,w,t,h;
	freopen("grap.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	for(i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add_edge(&G,x,y,w);
	}
	scanf("%d%d",&t,&h);
	
	Dijkstra(&G,t);
	printf("%d ",pi[h]);
	
}


