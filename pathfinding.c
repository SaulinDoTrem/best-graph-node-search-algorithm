#include "pathfinding.h"
#include "comparisons.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>  // Para definir o valor de INF
#include <math.h>


//////////////////////////////////////////// BUSCA EM PROFUNDIDADE //////////////////////////////////////

int findPathRec(int** adjMatrix, int numNos, int inicio, int fim, Noh** caminho, int* visitados, int* contadorVisitacao) {
    visitados[inicio] = ++(*contadorVisitacao);  // Marca a ordem de visitação do nó atual

    adicionarNoh(caminho, inicio);

    if (ehIgual(inicio, fim)) {
        return 1;
    }

    for (int i = 0; ehMenor(i, numNos); i++) {
        // Usa visitados para verificar se o nó já foi visitado
        if (ehIgual(adjMatrix[inicio][i], 1) && ehIgual(visitados[i], 0)) {
            if (findPathRec(adjMatrix, numNos, i, fim, caminho, visitados, contadorVisitacao)) {
                return 1;
            }
        }
    }

    removerNoh(caminho, inicio);
    return 0;
}

int findPath(int** adjMatrix, int numNos, int inicio, int fim, Noh** caminho, int* visitados) {
    int contadorVisitacao = 0;  // Inicializa o contador de visitação

    for (int i = 0; ehMenor(i, numNos); i++) {
        visitados[i] = 0;  // Zera o vetor de nós visitados
    }

    return findPathRec(adjMatrix, numNos, inicio, fim, caminho, visitados, &contadorVisitacao);
}
