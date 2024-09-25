#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 400  // Tamanho máximo de uma expressão

// Função para determinar a precedência de operadores
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 0;
    }
    if (op == '*' || op == '/') {
        return 1;
    }
    if (op == '^') {
        return 2;
    }
    return -1;
}

// Função para verificar se um caractere é um operador
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Função para converter expressão infixa para pós-fixa (Shunting Yard Algorithm)
void infix_to_postfix(char* expression, char* output) {
    char stack[MAX];  // Pilha para operadores
    int top = -1;     // Inicialmente, a pilha está vazia
    int k = 0;        // Índice para a saída pós-fixa

    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        // Se o caractere é um operando (letra), adicione à saída
        if (isalpha(c)) {
            output[k++] = c;
        }
        // Se o caractere é um parêntese de abertura, empilhe
        else if (c == '(') {
            stack[++top] = c;
        }
        // Se for um parêntese de fechamento, desempilhe até encontrar '('
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                output[k++] = stack[top--];
            }
            top--;  // Remove o '(' da pilha
        }
        // Se for um operador
        else if (is_operator(c)) {
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                output[k++] = stack[top--];
            }
            stack[++top] = c;  // Empilhe o operador atual
        }
    }

    // Desempilhe os operadores restantes
    while (top >= 0) {
        output[k++] = stack[top--];
    }

    output[k] = '\0';  // Finaliza a string pós-fixa
}

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de expressões

    char expression[MAX];  // String para armazenar a expressão de entrada
    char output[MAX];      // String para armazenar a expressão pós-fixa

    for (int i = 0; i < N; i++) {
        scanf("%s", expression);  // Lê a expressão infixa
        infix_to_postfix(expression, output);  // Converte para pós-fixa
        printf("%s\n", output);  // Imprime a expressão pós-fixa
    }

    return 0;
}
