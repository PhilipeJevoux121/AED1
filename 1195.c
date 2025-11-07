
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* novoNo (int n){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = n;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserirNo (No* raiz, int n){
    if (raiz == NULL){
        return novoNo(n);
    }
    if (n < raiz->valor){
        raiz->esq = inserirNo(raiz->esq, n);
        
    }else{
        raiz->dir = inserirNo(raiz->dir, n);
    }
    return raiz;
}

void posOrdem(No* raiz, int *pri){
    if (raiz != NULL){
        posOrdem(raiz->esq, pri);
        posOrdem(raiz->dir, pri);
        if(*pri) {
            printf("%d", raiz->valor);
            *pri = 0;
        }else{
            printf(" %d", raiz->valor);
        }
    }
}

void emOrdem(No* raiz, int *pri){
    if(raiz != NULL){
        emOrdem(raiz->esq, pri);
        if(*pri){
            printf("%d", raiz->valor);
            *pri = 0;
        }else{
            printf(" %d", raiz->valor);
        }
        emOrdem(raiz->dir, pri);
    }
}

void preOrdem(No* raiz, int *pri){
    if(raiz != NULL){
        if(*pri){
            printf("%d", raiz->valor);
            *pri = 0;
        }else{
            printf(" %d", raiz->valor);
        }
        preOrdem(raiz->esq, pri);
        preOrdem(raiz->dir, pri);
    }
}

void liberar(No* raiz){
    if(raiz != NULL){
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main()
{
    int C, N, valor;
    scanf("%d", &C);
    
    for(int caso = 1; caso <= C; caso++){
        scanf("%d", &N);
        No* raiz = NULL;
        
        for(int i = 0; i < N; i++){
            scanf("%d", &valor);
            raiz = inserirNo(raiz, valor);
        }
        
        printf("Case %d:\n", caso);
        
        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("In..: ");
        emOrdem(raiz, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n");
        
        liberar(raiz);
        
    
    }
    return 0;
}
