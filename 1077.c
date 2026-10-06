#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estrutura do nó da lista encadeada para a Pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Função para empilhar (push)
void push(Node** top, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar (pop)
char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Retorna o elemento do topo sem remover
char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

// Retorna a precedência do operador
int precedencia(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0; // Para parênteses ou outros caracteres
}

// Converte a expressão infixa para pós-fixa
void infixaParaPosfixa(const char* expr) {
    Node* pilha = NULL;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Se for operando (letra ou dígito), imprime direto
        if (isalnum(c)) {
            putchar(c);
        }
        // Se for '(', empilha
        else if (c == '(') {
            push(&pilha, c);
        }
        // Se for ')', desempilha e imprime até achar '('
        else if (c == ')') {
            while (pilha != NULL && peek(pilha) != '(') {
                putchar(pop(&pilha));
            }
            if (pilha != NULL) {
                pop(&pilha); // Descarta o '('
            }
        }
        // Se for um operador
        else {
            while (pilha != NULL && peek(pilha) != '(') {
                char topo = peek(pilha);
                int pTopo = precedencia(topo);
                int pAtual = precedencia(c);

                // '^' é associativo à direita, os outros à esquerda
                if ((c == '^' && pAtual < pTopo) || (c != '^' && pAtual <= pTopo)) {
                    putchar(pop(&pilha));
                } else {
                    break;
                }
            }
            push(&pilha, c);
        }
    }

    // Desempilha e imprime qualquer operador restante
    while (pilha != NULL) {
        putchar(pop(&pilha));
    }
    putchar('\n');
}

int main() {
    int N;
    if (scanf("%d\n", &N) != 1) return 0;

    char buffer[1005];
    for (int i = 0; i < N; i++) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove o caractere de nova linha '\n', se presente
            buffer[strcspn(buffer, "\r\n")] = 0;
            infixaParaPosfixa(buffer);
        }
    }

    return 0;
}