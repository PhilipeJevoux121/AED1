#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void push(No **topo, int v) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = v;
    novo->prox = *topo;
    *topo = novo;
}

void pop(No **topo) {
    if (*topo == NULL) return;
    No *temp = *topo;
    *topo = (*topo)->prox;
    free(temp);
}

int peek(No *topo) {
    if (topo == NULL) return -1;
    return topo->valor;
}

void clearStack(No **topo) {
    while (*topo) pop(topo);
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        while (1) {
            int target[1001];
            scanf("%d", &target[0]);
            if (target[0] == 0) break;

            for (int i = 1; i < N; i++)
                scanf("%d", &target[i]);

            No *stack = NULL;
            int prox = 1;
            int ok = 1;

            for (int i = 0; i < N; i++) {
                int want = target[i];

                while (prox <= N && peek(stack) != want) {
                    push(&stack, prox);
                    prox++;
                }

                if (peek(stack) != want) {
                    ok = 0;
                    break;
                }

                pop(&stack);
            }

            clearStack(&stack);

            printf(ok ? "Yes\n" : "No\n");
        }

        printf("\n");
    }

    return 0;
}
