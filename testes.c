#include <stdio.h>
#include <stdlib.h>

struct bolsa{
    char nome[20];
    char area[20];
    float valor;
};

void function(){
    int tamanho, i;

    scanf("%d", &tamanho);
    struct bolsa *Acoes = malloc(tamanho*sizeof(Acoes));
    for ( i = 0; i < tamanho; i++)
    {   
        fflush(stdin);
        printf("digite o nome da companhia");
        scanf("%s", Acoes[i].nome);
        fflush(stdin);
        printf("digite a area");
        scanf("%s", Acoes[i].area);
        fflush(stdin);
        printf("digite o valor");
        scanf("%f", &Acoes[i].valor);

    }

    for(i=0; i<tamanho; i++){
        printf("%s %s %f", Acoes[i].nome, Acoes[i].area, Acoes[i].valor);
    }
    
}

int main(){

   function();



}