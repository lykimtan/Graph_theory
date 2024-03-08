#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Ð?nh nghia d? th? có hu?ng
typedef struct {
    int n; // S? d?nh
    int A[MAX_VERTICES][MAX_VERTICES]; // Ma tr?n k?
} Graph;

// Kh?i t?o d? th?
void init_graph(Graph *G, int n) {
    G->n = n;
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G->A[i][j] = 0;
        }
    }
}

// Thêm c?nh vào d? th?
void add_edge(Graph *G, int x, int y) {
    G->A[x][y] = 1;
}

// Duy?t d? th? theo chi?u sâu
void DFS(Graph *G, int mark[], int u) {
    if (mark[u]) return;
    mark[u] = 1;
    int v;
    for (v = 1; v <= G->n; v++) {
        if (G->A[u][v] != 0) {
            DFS(G, mark, v);
        }
    }
}

// Ki?m tra xem có chung d?i th? c?nh tranh hay không
int has_common_enemy(Graph *G, int x, int y) {
    int mark[MAX_VERTICES] = {0}; // M?ng dánh d?u d?nh dã du?c duy?t
    DFS(G, mark, x);
    if (mark[y]) return 1;
    return 0;
}

int main() {
    Graph G;
    int n, m, u, v, e, x, y,w;
    freopen("HeSinhThaiRung.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= n; e++) {
       for(v=1; v<=n; v++)
       {
       	scanf("%d",&w);
       	if(w==1) add_edge(&G,e,v+1);
	   }
    }
    scanf("%d%d", &x, &y);
    int found = 0;
    for (int i = 1; i <= n; i++) {
        if (G.A[x][i] == 1 && G.A[y][i] == 1) {
            found = 1;
            printf("%d ", i);
        }
    }
    if (!found) printf("KHONG CHUNG DOI THU\n");

return 0;

}

