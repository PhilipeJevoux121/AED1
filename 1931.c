#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int destino;
    int custo;
} Aresta;

typedef struct {
    int cidade;
    int paridade;  
    int distancia;
} No;

typedef struct {
    No dados[200005];
    int tamanho;
} HeapMin;

void troca(No *a, No *b) {
    No t = *a; *a = *b; *b = t;
}

void inserirHeap(HeapMin *h, No valor) {
    h->dados[++h->tamanho] = valor;

    int i = h->tamanho;
    while (i > 1 && h->dados[i].distancia < h->dados[i/2].distancia) {
        troca(&h->dados[i], &h->dados[i/2]);
        i /= 2;
    }
}

No removerHeap(HeapMin *h) {
    No topo = h->dados[1];
    h->dados[1] = h->dados[h->tamanho--];

    int i = 1;
    while (1) {
        int esq = 2*i, dir = esq + 1, menor = i;

        if (esq <= h->tamanho && h->dados[esq].distancia < h->dados[menor].distancia)
            menor = esq;
        if (dir <= h->tamanho && h->dados[dir].distancia < h->dados[menor].distancia)
            menor = dir;

        if (menor == i) break;

        troca(&h->dados[i], &h->dados[menor]);
        i = menor;
    }

    return topo;
}

int heapVazia(HeapMin *h) {
    return h->tamanho == 0;
}

int main() {
    int cidades, estradas;

    while (scanf("%d %d", &cidades, &estradas) != EOF) {

        Aresta *lista[cidades + 1];
        int qtd[cidades + 1];

        for (int i = 1; i <= cidades; i++) {
            lista[i] = NULL;
            qtd[i] = 0;
        }

        for (int i = 0; i < estradas; i++) {
            int c1, c2, custo;
            scanf("%d %d %d", &c1, &c2, &custo);

            qtd[c1]++;
            lista[c1] = realloc(lista[c1], qtd[c1] * sizeof(Aresta));
            lista[c1][qtd[c1]-1].destino = c2;
            lista[c1][qtd[c1]-1].custo = custo;

            qtd[c2]++;
            lista[c2] = realloc(lista[c2], qtd[c2] * sizeof(Aresta));
            lista[c2][qtd[c2]-1].destino = c1;
            lista[c2][qtd[c2]-1].custo = custo;
        }

        int dist[cidades + 1][2];

        for (int i = 1; i <= cidades; i++) {
            dist[i][0] = INF;
            dist[i][1] = INF;
        }

        HeapMin heap;
        heap.tamanho = 0;

        dist[1][0] = 0;
        inserirHeap(&heap, (No){1, 0, 0});

        while (!heapVazia(&heap)) {
            No atual = removerHeap(&heap);

            int cidade = atual.cidade;
            int paridade = atual.paridade;
            int distancia = atual.distancia;

            if (distancia > dist[cidade][paridade])
                continue;

            for (int i = 0; i < qtd[cidade]; i++) {
                int prox = lista[cidade][i].destino;
                int custo = lista[cidade][i].custo;

                int novaParidade = 1 - paridade;
                int novoCusto = distancia + custo;

                if (novoCusto < dist[prox][novaParidade]) {
                    dist[prox][novaParidade] = novoCusto;
                    inserirHeap(&heap, (No){prox, novaParidade, novoCusto});
                }
            }
        }

        if (dist[cidades][0] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[cidades][0]);

        for (int i = 1; i <= cidades; i++)
            free(lista[i]);
    }

    return 0;
}
