#include <stdio.h>
#include <stdlib.h>

void function( int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        function(v, inicio, meio);
        function(v, meio+1, fim);
        function2(v, inicio, meio, fim);
    }
}

void function2(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2]){
                    temp[i] = v[p1++];
                }else{
                    temp[i] = v[p2++];
                }
                if(p1 > meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                    fim2 = 1;
                }
            }else{
                if(!fim1){
                    temp[i] = v[p1++];
                }else{
                    temp[i] = v[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            v[k] = temp[j];
        }
    }
    free(temp);
}

int main(){
    int A[8] = {5,4,1,1,3,3,2,1};
    int inicio = 0;
    int fim = 8;
    function(A, inicio, fim);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}