#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int custo;
} Estrada;

int comparar(const void *a, const void *b) {
    return ((Estrada*)a)->custo - ((Estrada*)b)->custo;
}

// Union-Find
int pai[200005];
int tamanho[200005];

int encontrar(int x) {
    if (pai[x] == x) return x;
    return pai[x] = encontrar(pai[x]);
}

void unir(int a, int b) {
    a = encontrar(a);
    b = encontrar(b);

    if (a == b) return;

    if (tamanho[a] < tamanho[b]) {
        pai[a] = b;
    } else if (tamanho[b] < tamanho[a]) {
        pai[b] = a;
    } else {
        pai[b] = a;
        tamanho[a]++;
    }
}

int main() {
    int cidades, estradas;

    while (1) {
        scanf("%d %d", &cidades, &estradas);
        if (cidades == 0 && estradas == 0)
            break;

        Estrada lista[estradas];
        long long soma_total = 0;

        for (int i = 0; i < estradas; i++) {
            scanf("%d %d %d", &lista[i].u, &lista[i].v, &lista[i].custo);
            soma_total += lista[i].custo;
        }

        // Inicializar Union-Find
        for (int i = 0; i < cidades; i++) {
            pai[i] = i;
            tamanho[i] = 0;
        }

        // Ordenar estradas pelo custo menor
        qsort(lista, estradas, sizeof(Estrada), comparar);

        long long custo_mst = 0;
        int usadas = 0;

        for (int i = 0; i < estradas && usadas < cidades - 1; i++) {
            int u = lista[i].u;
            int v = lista[i].v;
            int c = lista[i].custo;

            if (encontrar(u) != encontrar(v)) {
                unir(u, v);
                custo_mst += c;
                usadas++;
            }
        }

        long long economia = soma_total - custo_mst;
        printf("%lld\n", economia);
    }

    return 0;
}
