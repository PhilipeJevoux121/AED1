#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
  int dado;
  struct Celula *prox;
} Celula;

Celula* criarFila(){
  Celula *ff = (Celula*) malloc(sizeof(Celula));
  if (ff == NULL) {
    printf("Erro de alocação!\n");
    return 0;
  }
  ff->prox = ff;
  return ff;
}

void enfileiraFila(Celula *ff, int x){
  Celula *nova = (Celula*) malloc(sizeof(Celula));
  if (nova == NULL) {
    printf("Erro de alocação!\n);
    exit(1);
  }
  nova->dado = x;

  Celula *aux = ff;
  while(aux->prox != ff){
    aux = aux->prox;
  }
  aux->prox = nova;
  nova->prox = ff;
}

int desenfileiraFila(Celula *ff){
  Celula *primeiro = ff->prox;
  int x = primeiro->dado;
  ff->prox = primeiro->prox;
  free(primeiro);
  return x;
}

void imprimeFila(Celula *ff){
  Celula *aux = ff->prox;
  printf("Fila: ");
  while (aux != ff){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
}

void liberaFila(Celula *ff){
  Celula *aux = ff->prox;
  while(aux != ff){
    Celula *free = aux;
    aux = aux->prox;
    free(free);
  }
  free(ff);
}
