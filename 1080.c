#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// usando o define pra facilitar ao inves de escrever 100 td hr e relembrar
#define C 100

int main(){

    int *v;

    srand(time(NULL));

    v = (int*)malloc(C*sizeof(int));

    for(int i=0;i<C;i++){
        v[i] = rand()%1000;
    }

    // criar variavel para verificação

    int maior = v[0];
    int posicao = 0;

    for(int i=0;i<C;i++){
        if(maior<v[i]){
            maior = v[i];
            posicao = i;
        }
    }

    printf("\nO maior elemento do vetor eh: %d", maior);
    printf("\nEsta no vetor de indice %d", posicao);

    free(v);

    return 0;
}