No* BuscaEInsere(int x, No **inicio) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->info < x) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->info == x) {
        return atual;
    }

    No *novo = (No*) malloc(sizeof(No));
    novo->info = x;
    novo->prox = atual;
    if (anterior == NULL) {
        *inicio = novo;
    } else {
        anterior->prox = novo;
    }

    return novo;
}
