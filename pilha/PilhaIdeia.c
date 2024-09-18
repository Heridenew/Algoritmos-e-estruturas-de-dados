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
    pilhat.pilha = (int*)calloc(1, sizeof(int));  // Aloca memória para um elemento

    return pilhat;
}

// Função para adicionar um elemento à pilha
void pushPilha(pilha* p, int value) {
    if (p->tamanho == 0) {
        p->tamanho = 1;
        p->pilha = realloc(p->pilha, p->tamanho * sizeof(int));  // Realoca memória para um elemento
        if (p->pilha == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        p->pilha[0] = value;  // Adiciona o valor na primeira posição
    } else {
        p->tamanho++;
        p->pilha = realloc(p->pilha, p->tamanho * sizeof(int));  // Realoca memória para o novo tamanho
        if (p->pilha == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        p->pilha[p->tamanho - 1] = value;  // Adiciona o valor na nova posição
    }
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

int main() {
    pilha pilhateste = iniciarPilha();  // Inicializa a pilha

    // Testando a função pushPilha
    pushPilha(&pilhateste, 10);
    pushPilha(&pilhateste, 5);
    pushPilha(&pilhateste, 8);

    // Testando a função popPilha
    popPilha(&pilhateste);
    popPilha(&pilhateste);
    popPilha(&pilhateste);
    popPilha(&pilhateste);  // Tentativa de remover de uma pilha vazia

    // Liberando a memória alocada
    free(pilhateste.pilha);
    return 0;
}



/*

Estrutura da Pilha: A estrutura pilha contém um ponteiro para um array de inteiros (pilha) e um inteiro (tamanho) que representa o tamanho atual da pilha.
Função iniciarPilha: Inicializa uma pilha com tamanho 0 e aloca memória para um elemento. Usa calloc para garantir que a memória alocada seja zerada.
Função pushPilha: Adiciona um elemento à pilha. Se a pilha estiver vazia, aloca memória para um elemento. Caso contrário, aumenta o tamanho da pilha e realoca a memória para acomodar o novo elemento. Verifica se a realocação foi bem-sucedida.
Função popPilha: Remove um elemento da pilha. Se a pilha estiver vazia, imprime uma mensagem. Caso contrário, diminui o tamanho da pilha e realoca a memória. Verifica se a realocação foi bem-sucedida, exceto quando a pilha está vazia.
Função main: Testa as funções pushPilha e popPilha adicionando e removendo elementos da pilha. No final, libera a memória alocada para evitar vazamentos de memória.

*/