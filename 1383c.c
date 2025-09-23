#include <stdio.h>
#include <stdlib.h>

int verificarLinha(int **matri) {
    int linha[10];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            linha[j] = matri[i][j];
        }
        for (int k = 0; k < 9; k++) {
            for (int l = k + 1; l < 9; l++) {
                if (linha[k] == linha[l]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificarColuna(int **matri) {
    int coluna[10];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            coluna[j] = matri[j][i];
        }
        for (int k = 0; k < 9; k++) {
            for (int l = k + 1; l < 9; l++) {
                if (coluna[k] == coluna[l]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int verificaBLoco(int **matri) {
    int bloco[10];
    for (int lin = 0; lin < 9; lin += 3) {
        for (int col = 0; col < 9; col += 3) {
            int idx = 0;
            for (int i = lin; i < lin + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    bloco[idx++] = matri[i][j];
                }
            }
            for (int k = 0; k < 9; k++) {
                for (int l = k + 1; l < 9; l++) {
                    if (bloco[k] == bloco[l]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {
    int n, cont = 0;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int **matri = (int **)malloc(9 * sizeof(int *));
        for (int i = 0; i < 9; i++) {
            matri[i] = (int *)malloc(9 * sizeof(int));
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                do {
                    scanf("%d", &matri[i][j]);
                } while (matri[i][j] <= 0 || matri[i][j] > 9);
            }
        }

        int erroL = verificarLinha(matri);
        int erroC = verificarColuna(matri);
        int erroB = verificaBLoco(matri);

        printf("Instancia %d\n", instancia);
        if (erroB && erroC && erroL) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        for (int i = 0; i < 9; i++) {
            free(matri[i]);
        }
        free(matri);
    }

    return 0;
}
