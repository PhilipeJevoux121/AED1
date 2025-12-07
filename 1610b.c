#include <stdio.h>
#include <stdlib.h>

#define vertice int

typedef struct no *link;

struct no {
    vertice w;
    link prox;
};

typedef struct {
    int V;
    int A;
    link *adj;
} *grafo;

int estado[200000];  

link novoNo(vertice w, link prox){
    link a = malloc(sizeof(struct no));
    a->w = w;
    a->prox = prox;
    return a;
}

grafo inicializacao(int V){
    grafo G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));

    for (int i = 0; i < V; i++)
        G->adj[i] = NULL;

    return G;
}

void inserir(grafo G, vertice v, vertice w){
    // evita duplicada
    for (link a = G->adj[v]; a != NULL; a = a->prox)
        if (a->w == w) return;

    G->adj[v] = novoNo(w, G->adj[v]);
    G->A++;
}

int temCiclo;

void dfs(grafo G, vertice v){
    estado[v] = 1;

    for (link a = G->adj[v]; a != NULL; a = a->prox){
        int w = a->w;

        if (estado[w] == 1){  
            temCiclo = 1;    
            return;
        }
        else if (estado[w] == 0){
            dfs(G, w);
            if (temCiclo) return;
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

        grafo G = inicializacao(N);

        for (int i = 0; i < M; i++){
            int A, B;
            scanf("%d %d", &A, &B);
            inserir(G, A - 1, B - 1);
        }

        for (int i = 0; i < N; i++)
            estado[i] = 0;

        temCiclo = 0;

        for (int i = 0; i < N && !temCiclo; i++)
            if (estado[i] == 0)
                dfs(G, i);

        printf("%s\n", temCiclo ? "SIM" : "NAO");

        for (int i = 0; i < N; i++){
            link a = G->adj[i];
            while (a){
                link tmp = a;
                a = a->prox;
                free(tmp);
            }
        }
        free(G->adj);
        free(G);
    }

    return 0;
}
