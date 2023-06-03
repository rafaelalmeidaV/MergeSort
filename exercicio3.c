#include <stdio.h>

struct acoes{
    char nome[100];
    char area[100];
    int valor;
};

void function(){

    int tamanho;

    printf("digite o tamanho do bgl");
    scanf("%d", &tamanho);
    

    struct acoes *Acoes = malloc(tamanho * sizeof(Acoes));

    for(int i = 0; i< tamanho; i++){
        printf("digite o negocio");
        scanf("%s", Acoes[i].nome);
        printf("digite a area de atuaacao");
        scanf("%s", Acoes[i].area);
        printf("digite o valor");
        scanf("%d", &Acoes[i].valor);

    }

    for(int i=0; i < tamanho; i++){
        printf("%s , %s , %d", Acoes[i].nome, Acoes[i].area, Acoes[i].valor);
    }



}

int main(){
    function();
}