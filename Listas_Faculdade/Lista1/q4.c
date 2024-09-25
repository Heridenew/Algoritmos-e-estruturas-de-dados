#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;

typedef struct pilha {
    T* pilha;
    int tamanho;
} pilha;

pilha iniciarPilha() {
    pilha pilhat;
    pilhat.tamanho = 0;
    pilhat.pilha = (T*)calloc(1, sizeof(T));
    return pilhat;
}

void add(pilha* p, T element) {
    p->tamanho++;
    p->pilha = realloc(p->pilha, p->tamanho * sizeof(T));
    if (p->pilha == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    p->pilha[p->tamanho - 1] = element;
}

void addAt(pilha* p, int position, T element) {
    if (position < 0 || position > p->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    p->tamanho++;
    p->pilha = realloc(p->pilha, p->tamanho * sizeof(T));

    for (int i = p->tamanho - 1; i > position; i--) {
        p->pilha[i] = p->pilha[i - 1];
    }

    p->pilha[position] = element;
}

void addAll(pilha* p, int position, pilha* otherPilha) {
    if (position < 0 || position > p->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = 0; i < otherPilha->tamanho; i++) {
        addAt(p, position + i, otherPilha->pilha[i]);
    }
}

void removeElement(pilha* p, T element) {
    if (p->tamanho == 0) {
        printf("A pilha está vazia.\n");
        return;
    }

    int i;
    for (i = 0; i < p->tamanho; i++) {
        if (p->pilha[i] == element) {
            break;
        }
    }

    if (i == p->tamanho) {
        printf("Elemento não encontrado.\n");
        return;
    }

    for (int j = i; j < p->tamanho - 1; j++) {
        p->pilha[j] = p->pilha[j + 1];
    }

    p->tamanho--;
    p->pilha = realloc(p->pilha, p->tamanho * sizeof(T));
}

void removeAt(pilha* p, int position) {
    if (position < 0 || position >= p->tamanho) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = position; i < p->tamanho - 1; i++) {
        p->pilha[i] = p->pilha[i + 1];
    }

    p->tamanho--;
    p->pilha = realloc(p->pilha, p->tamanho * sizeof(T));
}

T getElement(pilha* p, int position) {
    if (position < 0 || position >= p->tamanho) {
        printf("Posição inválida.\n");
        exit(1);
    }
    return p->pilha[position];
}

bool isEmpty(pilha* p) {
    return p->tamanho == 0;
}

int size(pilha* p) {
    return p->tamanho;
}

void clear(pilha* p) {
    free(p->pilha);
    p->pilha = NULL;
    p->tamanho = 0;
}

int main() {
    pilha p = iniciarPilha();

    add(&p, 10);
    add(&p, 20);
    add(&p, 30);
    addAt(&p, 1, 15);

    printf("Pilha após inserções: ");
    for (int i = 0; i < p.tamanho; i++) {
        printf("%d ", p.pilha[i]);
    }
    printf("\n");

    removeElement(&p, 20);
    printf("Pilha após remover o elemento 20: ");
    for (int i = 0; i < p.tamanho; i++) {
        printf("%d ", p.pilha[i]);
    }
    printf("\n");

    removeAt(&p, 1);
    printf("Pilha após remover na posição 1: ");
    for (int i = 0; i < p.tamanho; i++) {
        printf("%d ", p.pilha[i]);
    }
    printf("\n");

    printf("Elemento na posição 0: %d\n", getElement(&p, 0));

    printf("Tamanho da pilha: %d\n", size(&p));
    printf("Está vazia? %s\n", isEmpty(&p) ? "Sim" : "Não");

    clear(&p);

    printf("Está vazia após limpar? %s\n", isEmpty(&p) ? "Sim" : "Não");

    return 0;
}
