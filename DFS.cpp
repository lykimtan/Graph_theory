#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100
typedef int ElementType;
//khai bao kieu du lieu list

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

void make_null(List* L)
{
	L->size=0;
}

void push_back(List* L, ElementType x)
{
	L->data[L->size]=x;
	L->size++;
}

ElementType element_at(List* L, int index)
{
	return L->data[index-1]; 
}
//khai bao stack
typedef struct {
	int data[MAX_ELEMENTS];
	int top;
}Stack;

void make_null_stack(Stack* s)
{
	s->top=-1;
}

void push(Stack* S, int x)
{
	S->top++;
	S->data[S->top]=x;
}

int top(Stack* S)
{
	return S->data[S->top];
}

void pop(Stack* S)
{
	S->top--;
}

int is_empty(Stack *S)
{
	return S->top==-1;
}

typedef struct{
	int n,m;
	int  A[MAX_VERTICES][MAX_ELEMENTS];
}Graph;

void init_graph(Graph* G, int n, int m)
{
	G->n=n;
	G->m = m;
	for(int i =1; i<=n; i++)
	for(int j=1; j<=m; j++)
	G->A[i][j]=0;
}

void add_edge(Graph* G, int e, int x, int y)
{
	G->A[x][e] = 1;
	G->A[y][e]= 1;
}

int adjacent(Graph* G, int x, int y)
{
	int e;
	for(e=1; e<=G->m; e++)
	if(G->A[x][e]==1 && G->A[y][e]==1)
	return 1;// neu trong 1 cot bat ki ma hang x cot e = 1 va hang y cot e cung bang 1
	return 0;
}

int degree(Graph* G, int x)
{
	int e, deg=0;
	for(e=1; e<= G->m; e++)
	if(G->A[x][e]==1)
	deg++;
	return deg;
}

List neighbors(Graph* G, int x)
{
	int y;
	List list;
	make_null(&list);
	for(y=1; y<=G->n; y++)
	if(adjacent(G,x,y))
	push_back(&list,y);
	return list;
}

//void breath_search_first(Graph* G)
//{
//	Queue L;
//	int mark[MAX_VERTICES];
//	make_null_queue(&L);
//	
//	int j;
//	for(j=1;j<=G->n;j++)
//	{
//		mark[j] =0;
//	}
//	push(&L,1);
//	while(!is_empty(&L))
//	{
//		int x = top(&L);
//		pop(&L);
//		if(mark[x]!=0)
//		continue;
//		printf("%d\n",x);
//		mark[x] =1;// danh dau la da duyet
//		List list = neighbors(G,x);
//		for(j=1; j<= list.size; j++)
//		{
//			int y = element_at(&list, j);
//			push(&L,y);
//		}
//	}
//	
//	
//}
int mark[MAX_VERTICES];
void DFS(Graph* pG, int s)
{
	Stack Q;
	make_null_stack(&Q);
	 push(&Q,s);
	 while(!is_empty(&Q))
	 {
	 	int u = top(&Q);
	 	pop(&Q);
	 	if(mark[u]!=0)
	 	continue;
	 	printf("%d \n",u);
	 	mark[u]=1;
	 	
	 	for(int v =1; v<= pG->n; v++)
	 	if(adjacent(pG,u,v) )
	 	push(&Q,v);
	 }
}



int main()
{
	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n,m);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G,e, u, v);
	}
	
	for(int t=1; t<= G.n; t++)
	{
		if(mark[t]==0) 
		DFS(&G,t);
	}

	
	
}


