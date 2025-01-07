#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int* elementos;
    int tamanho;
} pilha;

pilha iniciarPilha() {
    pilha p;
    p.tamanho = 0;
    p.elementos = NULL;  
    return p;
}

void liberarPilha(pilha* p) {
    free(p->elementos);
    p->elementos = NULL;
    p->tamanho = 0;
}

void push(pilha* p, int c) {
    p->tamanho++;
    p->elementos = (int*)realloc(p->elementos, p->tamanho * sizeof(int));
    p->elementos[p->tamanho - 1] = c;
}

int pop(pilha* p) {
    if (p->tamanho == 0) return -1;  
    return p->elementos[--p->tamanho];
}

int topo(pilha* p) {
    if (p->tamanho == 0) return -1;
    return p->elementos[p->tamanho - 1];
}

int par(int c) {
    return c % 2 == 0;
}

void verify(pilha* p, int c) {
    if (p->tamanho == 0) {
        push(p, c);
        return;
    }

    push(p, c);
    while (p->tamanho >= 2) {
        int topo_atual = topo(p);
        int segundo = p->elementos[p->tamanho - 2];
        
        if (par(topo_atual) == par(segundo)) {
            pop(p);
            pop(p);
            int diferenca = abs(topo_atual - segundo);
            if (diferenca != 0) {
                push(p, diferenca);
            }
        } else {
            break;
        }
    }
}

int main() {
    int t, numero;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        pilha Pilha = iniciarPilha();
        
        while (scanf("%d", &numero) == 1) {
            if (numero == 0) {
                break;
            }
            verify(&Pilha, numero);
        }

        printf("Pilha %d: %d %d\n", i, Pilha.tamanho, 
               Pilha.tamanho > 0 ? topo(&Pilha) : -1);
        
        liberarPilha(&Pilha); 
    }

    return 0;
}
