#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100

typedef struct{
	int u,p;
}ElementType;
//typedef struct {
//	ElementType data[MAX_ELEMENTS];
//	int front, rear;
//}Queue;
//
//void make_null_queue(Queue* Q)
//{
//	Q->front = 0;
//	Q->rear=-1;
//}
//
//void push(Queue* Q, ElementType x)
//{
//	Q->rear++;
//	Q->data[Q->rear] = x;
//}
//
//ElementType top(Queue* Q)
//{
//	return Q->data[Q->front];
//}
//
//void pop(Queue* Q)
//{
//	Q->front++;
//}
//
//int is_empty(Queue *Q)
//{
//	return Q->front > Q->rear;
//}

typedef struct{
	ElementType data[MAX_VERTICES];
	int top;
}Stack;

void make_null_stack(Stack* S)
{
	S->top = -1;
}
void push(Stack* S, ElementType u)
{
	S->top++;
	S->data[S->top]=u;
}
void pop(Stack* S)
{
	S->top--;
}

ElementType top(Stack* S)
{
	return S->tda
}

int empty(Stack* S)
{
	return S->top ==-1;
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



int mark[MAX_VERTICES];
int parent[MAX_VERTICES];

void BFS(Graph* pG, int s)
{
	Stack Q;
	make_null_stack(&Q);
	 ElementType pair;
	 pair.u = s;
	 pair.p = 0;
	 push(&Q,pair);
	 
	 while(!empty(&Q))
	 {
	 	ElementType pair = top(&Q);
	 	pop(&Q);
	 	int u = pair.u;
	 	int p = pair.p;

	 	if(mark[u]!=0)
	 	continue;
	 
	 	mark[u]=1;
	 	parent[u] = p;
	 	printf("%d %d \n",u, parent[u]);
	 	
	 	for(int v =1; v<= pG->n; v++)
	 	if(adjacent(pG,u,v) )
	 	{
	 		ElementType pair;
	 		pair.u = v;
	 		pair.p = u;
	 		push(&Q,pair);
		 }
	 }
}



int main()
{
	freopen("dt.txt","r",stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n,m);
	for (e = 1; e <= m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G,e, u, v);
	}
	
	for(int t =1; t<=G.n; t++)
	{
	    if(mark[t]==0)
	    BFS(&G,t);
	}
	 
}


