#include <stdio.h>

void ordDecre(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int caso;
    scanf("%d", &caso);
    while (caso--) {
        int alunosTotal;
        scanf("%d", &alunosTotal);
        int nota[alunosTotal];
        int notaOrd[alunosTotal];

        for (int i = 0; i < alunosTotal; i++) {
            scanf("%d", &nota[i]);
            notaOrd[i] = nota[i];
        }

        ordDecre(notaOrd, alunosTotal);
        int aux = 0;
        for (int i = 0; i < alunosTotal; i++) {
            if (nota[i] == notaOrd[i]) {
                aux++;
            }
        }
        printf("%d\n", aux);
    }
    return 0;
}
