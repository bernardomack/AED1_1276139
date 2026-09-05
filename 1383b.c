
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int ***sudoku;

    // Lendo a quantidade de instancias
    scanf("%d", &n);

    // Alocando espaço para n matrizes
    sudoku = (int ***)malloc(n * sizeof(int **));

    // Alocando cada matriz
    for (int q = 0; q < n; q++) {

        // 9 linhas
        sudoku[q] = (int **)malloc(9 * sizeof(int *));

        // 9 colunas em cada linha
        for (int i = 0; i < 9; i++) {
            sudoku[q][i] = (int *)malloc(9 * sizeof(int));
        }
    }

    // Preenchendo as matrizes
    for (int q = 0; q < n; q++) {

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                scanf("%d", &sudoku[q][i][j]);

            }
        }
    }

    // Verificando cada instancia
    for (int q = 0; q < n; q++) {

        int valido = 1;

        //vendo as linhas

        for (int i = 0; i < 9 && valido; i++) {

            for (int j = 0; j < 9 && valido; j++) {

                // Verifica se o numero se repete
                for (int l = j + 1; l < 9; l++) {

                    if (sudoku[q][i][j] == sudoku[q][i][l]) {

                        valido = 0;
                        break;

                    }
                }
            }
        }

       //verificando as colunas
        for (int j = 0; j < 9 && valido; j++) {

            for (int i = 0; i < 9 && valido; i++) {

                // Verifica se o numero se repete
                for (int l = i + 1; l < 9; l++) {

                    if (sudoku[q][i][j] == sudoku[q][l][j]) {

                        valido = 0;
                        break;

                    }
                }
            }
        }

        //verificando matriz 3x3

        for (int k = 0; k <= 6 && valido; k += 3) {

            for (int a = 0; a <= 6 && valido; a += 3) {

                for (int i = k; i < k + 3 && valido; i++) {

                    for (int j = a; j < a + 3 && valido; j++) {

                        for (int x = k; x < k + 3; x++) {

                            for (int y = a; y < a + 3; y++) {

                                // Não compara a posição com ela mesma
                                if (i == x && j == y) {
                                    continue;
                                }

                                if (sudoku[q][i][j] == sudoku[q][x][y]) {

                                    valido = 0;
                                    break;

                                }
                            }

                            if (!valido) {
                                break;
                            }
                        }
                    }
                }
            }
        }

    //verificando a matriz

        for (int i = 0; i < 9 && valido; i++) {

            for (int j = 0; j < 9; j++) {

                if (sudoku[q][i][j] < 1 || sudoku[q][i][j] > 9) {

                    valido = 0;
                    break;

                }
            }
        }

     // resultado 
        printf("Instancia %d\n", q + 1);

        if (valido) {
            printf("SIM\n\n");
        }
        else {
            printf("NAO\n\n");
        }
    }

    // liberando td dps

    for (int q = 0; q < n; q++) {

        for (int i = 0; i < 9; i++) {
            free(sudoku[q][i]);
        }

        free(sudoku[q]);
    }

    free(sudoku);

    return 0;
}
