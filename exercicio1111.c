#include <stdio.h>
int main ()
{
	char strings [2][100];
	int count;
    int id[2];
	for (count=0;count<2;count++)
        {
            fflush(stdin);
        	printf ("\n\nDigite uma string: ");
        	gets (strings[count]);
            fflush(stdin);
            printf("digite o id");
            scanf("%d", &id[count]);
        }
	printf ("\n\n\nAs strings que voce digitou foram:\n\n");
	for (count=0;count<2;count++){
                printf ("%s\n",strings[count]);
    }
    for(count=0;count<2;count--){
        printf("%d", id[count]);
    }
}
