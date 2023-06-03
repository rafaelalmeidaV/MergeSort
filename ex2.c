#include <stdio.h>

int main(){
    int vet[] = {6,7,8,9};
    int *ptr = vet;
    ptr = vet+1;
    *ptr = 8;

    for (int i = 0; i < 4; i++)
    {
        printf("%d", vet[i]);
    }
    
}