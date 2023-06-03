#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *v = malloc(10*sizeof(int));
    int *aux = malloc(9*sizeof(int));

    for (int i = 0; i < 10; i++){
        scanf("%d", &v[i]);
    }
    

    for(int i = 0; i < 9; i++){        
        aux[i] = v[i+1];
    }
    free(v);
    v = aux;
    for(int i = 0 ; i<9 ; i++){
        printf("%d", v[i]);
    }
}