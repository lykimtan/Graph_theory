#include <stdio.h>

#define MAX_VERTICES 100
#define INFINITY -9999
#define ININFINITY 99999

int max(int a, int b)
{
	if(a>b) return a;
	return b;
}

int min(int a, int b)
{
	if(a<b) return a;
	return b;
}
typedef struct{
	int data[MAX_VERTICES];
	int size;
}List;

void make_null_list(List* L)
{
	L->size=0;
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

typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;

void init_graph(Graph* G, int n)
{
	G->n = n;
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	 G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y)
{
	G->A[x][y] = 1;
}

void copy_list(List* l1, List *l2)
{
	make_null_list(l1);
	for(int i=1 ; i<=l2->size; i++)
	{
		int x = element_at(l2,i);
		push_back(l1,x);
	}
}

int rank[MAX_VERTICES];
List L;
void ranking(Graph* G)
{
	make_null_list(&L);
	int d[MAX_VERTICES];
	int x,u;
	for(u=1; u<=G->n; u++)
	 d[u] = 0;
	for(x=1; x<=G->n; x++)
	{
		for(u=1; u<=G->n; u++)
		if(G->A[x][u] != 0)
		d[u]++;
	}
	
	List s1,s2;
	make_null_list(&s1);
	for(u=1; u<=G->n; u++)
		if(d[u] == 0)
		{
		push_back(&s1,u);	
		push_back(&L,u);
		}
		 
	int k=0,i;
	while(s1.size > 0)
	{
		make_null_list(&s2);
		for(i=1; i<=s1.size; i++)
		{
			int u = element_at(&s1,i);
			rank[u] = k;
			int v;
			for(v=1; v<=G->n; v++)
				if(G->A[u][v] != 0)
				{
					d[v]--;
					if(d[v] == 0)
					{
						push_back(&s2,v);
						push_back(&L,v);
					}
				}
		}
		copy_list(&s1,&s2);
		k++;
	}
}

int d[MAX_VERTICES];

int main()
{
	Graph G;
	int n,u,x,v,j,u1,t1;
	freopen("duanxaynha.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n+2);
	int anpha =n+1, beta = n+2;
	d[anpha] = 0;// thoi gian hoàn thành c?a công vi?c anpha la 0
	
	//doc danh sach cac cong viec

	for(u=1; u<=n;u++)
	{
		scanf("%d ", &d[u]);// thoi gian hoan thanh cong viec u
		do {
			scanf("%d", &v);//cong viec truoc cong viec u
			if(v>0)
			add_edge(&G,v,u);
		}while(v>0);
	}
	
	scanf("%d%d",&u1,&t1);
	
	//them cung noi anpha vao cac dinh co bac bang 0
	for(u=1; u<=n; u++)
	{
		int deg_neg = 0;
		for(x=1; x<=n; x++)
		{
			if(G.A[x][u] > 0)
			deg_neg++;//deg_neg la bac vao cua u
			if(deg_neg == 0) add_edge(&G,anpha,u);
		}
		//them cung noi vao cac dinh co bac ra = 0 vap beta
		for(u=1; u<=n; u++)
		{
			int deg_pos =0;
			for(v=1; v<=n; v++)
			if(G.A[u][v] > 0)
			deg_pos++;//deg_pos la bac ra cua u
			if(deg_pos ==0)
			add_edge(&G,u,beta);
		}
		
	}
	
	ranking(&G);
	
	int t[MAX_VERTICES];
	t[anpha] = 0;
	//anpha chac cahn nam dau danh sach,con cac dinh con lai tu 2 den L.size
	//tinh t[u]
	for(j=2; j<=L.size;j++)
	{
		int u = element_at(&L,j);
		t[u] = INFINITY;
		for(x=1; x<=G.n; x++)
		if(G.A[x][u] > 0)
		t[u] = max(t[u],t[x]+d[x]);
	}
	
	//tinh T[u]
	int T[MAX_VERTICES];
	T[beta] = t[beta];
	
	//beta chac chan nam cuoi danh sach, di nguoc lai tiu size -1 ve 1
	for(j=L.size-1; j>=1;j--)
	{
		int u = element_at(&L,j);
		T[u] = 	ININFINITY;
		for(v=1; v<=G.n; v++)
		{
			if(G.A[u][v] > 0)
			T[u] = min(T[u],T[v]-d[u]);
		}
	}
	
	
	for(int i=1; i<=G.n; i++)
	{
		if(T[i] == t[i]) printf("%d\n", i);
	}
	
	 
}
