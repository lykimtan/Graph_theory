#include <stdio.h>
 #define MAX_VERTICES 100
 #define MAX_EDGES 100
 
 typedef struct{
 	int n;
 	int A[MAX_VERTICES][MAX_EDGES]	
 }Graph;
 
 void init_graph(Graph* G, int n)
 {
	int i,j;
	G->n = n;
	for(i=1;i<=n;i++)
	 for(j=1; j<=n; j++)
	 	G->A[i][j] = 0;
 }
 
 void add_edge(Graph* G, int x, int y)
 {
 	G->A[x][y]+=1;
 	G->A[y][x]+=1;
 }
 
 int adjacent(Graph* G, int x, int y)
 {
 	return  G->A[x][y] != 0;
 }
 
 
 int degree(Graph* G, int x)
 {
 	int y, deg=0;
 	for( y=1; y<=G->n;y++)
 		if(G->A[x][y] >0)
 		deg++;
 	return deg;
 }
 
 int main()
 {
 	Graph G;
 	int n=4, v;
 	init_graph(&G,n);
 	add_edge(&G,1,2);
 	add_edge(&G,1,3);
 	add_edge(&G,1,3);
 	add_edge(&G,3,4);
 	add_edge(&G,1,4);
 	
 	for(v=1; v<=n ; v++)
 		printf("deg(%d) = %d\n",v, degree(&G,v));
 		return 0;
 }
 
 
 
