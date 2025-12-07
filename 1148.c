#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int destino;
    int tempo;
} Ligacao;

typedef struct {
    int cidade;
    int distancia;
} No;

typedef struct {
    No *dados;
    int tamanho;
    int capacidade;
} HeapMin;

HeapMin* criaHeap(int capacidade) {
    HeapMin *h = malloc(sizeof(HeapMin));
    h->dados = malloc(sizeof(No) * (capacidade + 1));
    h->tamanho = 0;
    h->capacidade = capacidade;
    return h;
}

void troca(No *a, No *b) {
    No tmp = *a; *a = *b; *b = tmp;
}

void inserirHeap(HeapMin *h, int cidade, int distancia) {
    h->tamanho++;
    h->dados[h->tamanho].cidade = cidade;
    h->dados[h->tamanho].distancia = distancia;

    int i = h->tamanho;
    while (i > 1 && h->dados[i].distancia < h->dados[i/2].distancia) {
        troca(&h->dados[i], &h->dados[i/2]);
        i /= 2;
    }
}

No removerHeap(HeapMin *h) {
    No topo = h->dados[1];
    h->dados[1] = h->dados[h->tamanho];
    h->tamanho--;

    int i = 1;
    while (1) {
        int esq = 2*i, dir = esq+1, menor = i;

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
    int cidades, ligacoes;

    while (scanf("%d %d", &cidades, &ligacoes) && !(cidades == 0 && ligacoes == 0)) {

        int matriz[501][501] = {0}; 

        Ligacao **lista = malloc((cidades+1) * sizeof(Ligacao*));
        int *qt = calloc(cidades+1, sizeof(int));

        for (int i = 1; i <= cidades; i++)
            lista[i] = NULL;

        int a, b, t;

        for (int i = 0; i < ligacoes; i++) {
            scanf("%d %d %d", &a, &b, &t);
            matriz[a][b] = t;
          
            qt[a]++;
            lista[a] = realloc(lista[a], qt[a] * sizeof(Ligacao));
            lista[a][qt[a]-1].destino = b;
            lista[a][qt[a]-1].tempo = t;
        }
      
        for (int i = 1; i <= cidades; i++) {
            for (int j = 1; j <= cidades; j++) {
                if (matriz[i][j] && matriz[j][i]) {

                    for (int k = 0; k < qt[i]; k++)
                        if (lista[i][k].destino == j)
                            lista[i][k].tempo = 0;

                    for (int k = 0; k < qt[j]; k++)
                        if (lista[j][k].destino == i)
                            lista[j][k].tempo = 0;
                }
            }
        }

        int consultas;
        scanf("%d", &consultas);

        while (consultas--) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            int *dist = malloc((cidades+1) * sizeof(int));
            for (int i = 1; i <= cidades; i++)
                dist[i] = INF;

            HeapMin *heap = criaHeap(200000);
            dist[origem] = 0;
            inserirHeap(heap, origem, 0);

            while (!heapVazia(heap)) {
                No atual = removerHeap(heap);
                int c = atual.cidade;

                if (atual.distancia > dist[c]) continue;
                if (c == destino) break;

                for (int i = 0; i < qt[c]; i++) {
                    int prox = lista[c][i].destino;
                    int peso = lista[c][i].tempo;

                    if (dist[c] != INF && dist[c] + peso < dist[prox]) {
                        dist[prox] = dist[c] + peso;
                        inserirHeap(heap, prox, dist[prox]);
                    }
                }
            }

            if (dist[destino] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[destino]);

            free(dist);
            free(heap->dados);
            free(heap);
        }

        printf("\n");

        for (int i = 1; i <= cidades; i++)
            free(lista[i]);

        free(lista);
        free(qt);
    }

    return 0;
}
