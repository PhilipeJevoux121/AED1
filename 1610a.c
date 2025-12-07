#include <stdio.h>
#include <stdlib.h>

typedef int vertice;

typedef struct {
    int V;
    int A;
    int **adj;
} *grafo;

int **iniciaMatriz(int r, int c, int val) {
    int **m = malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        m[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++)
            m[i][j] = val;
    }
    return m;
}

grafo inicia(int V) {
    grafo G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = iniciaMatriz(V, V, 0);
    return G;
}

void insereArco(grafo G, vertice v, vertice w) {
    if (G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->A++;
    }
}

int estado[10001]; 
int temCiclo;

void dfs(grafo G, vertice v) {
    estado[v] = 1;

    for (int w = 0; w < G->V; w++) {
        if (G->adj[v][w]) {
            if (estado[w] == 1) {
                temCiclo = 1;
            }
            else if (estado[w] == 0) {
                dfs(G, w);
            }
        }
    }

    estado[v] = 2;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        grafo G = inicia(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            insereArco(G, A - 1, B - 1);
        }

        for (int i = 0; i < N; i++)
            estado[i] = 0;

        temCiclo = 0;

        for (int i = 0; i < N; i++) {
            if (estado[i] == 0)
                dfs(G, i);
        }

        if (temCiclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
