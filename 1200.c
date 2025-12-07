#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char valor;
    struct cel *esq;
    struct cel *dir;
} celula;

typedef celula* arvore;

celula *novaCelula(char valor) {
    celula *novo = (celula *) malloc(sizeof(celula));
    novo->valor = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

celula *buscar(arvore r, char k) {
    if (r == NULL || r->valor == k) 
        return r;

    if (r->valor > k) 
        return buscar(r->esq, k);
    else 
        return buscar(r->dir, k);
}

arvore inserir(arvore r, celula *novo) {
    if (r == NULL) return novo;

    celula *f = r, *p = NULL;

    while (f != NULL) {
        p = f;
        if (novo->valor < f->valor)
            f = f->esq;
        else
            f = f->dir;
    }

    if (novo->valor < p->valor) 
        p->esq = novo;
    else 
        p->dir = novo;

    return r;
}

void infix(arvore r, int *primeiro) {
    if (r == NULL) return;
    infix(r->esq, primeiro);
    if (!*primeiro) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
    infix(r->dir, primeiro);
}

void prefix(arvore r, int *primeiro) {
    if (r == NULL) return;
    if (!*primeiro) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
    prefix(r->esq, primeiro);
    prefix(r->dir, primeiro);
}

void posfix(arvore r, int *primeiro) {
    if (r == NULL) return;
    posfix(r->esq, primeiro);
    posfix(r->dir, primeiro);
    if (!*primeiro) printf(" ");
    printf("%c", r->valor);
    *primeiro = 0;
}

int main() {
    arvore r = NULL;
    char comando[20];

    while (scanf("%s", comando) != EOF) {

        if (strcmp(comando, "I") == 0) {
            char x;
            scanf(" %c", &x);
            r = inserir(r, novaCelula(x));
        }

        else if (strcmp(comando, "P") == 0) {
            char x;
            scanf(" %c", &x);
            celula *res = buscar(r, x);
            if (res == NULL) printf("%c nao existe\n", x);
            else printf("%c existe\n", x);
        }

        else if (strcmp(comando, "INFIXA") == 0) {
            int first = 1;
            infix(r, &first);
            printf("\n");
        }

        else if (strcmp(comando, "PREFIXA") == 0) {
            int first = 1;
            prefix(r, &first);
            printf("\n");
        }

        else if (strcmp(comando, "POSFIXA") == 0) {
            int first = 1;
            posfix(r, &first);
            printf("\n");
        }
    }

    return 0;
}
