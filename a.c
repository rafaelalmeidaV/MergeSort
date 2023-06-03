#include <stdio.h>
#include <stdlib.h>
int main(){
    int var1=  10;
    char var2 = 'a';
    float var3= 10.0;
    int vetor[]= {112, 15, 65};
   
   
   
    printf("o endere�o de var1 eh: %p", &var1);
    printf("\n o endereco de var2 eh: %p", &var2);
    printf("\n o endereco de var3 eh: %p", &var3);
   
    int* ptr1 = vetor; //ponteiro do vetor
    char* ptr2 = &var2;
    float* ptr3 = &var3;
   
    printf("\no conteudo de var1 eh: %d", var1);
    printf("\n o endereco de var1 eh: %p", &var1);
    printf("\n o conteudo de pontDeInt eh: %d", *ptr1);
    printf("\n o endereco de pontDeInt eh: %p", &ptr1);
    printf("\n o conteudo da celular que pontDeInt aponta eh: %d", *ptr1);
   
    return 0;
}
