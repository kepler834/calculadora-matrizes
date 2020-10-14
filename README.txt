# calculadora-matrizes
biblioteca contendo operações fundamentais
  
 objeto:
    1. matriz => é um objeto que define uma matriz, dessa forma, é composto pelas seguintes informações: linha, coluna e elementos.
      1.1. SINTAX:  class matriz{
                      public:
                        matriz(int linha, int coluna);
                        int linha;
                        int coluna;
                        float *primeiro_elemento_matriz;
                    };
  funções: 
    1. Adição => função que recebe 2 objetos matriz e retorna um objeto matriz com os elementos das matrizes de entrada somados.
      1.1. SINTAX: 
                    matriz matriz_add(matriz matriz_a, matriz matriz_b);
   
    2. Adição => função que recebe 2 objetos matriz e retorna um objeto matriz com os elementos das matrizes de entrada subtraidos.
      2.1. SINTAX: 
                    matriz matriz_sub(matriz matriz_a, matriz matriz_b);

    3. multiplicação => função que recebe 2 objetos matriz ou 1 objeto matriz e uma constante, retorna um objeto matriz com os elementos dos parametros de entrada multiplicados.
      3.1. SINTAX: 
                    matriz matriz_multi(matriz matriz_a, matriz matriz_b); ou matriz matriz_multi(matriz matriz_a, float constante);
                   
    4. exponenciação => função que recebe 1 objetos matriz e uma constante, retorna um objeto matriz com os elementos da matriz de entrada multiplicada por ela mesmo o valor da constante vezes.
      4.1. SINTAX: 
                    matriz matriz_pow(matriz matriz_referencia, int expoente);
         
    5. determinante => calcula o valor do determiante da matriz se ela for quadrada.
      5.1. SINTAX:
                    float matriz_det(matriz matriz_referencia);
    
    6. transporsição => recebe um objeto matriz de entrada e retorna a matriz transposta da entrada
      6.1. SINTAX:
                    matriz matriz_transpor(matriz matriz_referencia);
                    
