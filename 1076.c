#include <stdio.h>
#include <stdlib.h>

#define MAX 60

int numVertices;                    
int matrizAdj[MAX][MAX];
int grauVertice[MAX];
int visitado[MAX];
int paridadeImpar[MAX];       
int adicionado;             

int dfs_contar_impares(int atual, int pai) {
    visitado[atual] = 1;
    int contador = paridadeImpar[atual];
    
    for (int prox = 0; prox < numVertices; prox++) {
        if (matrizAdj[atual][prox] && prox != pai) {
            if (!visitado[prox]) {
                int sub = dfs_contar_impares(prox, atual);
                if (sub % 2 == 1) {
                    adicionado++;
                }
                contador += sub;
            }
        }
    }
    return contador;
}

int main() {
    int testes;
    if (scanf("%d", &testes) != 1) return 0;

    while (testes--) {
        int inicio;
        if (scanf("%d", &inicio) != 1) return 0;

        int numArestas;
        if (scanf("%d %d", &numVertices, &numArestas) != 2) return 0;

        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) 
                matrizAdj[i][j] = 0;

            grauVertice[i] = 0;
            visitado[i] = 0;
            paridadeImpar[i] = 0;
        }

        for (int i = 0; i < numArestas; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) continue;
            if (!matrizAdj[u][v]) {
                matrizAdj[u][v] = matrizAdj[v][u] = 1;
                grauVertice[u]++; 
                grauVertice[v]++;
            }
        }

        int qtdArestas = 0;
        for (int i = 0; i < numVertices; i++)
            for (int j = i+1; j < numVertices; j++)
                if (matrizAdj[i][j]) qtdArestas++;

        for (int i = 0; i < numVertices; i++) 
            paridadeImpar[i] = (grauVertice[i] % 2 != 0) ? 1 : 0;

        if (qtdArestas == 0) {
            printf("0\n");
            continue;
        }

        for (int i = 0; i < numVertices; i++) 
            visitado[i] = 0;

        adicionado = 0;

        dfs_contar_impares(inicio, -1);

        int resultado = qtdArestas + adicionado;
        printf("%d\n", resultado);
    }

    return 0;
}
