#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no *esq, *dir;
} No;

No* novoNo(int v) {
    No* n = malloc(sizeof(No));
    n->val = v;
    n->esq = n->dir = NULL;
    return n;
}

No* insert(No* raiz, int v) {
    if (raiz == NULL) return novoNo(v);
    if (v < raiz->val) raiz->esq = insert(raiz->esq, v);
    else raiz->dir = insert(raiz->dir, v);
    return raiz;
}

typedef struct fila {
    No* data[600];
    int ini, fim;
} Fila;

void iniciarFila(Fila* q) {
    q->ini = q->fim = 0;
}

void push(Fila* q, No* x) {
    q->data[q->fim++] = x;
}

No* pop(Fila* q) {
    return q->data[q->ini++];
}

int empty(Fila* q) {
    return q->ini == q->fim;
}


void bfs(No* raiz) {
    Fila q;
    iniciarFila(&q);

    push(&q, raiz);
    int first = 1;

    while (!empty(&q)) {
        No* u = pop(&q);

        if (!first) printf(" ");
        first = 0;
        printf("%d", u->val);

        if (u->esq) push(&q, u->esq);
        if (u->dir) push(&q, u->dir);
    }
}

int main() {
    int C; 
    scanf("%d", &C);

    for (int c = 1; c <= C; c++) {

        int N;
        scanf("%d", &N);

        No* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            raiz = insert(raiz, x);
        }

        printf("Case %d:\n", c);
        bfs(raiz);
        printf("\n\n");
    }

    return 0;
}
