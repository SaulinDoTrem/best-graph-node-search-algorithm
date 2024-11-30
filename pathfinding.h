#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "SDL2/SDL.h"
#include "linked_list.h" // Inclus�o da lista encadeada

//#define SIZE 50 // Tamanho do labirinto (20x20)

//#define SIZE 50 // Tamanho do labirinto (20x20)
//#define CELL_SIZE 30

//#define SIZE 50
//#define CELL_SIZE 20



typedef struct {
    int x, y;
} Point;

/**
 * Fun��o: findPath
 * ----------------
 * Encontra o caminho m�nimo entre o n� de partida e o n� de destino em um grafo representado por uma matriz de adjac�ncias.
 *
 * Par�metros:
 *   int** adjMatrix   - Matriz de adjac�ncia quadrada que representa o grafo (labirinto).
 *   int numNos        - N�mero total de n�s no grafo.
 *   int inicio        - �ndice do n� de partida.
 *   int fim           - �ndice do n� de destino.
 *   Noh** caminho     - Ponteiro para uma lista encadeada que armazenar� o caminho encontrado.
 *   int* visitados    - Vetor que armazena a ordem de visita��o dos n�s durante a execu��o do algoritmo.
 *
 * Retorno:
 *   Retorna 1 se um caminho foi encontrado, 0 caso contr�rio.
 */
int findPath(int** adjMatrix, int numNos, int inicio, int fim, Noh** caminho, int* visitados);


#endif // PATHFINDING_H

