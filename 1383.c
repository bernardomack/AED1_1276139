#include <stdio.h>

int main(){
    int n;


    // veno quantas matrizes tem kk

    do{
    scanf("%d", &n);
    }while(n<0);

    int v[n][9][9];

    // invencao de moda aq vetor de 3 dimensoes fodase kkkk pra encontrar o vetor

    for(int q=0;q<n;q++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                scanf("%d", &v[q][i][j]);
            }
        }
    }

    // veno se as linhas sao iguais
    for(int q=0;q<n;q++){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                for(int l = 1+j;l<9;l++){
                    if(v[q][i][j] == v[q][i][l]){
                        printf("Instancia %d", q+1);
                        printf("NAO");
                        break;
                    }
                }   
            }
        }
    }

    // veno se as COLUNAS sao iguais

    for(int q=0;q<n;q++){
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                for(int l = 1+i;l<9;l++){
                    if(v[q][i][j] == v[q][l][j]){
                        printf("Instancia %d", q+1);
                        printf("NAO");
                        break;
                    }
                }   
            }
        }
    }



// veno se as sub matrize sao iguais
    for(int q=0;q<n;q++){
        for(int k = 0; k <= 6; k += 3){
            for(int a = 0; a <= 6; a += 3){

                for(int i = k; i < k + 3; i++){
                    for(int j = a; j < a + 3; j++){

                        for(int x = k; x < k + 3; x++){
                            for(int y = a; y < a + 3; y++){

                                if(i == x && j == y)
                                    continue;

                                if(v[q][i][j] == v[q][x][y]){
                                    printf("Instancia %d NAO\n", q + 1);
                            }

                            }
                        }

                    }
                }
            }
        }
    }
    

    return 0;
}