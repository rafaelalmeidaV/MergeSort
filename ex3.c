// #include <stdio.h>

// void concatena_vetores(int vetorA[], int vetorB[]) {
//     int tamanho_vetorA = 10;
//     int tamanho_vetorB = 20;
    
//     for(int i = 0; i < tamanho_vetorB; i++) {
//         vetorA[tamanho_vetorA + i] = vetorB[i];
//     }
// }


// void concatena_vetores(int vetorA[], int vetorB[]);

// int main() {
//     int vetorA[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // vetorA original
//     int vetorB[20] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}; // vetorB
//     concatena_vetores(vetorA, vetorB); // chama a função para concatenar os vetores
//     for(int i = 0; i < 30; i++) { // imprime o vetorA resultante
//         printf("%d ", vetorA[i]);
//     }
//     return 0;
// }

#include <stdio.h>

void concatenaVetores(int *vetA, int *vetB, int *vetC) {
    int i, j;

    // Copia os elementos de A para C
    for (i = 0; i < 10; i++) {
        vetC[i] = vetA[i];
    }

    // Copia os elementos de B para C
    for (i = 0, j = 10; i < 20; i++, j++) {
        vetC[j] = vetB[i];
    }

    // Copia os elementos de C para A
    for (i = 0; i < 30; i++) {
        vetA[i] = vetC[i];
    }
}

int main() {
    int vetorA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vetorB[20] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                      21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int vetorC[30];

    concatenaVetores(vetorA, vetorB, vetorC);

    // Imprime os elementos de A
    for (int i = 0; i < 30; i++) {
        printf("%d ", vetorA[i]);
    }

    return 0;
}

