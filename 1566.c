#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int freq;
    struct no *esq, *dir;
} No;

No* novoNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->freq = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    } 
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    } else {
        raiz->freq++;
    }
    return raiz;
}

void emOrdem(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        emOrdem(raiz->esq, primeiro);
        for (int i = 0; i < raiz->freq; i++) {
            if (*primeiro) {
                printf("%d", raiz->valor);
                *primeiro = 0;
            } else {
                printf(" %d", raiz->valor);
            }
        }
        emOrdem(raiz->dir, primeiro);
    }
}

void liberar(No* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);
        No* raiz = NULL;

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        int primeiro = 1;
        emOrdem(raiz, &primeiro);
        printf("\n");

        liberar(raiz);
    }

    return 0;
}

