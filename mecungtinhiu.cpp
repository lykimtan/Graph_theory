#include <stdio.h>

#define INFINITY 99999
#define MAXN 100

typedef struct{
	int data[MAXN];
	int size;
}List;

void make_null(List* L)
{
	L->size = 0;
}

void push_back(List *L, int x)
{
	L->data[L->size] = x;
	L->size++;
}
typedef struct{
	int A[MAXN][MAXN];
	int n;
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			G->A[i][j]=0;
		}
}

void add_edge(Graph* G, int x, int y, int w)
{
	if(x==y) G->A[x][y] +=1;
	else{
		G->A[x][y] +=1;
		G->A[y][x]+=1;
	}
}

void add_edge_directed(Graph* G, int x, int y)
{
	G->A[x][y] +=1;
}

int adjacent(Graph* G, int x, int y)
{
	return G->A[x][y] !=0;
}

int degree(Graph* G, int x)
{
	int y, deg =0;
	for(y=1; y<=G->n; y++)
	{
		deg+=G->A[x][y];
	}
	if(G->A[x][y]!=0) deg+=G->A[x][x];
	return deg;
}

List neighbors1(Graph* G, int x)
{
	int y;
	List L;
	make_null(&L);
	for(y=1; y<=G->n; y++)
	{
		if(adjacent(G,x,y))
		push_back(&L,y);
	}
	return L;
}

List neighbors2(Graph* G, int x)
{
	int i,j;
	List L; 
	make_null(&L);
	for(i=1; i<=G->n; i++)
	{
		for(j=1 ; j<=G->A[x][i]; j++)
		push_back(&L,i);
	}
	return L;
}

//O i,j se tuong ung voi dinh (i*N + j) + 1
// dinh u se tuong ung voi o o hang(u-10/n va cot (u-1)%n
// M dong, n cot
//doi 1 o thanh dinh
//co huong

void read(Graph* G, int B[][50], int m, int n)
{
	int u,k,i,j;
	//top,bottom,left,right
	int di[] = {-1,1,0,0};
	int dj[] = {0,0,-1,1};
	
	for(u=1; u<=G->n; u++)
	{
		i = (u-1)/n;
		j = (u-1)%n;
		int v;
		for(k=0; k<4; k++)
		{
			int ii = i+ di[k];
			int jj = j + dj[k];
			if(ii>=0 && ii < m && jj >=0 && jj<n)
			{
				v = ii*n + jj +1;
				G->A[u][v] = B[ii][jj];
			}
		}
	}
}

#define MAX_VERTICES 100
int pi[MAX_VERTICES];
int p[MAX_VERTICES];
int mark[MAX_VERTICES];

void MooreDikjstra(Graph* G, int u)
{
	int i,j,it;
	for(i=1; i<=G->n; i++)
	{
		pi[i] = INFINITY;
		mark[i] = 0;
	}
	pi[u] = 0;
	p[u] = -1;
	
	for(i=1 ; i<=G->n; i++)
	{
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++)
		{
			if(mark[j] ==0 && pi[j] <min_pi)
			{
				min_pi = pi[j];
				it = j;
			}
		}
		mark[it] = 1;
		//cap nhat cac dinh ke neu thoa
		for(j=1; j<=G->n; j++)
		{
			if(G->A[it][j] != 0 && mark[j]==0)
			{
				if(pi[it] + G->A[it][j] < pi[j])
				{
					pi[j] = pi[it] + G->A[it][j];
					p[j] = it;
				}
			}
		}
	}
}

int main()
{
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n,i,j,m;
	scanf("%d%d",&m,&n);
	init_graph(&G,n*m);
	int B[50][50];
	for(i=0; i<m; i++)
	{
		for(j=0; j<n;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	read(&G,B,m,n);
	MooreDikjstra(&G,1);
	printf("%d ", pi[G.n] + B[0][0]);
	return 0;
}
