#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int tam;
    
    scanf("%d", &tam);

    int *vetor = (int*) malloc(tam * sizeof(int));

    if (vetor == NULL){
        printf("erro de alocação");
        return 1;
    }

    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    int min = vetor[0];
    int posicao = 0;

    for (int i = 1; i < tam; i++){
        if (vetor[i] < min){
            min = vetor[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", min);
    printf("Posicao: %d\n", posicao);

    free(vetor);

    return 0;
}
