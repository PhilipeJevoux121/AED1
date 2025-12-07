#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila {
    int x, y;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *ini;
    NoFila *fim;
} Fila;

// Inicializa fila
void initFila(Fila *f) {
    f->ini = NULL;
    f->fim = NULL;
}

// Enfileira
void push(Fila *f, int x, int y) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));
    novo->x = x;
    novo->y = y;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->ini = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

// Desenfileira
int pop(Fila *f, int *x, int *y) {
    if (f->ini == NULL) return 0;

    NoFila *tmp = f->ini;
    *x = tmp->x;
    *y = tmp->y;

    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;

    free(tmp);
    return 1;
}

char grid[1025][1025];
int vis[1025][1025];

int N, M;

// BFS para "pintar" a região
void bfs(int sx, int sy) {
    Fila f;
    initFila(&f);

    push(&f, sx, sy);
    vis[sx][sy] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (f.ini != NULL) {
        int x, y;
        pop(&f, &x, &y);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!vis[nx][ny] && grid[nx][ny] == '.') {
                    vis[nx][ny] = 1;
                    push(&f, nx, ny);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%s", grid[i]);

    int clicks = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                bfs(i, j);  // pinta toda a região branca
                clicks++;   // 1 clique para essa região
            }
        }
    }

    printf("%d\n", clicks);

    return 0;
}
