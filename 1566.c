#include <stdio.h>

int main() {
    int NC;
    scanf("%d", &NC); // número de casos de teste (cidades)

    while (NC--) {
        int N;
        scanf("%d", &N);

        int freq[231] = {0}; // vetor para contar alturas de 20 a 230

        // leitura das alturas
        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            freq[h]++;
        }

        // impressão em ordem crescente
        int first = 1;
        for (int h = 20; h <= 230; h++) {
            while (freq[h]--) {
                if (first) {
                    printf("%d", h);
                    first = 0;
                } else {
                    printf(" %d", h);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
