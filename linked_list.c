#include <stdlib.h>
#include "linked_list.h"

// Fun��o para criar um novo n�
Noh* criarNoh(int valor) {
    Noh* novo = (Noh*)malloc(sizeof(Noh));
    if (novo) {
        novo->valor = valor;
        novo->proximo = NULL;
    }
    return novo;
}

// Fun��o para adicionar um n� � lista encadeada
void adicionarNoh(Noh** caminho, int valor) {
    Noh* novo = criarNoh(valor);
    if (!novo) return;

    if (*caminho == NULL) {
        *caminho = novo;
    } else {
        Noh* atual = *caminho;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Fun��o para adicionar um n� no final da lista encadeada
void adicionarNohNoFinal(Noh** caminho, int valor) {
    Noh* novoNoh = malloc(sizeof(Noh));
    novoNoh->valor = valor;
    novoNoh->proximo = NULL;
    if (*caminho == NULL) {
        *caminho = novoNoh;
    } else {
        Noh* atual = *caminho;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNoh;
    }
}


// Fun��o para liberar a mem�ria da lista encadeada
void liberarLista(Noh* caminho) {
    while (caminho != NULL) {
        Noh* temp = caminho;
        caminho = caminho->proximo;
        free(temp);
    }
}

void removerNoh(Noh** caminho, int valor) {
    // Se a lista estiver vazia, n�o h� nada para remover
    if (*caminho == NULL) {
        return;
    }

    Noh* atual = *caminho;
    Noh* anterior = NULL;

    // Se o primeiro n� cont�m o valor, remova-o
    if (atual->valor == valor) {
        *caminho = atual->proximo; // Move a cabe�a da lista
        free(atual); // Libera a mem�ria
        return;
    }

    // Percorre a lista at� encontrar o valor ou chegar ao fim
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se n�o encontrar o valor, apenas retorne
    if (atual == NULL) {
        return;
    }

    // Remove o n� encontrado
    anterior->proximo = atual->proximo;
    free(atual); // Libera a mem�ria do n� removido
}
