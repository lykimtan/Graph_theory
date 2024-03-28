#include <stdio.h>

#define MAXN 100
#define INFINITY 999
#define MAX_VERTICES 100
#define NO_EDGE 0
typedef struct{
    int n;
    int A[MAXN][MAXN];
}Graph;

void init_graph(Graph* G, int n)
{
    G->n = n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n;j++)
        {
            G->A[i][j]=0;
        }
    }
}

void add_edge(Graph* G, int x, int y, int w)
{
    G->A[x][y] = w;
}

int pi[MAXN];
int p[MAXN];
int cnt[MAXN];
int mark[MAXN];

void MooreDikjstra(Graph* G, int s)
{
    int i,it,u;
    for(u=1; u<=G->n; u++)
    {
        pi[u] = INFINITY;
        mark[u] = 0;
        cnt[u] = 0;
    }
    
    pi[s] = 0;
    p[s] = -1;
    for(it=1; it < G->n; it++)
    {
        int j, min_pi = INFINITY;
        for(j=1; j<=G->n; j++)
        {
            if(mark[j]==0 && pi[j] < min_pi)
            {
                min_pi=pi[j];
                u=j;
            }
        }
        mark[u]=1;
        
        for(i=1; i<=G->n; i++)
        {
            if(G->A[u][i]!=NO_EDGE && mark[i]==0)
            if(pi[u] + G->A[u][i] <= pi[i] )
            {
                pi[i] = pi[u] + G->A[u][i];
                p[i] = u;
                cnt[i] +=1;
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
	
	MooreDikjstra(&G,1);
	if(pi[n]==INFINITY) pi[n] = -1;
	printf("%d %d", pi[n], cnt[n]);

}
