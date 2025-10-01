#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char text;
    struct No *prox;
} No;

void push(No **topo, char c){
    No*novoNo = (No*)malloc(sizeof(No));
    novoNo->text = c;
    novoNo->prox = *topo;
    *topo = novoNo;
}

int pop(No **topo){
    if (*topo == NULL) return 0;
    No *aux = *topo;
    *topo = (*topo)->prox;
    free(aux);
    return 1;
}

int ChecarParent(const char *expr){
    No *pilha = NULL;
    for (int i = 0; expr[i] != '\0'; i++){
        if(expr[i] == '(') {
            push(&pilha, '(');
        } else if(expr[i] == ')'){
            if (!pop(&pilha)) {
                return 0;
            }
        }
    }
    if(pilha != NULL) return 0;
    return 1;
}

int main()
{
    char expr[1001];
    while (fgets(expr, sizeof (expr), stdin)){
        expr[strcspn(expr, "\n")] = '\0';
        
        if(ChecarParent(expr)){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }

    return 0;
}
