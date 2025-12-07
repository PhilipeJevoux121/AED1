#include <stdio.h>
#include <string.h>

#define MAX 10000

int inverter(int x){
    int r = 0;
    while (x > 0){
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int main(){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--){
        int A, B;
        scanf("%d %d", &A, &B);

        static int vetor[MAX + 1];
        for (int i = 0; i <= MAX; i++) vetor[i] = -1;
        static int i[MAX + 5];
        int cabeca = 0, pe = 0;

        vetor[A] = 0;
        i[pe++] = A;

        while (cabeca < pe){
            int u = i[cabeca++];
            if (u == B){
                printf("%d\n", vetor[u]);
                break;
            }
            int v = u + 1;
            if (v <= MAX && vetor[v] == -1){
                vetor[v] = vetor[u] + 1;
                i[pe++] = v;
            }
            v = inverter(u);
            if (v <= MAX && vetor[v] == -1){
                vetor[v] = vetor[u] + 1;
                i[pe++] = v;
            }
        }
    }
    return 0;
}
