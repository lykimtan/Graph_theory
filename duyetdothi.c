#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500
/* Khai bao Stack*/
#define MAX_ELEMENTS 100
typedef struct {
int data[MAX_ELEMENTS];
int size;
} Stack;
void make_null_stack(Stack* S) {
S->size = 0;
}
void push(Stack* S, int x) {
S->data[S->size] = x;
S->size++;
}
int top(Stack* S) {
return S->data[S->size - 1];
}
void pop(Stack* S) {
S->size--;
}
int empty(Stack* S) {
return S->size == 0;
}

/* KHAI BAO VA DINH NGHIA CTDL DANH SACH */
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
L->data[L->size] = x;
L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 
*/
ElementType element_at(List* L, int i) {
return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}
//****************************
typedef struct {
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
} Graph;

void init_graph(Graph* G, int n, int m)
{
	int i,j;
	G->n=n;
	G->m=m;
	for(i=1;i<= n;i++)
		for(j=1; j<= m; j++)
			G->A[i][j]=0;
}

void add_edge(Graph* G, int e, int x, int y)
{
	G->A[x][e]=1;
	G->A[y][e]=1;
}

int degree(Graph* G, int x)
{
	int e, deg = 0;
	for(e=1; e<= G->m ;e++)
		if(G->A[x][e]==1)
		deg++;
		return deg;
}

List neighbors(Graph* G, int x) {
int y;
List list;
make_null(&list);
for (y = 1; y <= G->n; y++)
if (adjacent(G, x, y))
push_back(&list, y);
return list;
}

void deep_first_search(Graph* G)
{
	Stack L;
	int mark[MAX_VERTICES];
	make_null_stack(&L);
	int j;
	for(j=1; j<=G->n; j++)
	mark[j]=0;
	push(&L,1);//dua 1 vao ngan xep , va bat dau duyet tu dinh 1
	while(!is_empty(L))
	{
		int x = top(&L);
		pop(&L);
		if(mark[x] != 0)
		continue;
		printf("Duyet %d\n",x);
		mark[x]=1;
		List list=neighbors(G,x);
		for(j=1;j<=list.size; j++)
		{
			int y = element_at(&list,j);
			push(&L,y);
		}
	}
}




int main()
{
	Graph G;
	int n =4, m=5,v;
	init_graph(&G,n,m);
	add_edge(&G,1,1,2);
	add_edge(&G,2,1,3);
	add_edge(&G,3,1,3);
	add_edge(&G,4,3,4);
	add_edge(&G,5,1,4);
	
	deep_first_search(&G);
	
}








