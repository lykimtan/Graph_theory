#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX_ELEMENTS 100


typedef struct{
    int data[MAX_ELEMENTS];
    int size;
}List;

void make_null(List* L)
{
    L->size = 0;
}

void push_back(List* L,int x)
{
    L->data[L->size] = x;
    L->size++;
}

int element_at(List* L, int x)
{
	return L->data[x-1];
}

typedef struct{
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
}Graph;

void init_graph(Graph* G, int n)
{
    G->n = n;
    for(int i=1; i<=G->n; i++)
    for(int j=1; j<=G->n; j++)
     G->A[i][j]=0;
}

void add_edge(Graph* G, int x, int y)
{
    G->A[x][y]=1;
    G->A[y][x] = 1;
}

int adjacent(Graph* G, int x, int y)
{
    return G->A[x][y]!=0;
}

List neighbors(Graph* G, int x)
{
    List L;
    make_null(&L);
    for(int i = 1; i<=G->n; i++)
    {
        if(adjacent(G,x,i))
        push_back(&L,i);
    }
    return L;
}



int main()
{
    freopen("dt.txt","r",stdin);
    Graph G;
    int n,m,x,u,v,i,j,y;
    scanf("%d",&n);
    init_graph(&G,n);
    
    for(int e=1; e<=n; e++)
    {
    for(i=1; i<=n; i++)
     {
        scanf("%d", &x);
        if(x!=0) add_edge(&G,e,i);
     }
    }
    
    scanf("%d%d",&x,&y);
    
    List l1 = neighbors(&G,x);
    List l2 = neighbors(&G,y);
    List kq;
    make_null(&kq);
   for(i=1; i<=l1.size; i++)
   for(j=1; j<=l2.size; j++)
   {
   	  if(element_at(&l1,i) == element_at(&l2,j))
   	  push_back(&kq,element_at(&l1,i));
   }
    
    if(kq.size == 0) printf("KHONG CHUNG DOI THU");
    else 
    {
    	for(i=1; i<=kq.size; i++)
    	{
    		printf("%d ",element_at(&kq,i));
		}
	}
}
