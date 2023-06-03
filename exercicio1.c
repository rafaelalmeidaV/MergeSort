#include <stdio.h>

int main()
{
    int vetor[] = {3, 4, 5, 6};
    int *ptr = vetor;
    ptr = vetor + 3;
    *ptr = 8;

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", vetor[i]);
    }
    
}


