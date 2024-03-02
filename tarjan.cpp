#include <stdio.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
typedef int ElementType;

typedef struct{
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;
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
    G->A[x][y]=1; // y ke voi x;
    G->A[y][x]=1; //x ke voi y
}

int adjacent(Graph* G, int x, int y)
{
    return G->A[x][y]!=0;
}

typedef struct{
    int data[MAX_VERTICES];
    int top;
}Stack;

void make_null_stack(Stack* S)
{
    S->top=-1;
}

void push(Stack* S, int u)
{
    S->top++;
    S->data[S->top]=u;
}

void pop(Stack* S)
{
    S->top--;
}

int top(Stack* S)
{
    return S->data[S->top];
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

void make_null(List* L)
{
	L->size=0;
}

void push_back(List* L, int x)
{
	L->data[L->size]=x;
	L->size++;
}

int element_at(List* L, int i)
{
	return L->data[i-1];
}
List neighbors(Graph* G, int x)
{
	int y; 
	List list;
	make_null(&list);
	for(y=1; y<=G->n; y++)
	{
		if(adjacent(G,x,y))
		push_back(&list,y);
		return list;
	}
}
int num[MAX_VERTICES], min_num[MAX_VERTICES];
int k;
Stack S;
int on_stack[MAX_VERTICES];
int cnt=0;

void strong_connect(Graph* G, int x)
{
	num[x]=min_num[x] = k;
	k++;
	push(&S,x);
	on_stack[x]=1;
	
	List list = neighbors(G,x);
	int j;
	for(j=1; j<=list.size; j++){
		int y=element_at(&list,j);
		if(num[y] <0)
		{
			strong_connect(G,y);
			min_num[x]=min(min_num[x], min_num[y]);
		}else if(on_stack[y])
		 min_num[x]= min(min_num[x],num[y]);
	}
	
	printf("min_num[%d] = %d\n",x,min_num[x]);
	
	if(num[x]==min_num[x])
	{
		printf("%d la dinh khop.\n",x);
		int w;
		do{
			w=top(&S);
			pop(&S);
			on_stack[w]=0;
		}while( w!=x);
	}
}

int main()
{
	freopen("dt.txt", "r", stdin); 
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	
	for(int j=1; j<=n; j++)
	{
		num[j]=-1;
		on_stack[j]=0;
	}
	
	k=1;
	
	for(int j=1; j<=n; j++)
	{
		if(num[j]==-1)
		strong_connect(&G,j);
	}
	
	
}
