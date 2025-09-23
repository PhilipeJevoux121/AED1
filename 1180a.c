#include <stdio.h>

int main(){

    int N, min, pos;
    
    scanf("%d", &N);

    int r[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &r[i]);
    }

    min = r[0];
    pos = 0;

    for(int i = 1; i < N; i++){
        if(r[i] < min){
            min = r[i];
            pos = i;
        }
    }

    printf("Menor valor: %d\n", min);
    printf("Posicao: %d\n", pos);

    return 0;
}
