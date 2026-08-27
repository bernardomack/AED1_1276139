#include <stdio.h>

int main(){
    int n;

    // Colocando ae pra escolher o numero de elementos do vetor
    do{
        printf("Digite o numero de elementos de seu vetor maior que 1 e menor que 1000:\n");
        scanf("%d", &n);
    }while(n<=1 || n>=1000);

    int v[n];

    // preenchendo o vetor
    for(int i=0;i<n;i++){
        printf("\nEscolha o valor do vetor na posicao %d: ", i);
        scanf("%d", &v[i]);
    }

    // vendo qual eh menor e a posicao

    int menor = v[0];
    int posicao = 0;

    for(int i=0;i<n;i++){
        if(menor>=v[i]){
            menor = v[i];
            posicao = i;
        }
    }

    printf("Aqui esta seu vetor:\n");
    for(int i=0;i<n;i++){
        printf("%d, ", v[i]);
    }

    printf("\nO menor elemento eh: %d", menor);
    printf("\nE sua posicao eh: %d", posicao);
    return 0;
}