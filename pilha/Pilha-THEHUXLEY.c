#include <stdio.h>
#include <stdlib.h>  

// Definição da estrutura da pilha
typedef struct pilha {
    int* pilha;    // Ponteiro para o array que armazena os elementos da pilha
    int tamanho;   // Tamanho atual da pilha
} pilha;

// Função para iniciar a pilha
pilha iniciarPilha() {
    pilha pilhat;
    pilhat.tamanho = 0;  // Inicializa o tamanho da pilha como 0
    pilhat.pilha = (int*)malloc(sizeof(int));  // Aloca memória para um elemento

    return pilhat;
}

// Função para adicionar um elemento à pilha
void pushPilha(pilha* p, int value) {
    p->tamanho++;
    p->pilha = realloc(p->pilha, p->tamanho * sizeof(int));  // Realoca memória para o novo tamanho
    if (p->pilha == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    p->pilha[p->tamanho - 1] = value;  // Adiciona o valor na nova posição
}

// Função para remover um elemento da pilha
void popPilha(pilha* p) {
    if (p->tamanho == 0) {
        printf("A pilha está vazia.\n");
    } else {
        p->tamanho--;
        p->pilha = realloc(p->pilha, p->tamanho * sizeof(int));  // Realoca memória para o novo tamanho
        if (p->pilha == NULL && p->tamanho > 0) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
    }
}

// Função para imprimir os elementos da pilha
void imprimirPilha(pilha* p) {
    for (int i = p->tamanho - 1; i >= 0; i--) {
        printf("%d", p->pilha[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}


int main() {
    pilha p = iniciarPilha();
    char comando[50];
    int valor;

    while (1) {
        fgets(comando, 50, stdin);
        if (strncmp(comando, "Empilhar", 8) == 0) {
            sscanf(comando + 9, "%d", &valor);
            pushPilha(&p, valor);
        } else if (strncmp(comando, "Desempilhar", 11) == 0) {
            popPilha(&p);
        } else if (strncmp(comando, "Imprimir", 8) == 0) {
            imprimirPilha(&p);
        } else if (strncmp(comando, "Finalizar", 9) == 0) {
            break;
        }
    }

    free(p.pilha);
    return 0;
}
