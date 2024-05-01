#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

typedef struct{
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	int i,j;
    for( i=1; i<=n; i++)
    {
        for( j=1; j<=n; j++)
        {
            G->A[i][j]=0;
        }
    }
}

void add_edge(Graph* G, int x, int y)
{
    G->A[x][y]=1;
    G->A[y][x]=1;
}



int degree(Graph* G, int x)
{
    int i,cnt=0;
    for(i=1;i<=G->n;i++)
    {
        if(G->A[x][i]>0)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    Graph G;
    int n,m,i,j,e,v;
    freopen("dt.txt","r",stdin);
    scanf("%d%d",&n,&m);
       init_graph(&G,n);
    for(j=1; j<=m;j++)
    {
        scanf("%d %d",&e,&v);
        add_edge(&G,e,v);
    }
    int cnt;
    for(i=1; i<=G.n; i++)
    {
    	cnt =degree(&G,i);
        printf("%d \n",cnt);
    }
    return 0;
}
