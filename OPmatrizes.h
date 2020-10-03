#ifndef OPMatrizes_H
#define OPMatrizes_H
#include <iostream>
#include <math.h>

    class matriz{
        public:
        matriz(int linha, int coluna);
        int linha;
        int coluna;
        float *primeiro_elemento_matriz;
    };

    matriz matriz_add(matriz matriz_a, matriz matriz_b);

    void matriz_exibir(matriz matriz_referencia);

    void matriz_elementos(matriz matriz_referencia);

    matriz matriz_sub(matriz matriz_a, matriz matriz_b);

    matriz matriz_multi(matriz matriz_a, matriz matriz_b);
    matriz matriz_multi(matriz matriz_referencia, float constante);

    matriz matriz_transpor(matriz matriz_referencia);

    float matriz_det(matriz matriz_referencia);
#endif
