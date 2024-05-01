#include <stdio.h>

typedef struct{
	int data[100];
	int size;
}List;

void make_null(List* L)
{
	L->size = 0;
}

void push_back(List* L, int x)
{
	L->data[L->size] = x;
	L->size++;
}

int element_at(List* L, int index)
{
	return L->data[index-1];
}

void copy_list(List* L1, List* L2)
{
	make_null(L2);
	for(int i=1; i<=L1->size;i++)
	{
		int x = element_at(L1,i);
		push_back(L2,x);
	}
}

typedef struct{
	int A[100][100];
	int n;
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	for(int i=1; i<=G->n;i++)
	for(int j=1; j<=G->n;j++)
	G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y)
{
	G->A[x][y] = 1;
}

int adjacent(Graph* G, int x, int y)
{
	return G->A[x][y]!=0;
}
int rank[100];
void ranking_topo(Graph* G)
{
	int d[100];
	int x,u;
	for(u=1; u<=G->n;u++)
		d[u] = 0;
	
	for(x=1;x<=G->n;x++)
		for(u=1; u<=G->n;u++)
			if(adjacent(G,x,u))
				d[u]++;
	List s1,s2;
	make_null(&s1);
	
	for(u=1; u<=G->n;u++)
		if(d[u]==0) push_back(&s1,u);
	
	int k=0,i;
	while(s1.size > 0)
	{
		make_null(&s2);
		for(i=1; i<=s1.size;i++)
		{
			int u = element_at(&s1,i);
			rank[u] = k;
			int v;
			for(v=1; v<=G->n; v++)
				if(adjacent(G,u,v))
				 {
				 	d[v]--;
				 	if(d[v]==0)
				 	 push_back(&s2,v);
				 }
		}
		copy_list(&s2,&s1);
		k++;
	}
}

int main()
{
	Graph G;
	int n,m,e,v;
	freopen("topo.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(int i=0; i<m;i++)
	{
		scanf("%d%d",&e,&v);
		add_edge(&G,e,v);
	}
	
	ranking_topo(&G);
	
	for(int i=1; i<=G.n;i++)
	{
		printf("%d \n", rank[i]);
	}
}
