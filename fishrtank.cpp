#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
#define MAX_ELEMENTS 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int fail;
int color[MAX_VERTICES];
typedef int ElementType;

typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

// tao danh sach rong

void make_null_list(List* L)
{
	L->size=0;
}
// them mot phan tu vao cuoi danh sach
void push_back(List* L, ElementType x)
{
	L->data[L->size]=x;
	L->size++;
}
//lay mot phan tu tai vi tri i
ElementType element_at(List* L, int index)
{
	return L->data[index-1];
 } 
 
 int count_list(List* L)
 {
 	return L->size;
 }
 
 typedef struct{
 	int n;
 	int A[MAX_VERTICES][MAX_VERTICES];
 }Graph;
 
 void init_graph(Graph* G, int n)
 {
 	int i,j;
 	G->n=n;
 	for(i=1; i<=G->n; i++)
 		for(j=1; j<=G->n; j++)
 		  G->A[i][j]=0;
 }
 
 void add_edge(Graph* G, int x, int y)
 {
 	G->A[x][y]=1; // y ke voi x
 	G->A[y][x]=1;// x ke voi y
 }
 
 int adjacent(Graph* G, int x, int y)
 {
 	return G->A[x][y]!=0;
 }

List neighbors(Graph* G, int x)
{
	int y; 
	List list;
	make_null_list(&list);
	for(y=1; y<=G->n; y++)
		if(adjacent(G,x,y)) push_back(&list,y);
	return list;
}

void colorize(Graph* G, int x, int c)
{
    if(color[x]==-1){
    	color[x]=c;
    List list = neighbors(G,x);
    int j;
    for(j=1; j<=list.size; j++){
    	int y = element_at(&list,j);
        colorize(G,y,!c);
	}
	}
    else
    if (color[x]!=c)
    fail=1;
}

int is_bigraph(Graph* G)
{
    int j;
    for(j=1; j<=G->n; j++)
    {
        color[j]=-1;
    }
    fail=0;
    colorize(G,1,0);
    return !fail;
}




int main()
{
// 	freopen("bigraph.txt","r",stdin);
	Graph G;
	int n,m,u,v,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	
	for(e=1; e<=m; e++)
	{
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	int cnt1=0;
	int cnt2=0;
	if(!is_bigraph(&G)) printf("-1 -1");
	else
	{
		for(int i=1; i<=G.n; i++)
	{
		if(color[i]!=1)
		cnt1++;
	}
	for(int i=1; i<=G.n; i++)
	{
		if(color[i]==1)
		cnt2++;
	}
	if(cnt1!=0 && cnt2!=0)
	printf("%d %d",cnt1,cnt2);
	else printf("-1 -1");
	}
	
	
	
}



