
#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    char frase[1001];

    for (int i = 0; i < N; i++) {
        fgets(frase, 1001, stdin);
        int len = strlen(frase);
        if (len > 0 && frase[len - 1] == '\n') frase[len - 1] = '\0';

        int diamante = 0;
        int aberto = 0;

        for (int j = 0; frase[j] != '\0'; j++) {
            if (frase[j] == '<') {
                aberto++;
            } else if (frase[j] == '>') {
                if (aberto > 0) {
                    aberto--;
                    diamante++;
                }
            }
        }
        printf("%d\n", diamante);
    }

    return 0;
}
