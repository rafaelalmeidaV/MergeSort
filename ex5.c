#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 10;
    int *ptr = var;

    
    printf("%p", ptr);    
    printf("%p", &ptr);
    printf("%d", *ptr);
}