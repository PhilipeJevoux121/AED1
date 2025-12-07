#include <stdio.h>

#define N 400

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int tamanho;
char grade[4*N + 5][4*N + 5];

int linhas, colunas;

void busca_largura(int xi, int yi) {
    static int fila_x[4*N*4*N];
    static int fila_y[4*N*4*N];

    int frente = 0, fundo = 0;

    fila_x[fundo] = xi;
    fila_y[fundo] = yi;
    fundo++;

    grade[xi][yi] = 1;

    while (frente < fundo) {
        int x = fila_x[frente];
        int y = fila_y[frente];
        frente++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < linhas &&
                ny >= 0 && ny < colunas &&
                grade[nx][ny] == 0)
            {
                grade[nx][ny] = 1;
                fila_x[fundo] = nx;
                fila_y[fundo] = ny;
                fundo++;
            }
        }
    }
}

int main() {
    while (scanf("%d", &tamanho) == 1) {

        linhas = 4 * tamanho;
        colunas = 2 * (2*tamanho + 1);

        for (int i = 0; i < linhas; i++)
            for (int j = 0; j < colunas; j++)
                grade[i][j] = 0;

        int linha_par, bi, bj;
        char bloco;

        for (int i = 0; i < 2*tamanho - 1; i++) {
            for (int j = 0; j < tamanho; j++) {
                do { bloco = getchar(); } while (bloco == ' ' || bloco == '\n');

                linha_par = i % 2;
                bi = 2*i + 1;
                bj = 2*(2*j + linha_par) + 1;

                if (bloco == 'H') {
                    grade[bi][bj-1] = 1;
                    grade[bi][bj] = 1;
                    grade[bi][bj+1] = 1;
                    grade[bi][bj+2] = 1;
                } else {
                    grade[bi-1][bj] = 1;
                    grade[bi][bj] = 1;
                    grade[bi+1][bj] = 1;
                    grade[bi+2][bj] = 1;
                }
            }
        }

        int componentes = 0;

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (grade[i][j] == 0) {
                    busca_largura(i, j);
                    componentes++;
                }
            }
        }

        printf("%d\n", componentes - 1);
    }

    return 0;
}
