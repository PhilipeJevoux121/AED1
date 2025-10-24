No* BuscaERemove(No *inicio, int valor) {
    No *atual = inicio;
    No *anterior = NULL;
    while (atual != NULL && atual->info != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Elemento %d não encontrado.\n", valor);
        return inicio; // lista permanece igual
    }

    if (anterior == NULL) {
        inicio = atual->prox; // novo início da lista
    } else {
        anterior->prox = atual->prox; // "pula" o nó removido
    }

    printf("Elemento %d removido.\n", valor);
    free(atual); // libera memória do nó removido
    return inicio;
}
