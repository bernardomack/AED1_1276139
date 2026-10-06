#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó para a Pilha Dinâmica
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para empilhar (push)
void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar (pop)
int pop(Node** top) {
    if (*top == NULL) return -1;
    Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Retorna o topo da pilha sem remover
int peek(Node* top) {
    if (top == NULL) return -1;
    return top->data;
}

// Libera a memória restante da pilha
void limparPilha(Node** top) {
    while (*top != NULL) {
        pop(top);
    }
}

int main() {
    int N;

    // Lê N até encontrar N = 0 (fim de todos os blocos)
    while (scanf("%d", &N) == 1 && N != 0) {
        
        while (1) {
            int alvo[1005];
            scanf("%d", &alvo[0]);

            // Se o primeiro elemento for 0, acabou o bloco atual
            if (alvo[0] == 0) {
                break;
            }

            // Lê o restante do arranjo desejado para B
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            Node* pilha = NULL;
            int vagao_atual = 1; // Próximo vagão a chegar de A
            int idx_alvo = 0;    // Índice da sequência desejada em B
            int possivel = 1;

            while (idx_alvo < N) {
                // Se a pilha tiver no topo o vagão que precisamos agora, desempilhamos para B
                if (pilha != NULL && peek(pilha) == alvo[idx_alvo]) {
                    pop(&pilha);
                    idx_alvo++;
                }
                // Se ainda há vagões vindo de A, empilhamos
                else if (vagao_atual <= N) {
                    push(&pilha, vagao_atual);
                    vagao_atual++;
                }
                // Se não podemos desempilhar o desejado nem empilhar novos vagões, é impossível
                else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            limparPilha(&pilha);
        }

        // Linha em branco após o término de cada bloco
        printf("\n");
    }

    return 0;
}