#include <stdio.h>

void funcQuickSort(int v[], int inicio, int fim){
    int i, j, pivo, aux;
    i = inicio;
    j = fim - 1;
    pivo = v[(inicio + fim) / 2];

    while(i<=j){
        while(v[i] < pivo && i < fim){
            i++;
        }
        while (v[j] > pivo && j > inicio){
            j--;
        }
        if( i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
        if(j > inicio){
            funcQuickSort(v, inicio, j+1);
        }
        if(i < fim){
            funcQuickSort(v, i, fim);
        }
    }

}

int main(){
    int A[8] = {5,4,1,1,3,3,2,1};
    int inicio = 0;
    int fim = 8;
    funcQuickSort(A, inicio, fim);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }
}