#include <stdio.h>
#define MAX_EDGE 100 
#define NO_EDGE 0
#define oo 9999
int min(int a, int b)
{
	if(a<b) return a;
	return b;
}

typedef struct{
	int data[100];
	int front, rear;
}Queue;

void make_null(Queue *Q)
{
	Q->front = 0;
	Q->rear =-1;
}

void enqueue(Queue* Q, int x)
{
	Q->rear++;
	Q->data[Q->rear] = x;
}

int front(Queue* Q)
{
	return Q->data[Q->front];
}

void dequeue(Queue* Q)
{
	Q->front++;
}

int is_empty(Queue* Q)
{
	return Q->front > Q->rear;
}

typedef struct{
	int C[100][100];
	int F[100][100];
	int n;
}Graph;

typedef struct{
	int dir;
	int p;
	int sigma;
}lable;

lable lables[100];

void init_flow(Graph* pG)
{
	int u,v;
	for(v=1;v<=pG->n;v++)
	for(u=1;u<=pG->n;u++)
	{
			pG->F[u][v] = 0;
			pG->C[u][v] = 0;
	}

	
}

void init_graph(Graph* g, int n)
{
	g->n = n;
	for(int u=0; u<n;u++)
	for(int v = 0; v<n;v++)
	{
		g->C[u][v] = 0;
		g->F[u][v] = 0;
	}
}
int fordfullkerson(Graph* pG, int s, int t)
{
	init_flow(pG);
	int max_flow = 0;
	Queue q;
	do{
		for(int u=1;u<=pG->n;u++)
		lables[u].dir  = 0;
		
		//gan nhan s
		lables[s].dir = +1;
		lables[s].p = s;
		lables[s].sigma = oo;
		//khoi tao q rong
		make_null(&q);
		enqueue(&q,s);
		int found = 0;
		while(!is_empty(&q))
		{
			int u = front(&q);
			dequeue(&q);
			for(int v=1;v<=pG->n;v++)
			{
				if(pG->C[u][v]!=NO_EDGE && lables[v].dir ==0 && pG->F[u][v] < pG->C[u][v])
				{
					lables[v].dir = +1;
					lables[v].p = u;
					lables[v].sigma = min(lables[u].sigma,pG->C[u][v] - pG->F[u][v]);
					enqueue(&q,v);
				}
			}
			
			for(int x = 1; x<=pG->n;x++)
			{
				if(pG->C[x][u] !=NO_EDGE && lables[x].dir == 0 && pG->F[x][u] > 0){
					lables[x].dir = -1;
					lables[x].p = u;
					lables[x].sigma = min(lables[u].sigma,pG->F[x][u]);
					enqueue(&q,x);
				}
			}
			
			if(lables[t].dir != 0)
			{
				found = 1;
				break;
			}
		}
		int max_flow = 0;
		do{
			if(found ==1)
			{
				int sigma = lables[t].sigma;
				int u = t;
				while(u!=s){
					int p = lables[u].p;
					if(lables[u].dir > 0) pG->F[p][u] += sigma;
					else pG->F[u][p] -=sigma;
					u = p;
			}
				max_flow +=sigma; 
			} else break;
		}while(1);
		return max_flow;
	}while(1);
}

int main()
{
	Graph g;
	int n,m,u,v,e,c;
	freopen("prim.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&g,n);
	
	for(e=0;e<m;e++)
	{
		scanf("%d%d%d",&u,&v,&c);
		g.C[u][v] = c;
	}
	int max_flow = fordfullkerson(&g,1,n);
	printf("Max flow %d",max_flow);
	return 0;
}
