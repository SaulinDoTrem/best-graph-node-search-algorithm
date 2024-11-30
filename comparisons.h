#ifndef COMPARISONS_H
#define COMPARISONS_H

// Declara��o da vari�vel global para contar compara��es
extern int comparisons;

// Fun��o para zerar o contador de compara��es
void resetComparisons();

// Fun��o para retornar o n�mero atual de compara��es
int getComparisons();

// Fun��es de compara��o - sempre incrementam o n�mero de compara��es
int ehMaior(int a, int b);
int ehMenor(int a, int b);
int ehIgual(int a, int b);
int ehMaiorOuIgual(int a, int b);
int ehMenorOuIgual(int a, int b);
int ehDiferente(int a, int b);

#endif // COMPARISONS_H
