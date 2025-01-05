#include "pathfinding.h"
#include "comparisons.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>  // Para definir o valor de INF
#include <math.h>

int heuristica(int noAtual, int fim, int largura) {
    int xAtual = noAtual % largura, yAtual = noAtual / largura;
    int xFim = fim % largura, yFim = fim / largura;
    return abs(xAtual - xFim) + abs(yAtual - yFim);
}

int aSharp(int** adjMatrix, int numNos, int inicio, int fim, Noh** caminho, int* visitados, int largura) {
    int* distancias = (int*)malloc(numNos * sizeof(int));
    int* predecessores = (int*)malloc(numNos * sizeof(int));
    int* estimativas = (int*)malloc(numNos * sizeof(int));

    // Inicialização
    for (int i = 0; ehMenor(i, numNos); i++) {
        distancias[i] = INT_MAX;
        predecessores[i] = -1;
        estimativas[i] = INT_MAX;
    }
    distancias[inicio] = 0;
    estimativas[inicio] = heuristica(inicio, fim, largura);

    for (int i = 0; ehMenor(i, numNos - 1); i++) {
        int atual = -1, minimo = INT_MAX;

        // Encontra o nó com a menor estimativa
        for (int j = 0; ehMenor(j, numNos); j++) {
            if (ehIgual(visitados[j], 0) && ehMenor(estimativas[j], minimo)) {
                minimo = estimativas[j];
                atual = j;
            }
        }

        if (ehIgual(atual, -1) || ehIgual(atual, fim)) break;
        visitados[atual] = 1;

        // Atualiza as distâncias e estimativas dos vizinhos
        for (int vizinho = 0; ehMenor(vizinho, numNos); vizinho++) {
            if (ehDiferente(adjMatrix[atual][vizinho], 0) && ehIgual(visitados[vizinho], 0)) {
                int novaDist = distancias[atual] + adjMatrix[atual][vizinho];
                if (ehMenor(novaDist, distancias[vizinho])) {
                    distancias[vizinho] = novaDist;
                    predecessores[vizinho] = atual;
                    estimativas[vizinho] = distancias[vizinho] + heuristica(vizinho, fim, largura);
                }
            }
        }
    }

    // Verifica se encontrou o caminho
    if (ehIgual(distancias[fim], INT_MAX)) {
        free(distancias);
        free(predecessores);
        free(estimativas);
        return 0; // Não encontrou o caminho
    }

    // Reconstrói o caminho
    int no = fim;
    while (ehDiferente(no, -1)) {
        adicionarNoh(caminho, no);
        no = predecessores[no];
    }

    free(distancias);
    free(predecessores);
    free(estimativas);
    return 1; // Encontrou o caminho
}

int findPath(int** adjMatrix, int numNos, int inicio, int fim, Noh** caminho, int* visitados) {
    int contadorVisitacao = 0;  // Inicializa o contador de visitação

    for (int i = 0; ehMenor(i, numNos); i++) {
        visitados[i] = 0;  // Zera o vetor de nós visitados
    }

    return aSharp(adjMatrix, numNos, inicio, fim, caminho, visitados, 20);
}

