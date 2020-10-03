#include "OPmatrizes.h"
//atribuindo caracteristicas de uma matiz
matriz::matriz(int linha, int coluna){
    matriz::linha = linha;
    matriz::coluna = coluna;
    int ordem = linha*coluna;
    matriz::primeiro_elemento_matriz = (float *) malloc(sizeof(float)*ordem);
}

matriz matriz_add(matriz matriz_a, matriz matriz_b){
    if(matriz_a.linha == matriz_b.linha && matriz_a.coluna == matriz_b.coluna){
        matriz matriz_resultado(matriz_a.linha,matriz_a.coluna);
        for(int i=0; i<(matriz_a.linha*matriz_a.coluna); i++){
            matriz_resultado.primeiro_elemento_matriz[i]=matriz_a.primeiro_elemento_matriz[i]+matriz_b.primeiro_elemento_matriz[i];
        }
        return matriz_resultado;
    }
    else{
        exit(1);
    }
}

void matriz_exibir(matriz matriz_referencia){
    for(int i=0; i<matriz_referencia.linha;i++){
        for(int j=0; j<matriz_referencia.coluna;j++){
            std::cout<<matriz_referencia.primeiro_elemento_matriz[(i*matriz_referencia.coluna)+j]<<'\t';
        }
        std::cout<<'\n';
    }
  }

void matriz_elementos(matriz matriz_referencia){
    for(int i=0; i<matriz_referencia.linha;i++){
        for(int j=0; j<matriz_referencia.coluna;j++){
            std::cout<<"INSIRA O ELEMENTO["<<(i+1)<<']'<<'['<<(j+1)<<"] : ";
            std::cin>>matriz_referencia.primeiro_elemento_matriz[(i*matriz_referencia.coluna)+j];
        }
    }
}

matriz matriz_sub(matriz matriz_a, matriz matriz_b){
    if(matriz_a.linha == matriz_b.linha && matriz_a.coluna == matriz_b.coluna){
        matriz matriz_resultado(matriz_a.linha,matriz_a.coluna);
        for(int i=0; i<(matriz_a.linha*matriz_a.coluna); i++){
            matriz_resultado.primeiro_elemento_matriz[i]=matriz_a.primeiro_elemento_matriz[i]-matriz_b.primeiro_elemento_matriz[i];
        }
        return matriz_resultado;
    }
    else{
        exit(1);
    }
}

matriz matriz_multi(matriz matriz_a, matriz matriz_b){
    if(matriz_a.coluna == matriz_b.linha){
        matriz matriz_resultado(matriz_a.linha, matriz_b.coluna);
        for(int i=0; i<matriz_resultado.linha; i++){
            for(int j=0; j<matriz_resultado.coluna; j++){
                matriz_resultado.primeiro_elemento_matriz[(i*matriz_resultado.coluna)+j] = 0;
                for(int k=0; k<matriz_a.coluna; k++){
                    matriz_resultado.primeiro_elemento_matriz[(i*matriz_resultado.coluna)+j]
                    += matriz_a.primeiro_elemento_matriz[(i*matriz_a.coluna)+k] * matriz_b.primeiro_elemento_matriz[(k*matriz_b.coluna)+j];
                 }
            }
        }
        return matriz_resultado;
    }
    else{
        exit(1);
    }
}
matriz matriz_multi(matriz matriz_referencia, float constante){
    matriz matriz_resultado(matriz_referencia.linha, matriz_referencia.coluna);
    for(int i=0; i<(matriz_resultado.linha*matriz_resultado.coluna); i++){
        matriz_resultado.primeiro_elemento_matriz[i] = matriz_referencia.primeiro_elemento_matriz[i]*constante;
    }
    return matriz_resultado;
}

matriz matriz_transpor(matriz matriz_referencia){
    matriz matriz_resultado(matriz_referencia.coluna,matriz_referencia.linha);
    for(int i=0; i<matriz_resultado.linha; i++){
        for(int j=0; j<matriz_resultado.coluna; j++){
            matriz_resultado.primeiro_elemento_matriz[(i*matriz_resultado.coluna)+j] = matriz_referencia.primeiro_elemento_matriz[(j*matriz_referencia.coluna)+i];
        }
    }
    return matriz_resultado;
}

float matriz_det(matriz matriz_referencia){
    if(matriz_referencia.linha == matriz_referencia.coluna){
        float det=0;
        if (matriz_referencia.linha == 1 && matriz_referencia.coluna == 1){
            det = matriz_referencia.primeiro_elemento_matriz[0];
        }
        else if(matriz_referencia.linha == 2 && matriz_referencia.coluna == 2){
            det = matriz_referencia.primeiro_elemento_matriz[0]*matriz_referencia.primeiro_elemento_matriz[3];
            det -= matriz_referencia.primeiro_elemento_matriz[1]*matriz_referencia.primeiro_elemento_matriz[2];
        }
        else{
            for(int i=0; i<matriz_referencia.linha; i++){
                matriz matriz_resto(matriz_referencia.linha-1, matriz_referencia.coluna-1);
                int m=0;
                for(int j=1; j<matriz_referencia.linha; j++){
                    for(int k=0; k<matriz_referencia.coluna; k++){
                        if(k!=i){
                            matriz_resto.primeiro_elemento_matriz[m] = matriz_referencia.primeiro_elemento_matriz[(j*matriz_referencia.coluna)+k];
                            m++;
                        }
                    }
                }
                det += matriz_referencia.primeiro_elemento_matriz[i]*pow(-1,i+2)*matriz_det(matriz_resto);
            }
        }
        return det;
    }
    else{
        exit(1);
    }
}

matriz matriz_pow(matriz matriz_referencia, int expoente){
    matriz matriz_resultado(matriz_referencia.linha, matriz_referencia.coluna);
    for(int i=0; i<matriz_resultado.linha; i++){
        for(int j=0; j<matriz_resultado.coluna; j++){
            if(i==j){
                matriz_resultado.primeiro_elemento_matriz[(i*matriz_resultado.coluna)+j] = 1;
            }
            else{
                matriz_resultado.primeiro_elemento_matriz[(i*matriz_resultado.coluna)+j] = 0;
            }
        }
    }
    for(int i=0; i<expoente; i++){
        matriz_resultado = matriz_multi(matriz_referencia, matriz_resultado);
    }
}
