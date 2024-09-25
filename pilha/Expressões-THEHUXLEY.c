#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um nó da pilha
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Estrutura para representar a pilha
typedef struct Stack {
    Node* top;
} Stack;

// Função para inicializar a pilha
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Função para empilhar um caractere na pilha
void push(Stack* stack, char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

// Função para desempilhar um caractere da pilha
char pop(Stack* stack) {
    if (stack->top == NULL) {
        return '\0';
    }
    Node* temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Função para verificar se os caracteres correspondem
int corresponde(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

// Função para verificar se a cadeia é bem definida
char verificarCadeia(char* cadeia) {
    Stack* stack = createStack();
    int n = strlen(cadeia);

    for (int i = 0; i < n; i++) {
        if (cadeia[i] == '(' || cadeia[i] == '[' || cadeia[i] == '{') {
            push(stack, cadeia[i]);
        } else {
            if (isEmpty(stack) || !corresponde(pop(stack), cadeia[i])) {
                return 'N';
            }
        }
    }

    char resultado = isEmpty(stack) ? 'S' : 'N';
    free(stack);
    return resultado;
}

int main() {
    int T;
    scanf("%d", &T);
    char cadeia[100001];

    for (int i = 0; i < T; i++) {
        scanf("%s", cadeia);
        printf("%c\n", verificarCadeia(cadeia));
    }

    return 0;
}
