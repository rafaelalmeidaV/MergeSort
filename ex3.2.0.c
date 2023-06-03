#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int* vetorA, int* vetorB, int tamanhoA, int tamanhoB) {
    int* vetorC = (int*) malloc((tamanhoA+tamanhoB) * sizeof(int)); // alocando memória para o vetorC

    // copiando elementos de A para C
    for(int i = 0; i < tamanhoA; i++) {
        vetorC[i] = vetorA[i];
    }

    // copiando elementos de B para C
    for(int i = 0; i < tamanhoB; i++) {
        vetorC[tamanhoA+i] = vetorB[i];
    }

    // copiando elementos de C para A
    for(int i = 0; i < tamanhoA+tamanhoB; i++) {
        vetorA[i] = vetorC[i];
    }

    free(vetorC); // liberando memória alocada para vetorC
}

int main() {
    int vetorA[10] = {1,2,3,4,5,6,7,8,9,10};
    int vetorB[20] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int tamanhoA = 10;
    int tamanhoB = 20;

    mergeArrays(vetorA, vetorB, tamanhoA, tamanhoB);

    // imprimindo vetorA com os elementos de B adicionados
    for(int i = 0; i < 30; i++) {
        printf("%d ", vetorA[i]);
    }

    return 0;
}