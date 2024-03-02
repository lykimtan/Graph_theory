#include <stdio.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
int min(int a, int b)
{
	if(a<b) return a;
	return b;
}
typedef struct{
    int data[MAX_VERTICES];
    int top;
}Stack;

void make_null_stack(Stack* S)
{
    S->top =-1;
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

typedef struct{
    int data[MAX_ELEMENTS];
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
    for(int i=1; i<=G->n; i++)
        for(int j=1; j<=G->n; j++)
            G->A[i][j]=0;
}

void add_edge(Graph* G, int x, int y)
{
    G->A[x][y]=1; //y lien ke voi x;
}

void add_edges(Graph* G, int x,int y)
{
    G->A[x][y]=1;
    G->A[y][x]=1;
}

int adjacent(Graph* G, int x, int y)
{
    return G->A[x][y]!=0;
}

List neighbors(Graph* G, int x)
{
    List list;
    make_null(&list);
    for(int i=1; i<=G->n; i++)
    {
        if(adjacent(G,x,i))
        push_back(&list,i);
    }
    return list;
}

Stack S;
int num[MAX_VERTICES];
int min_num[MAX_VERTICES];
int on_stack[MAX_VERTICES];
int k;
int cnt = 0;

void strong_connect(Graph* G, int x)
{
    num[x]= min_num[x]= k;
    k++;
    push(&S,x);
    on_stack[x]=1;
    List list = neighbors(G,x);
    
    for(int j=1; j<=list.size; j++)
    {
        int y= element_at(&list,j);
        if(num[y] < 0 )
        {
            strong_connect(G,y);
            min_num[x]  = min(min_num[x], min_num[y]);
        }else if(on_stack[y])
        min_num[x] = min(min_num[x], min_num[y]);
    }
    
//    printf("min_num[%d] = %d\n",x,min_num[x]);
    
    if(num[x]==min_num[x])
    {
//        printf("%d la dinh khop\n",x);
        int w;
        do{
            w=top(&S);
            pop(&S);
            cnt++;
            on_stack[w]=0;
        }while(w!= x);
    }
    }

int main()
{
     freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? dòng này.
	Graph G;
	int n, m, u, v, e,p;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v,&p);
		if(p==1)
		add_edge(&G, u, v);
		else
		add_edges(&G,u,v);
	}
	
	for(int i=1; i<=n; i++)
	{
	    num[i]=-1;
	    on_stack[v]=0;
	}	
	k=1;
	make_null_stack(&S);
	
	strong_connect(&G,1);
	
	for(int i=1; i<=n; i++)
	{
		if(min_num[i]!= min_num[1]){
			printf("NO");
			return 0;
		}
	}
	 printf("OKIE");
	
}
    
    
