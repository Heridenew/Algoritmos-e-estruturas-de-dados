#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da pilha
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Estrutura para a pilha
typedef struct Stack {
    Node *top;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack) {
    stack->top = NULL;
}

// Função para criar um novo nó
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para empilhar um elemento
void push(Stack *stack, int data) {
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Função para desempilhar um elemento
int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("EMPTY STACK\n");
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Função para imprimir todos os elementos da pilha
void printStack(Stack *stack) {
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// Função principal para processar os comandos de entrada
int main() {
    Stack stack;
    initStack(&stack);

    char command[20];
    int value;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "Empilhar") == 0) {
            scanf("%d", &value);
            push(&stack, value);
            printStack(&stack);
        } else if (strcmp(command, "Desempilhar") == 0) {
            pop(&stack);
            printStack(&stack);
        } else if (strcmp(command, "Fim") == 0) {
            break;
        }
    }

    return 0;
}
