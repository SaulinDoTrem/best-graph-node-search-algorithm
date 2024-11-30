#include "comparisons.h"

// Defini��o da vari�vel global
int comparisons = 0;

// Fun��o para zerar o contador de compara��es
void resetComparisons() {
    comparisons = 0;
}

// Fun��o para retornar o n�mero atual de compara��es
int getComparisons() {
    return comparisons;
}

// Fun��es de compara��o - sempre incrementam o n�mero de compara��es
int ehMaior(int a, int b) {
    comparisons++;
    return a > b;
}

int ehMenor(int a, int b) {
    comparisons++;
    return a < b;
}

int ehIgual(int a, int b) {
    comparisons++;
    return a == b;
}

int ehMaiorOuIgual(int a, int b) {
    comparisons++;
    return a >= b;
}

int ehMenorOuIgual(int a, int b) {
    comparisons++;
    return a <= b;
}

int ehDiferente(int a, int b) {
    comparisons++;
    return a != b;
}
