#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} No;

typedef struct fila {
    No* inicio;
    No* fim;
} Fila;

void iniciarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(Fila* f, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int remover(Fila* f) {
    if (f->inicio == NULL) return -1;

    No* temp = f->inicio;
    int valor = temp->valor;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
        f->fim = NULL;

    free(temp);
    return valor;
}

int tamanho(Fila* f) {
    int cont = 0;
    No* atual = f->inicio;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int frente(Fila* f) {
    if (f->inicio == NULL) return -1;
    return f->inicio->valor;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        Fila f;
        iniciarFila(&f);

        for (int i = 1; i <= n; i++) {
            inserir(&f, i);
        }

        printf("Discarded cards:");
        int primeira = 1;
      
        while (tamanho(&f) > 1) {

            int descartada = remover(&f);

            if (primeira) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }

            int mover = remover(&f);
            inserir(&f, mover);
        }

        printf("\nRemaining card: %d\n", frente(&f));
        remover(&f);
    }

    return 0;
}
