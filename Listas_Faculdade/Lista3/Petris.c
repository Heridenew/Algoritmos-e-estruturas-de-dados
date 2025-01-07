#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void verify(pilha* p, int c) {
    if (p->tamanho == 0) {
        push(p, c);
        return;
    }

    push(p, c);
    while (p->tamanho >= 2) {
        int topo1 = p->elementos[p->tamanho - 1];
        int topo2 = p->elementos[p->tamanho - 2];
        
        if (topo1 == topo2) {
            pop(p);
            pop(p);
        } else {
            break;
        }
    }
}

int main() {
    int P;
    scanf("%d", &P);
    
    for (int caso = 0; caso < P; caso++) {
        pilha* colunas = NULL;
        int numColunas = 0;
        
        while (1) {
            int coluna, cor;
            char linha[10];
            scanf("%s", linha);
            
            if (strcmp(linha, "END") == 0) {
                break;
            }
            
            coluna = atoi(linha);
            scanf("%d", &cor);
            
            if (coluna == 0) {
                numColunas++;
                colunas = (pilha*)realloc(colunas, numColunas * sizeof(pilha));
                for (int i = numColunas - 1; i > 0; i--) {
                    colunas[i] = colunas[i-1];
                }
                colunas[0] = iniciarPilha();
                verify(&colunas[0], cor);
            }
            else if (coluna == numColunas + 1) {
                numColunas++;
                colunas = (pilha*)realloc(colunas, numColunas * sizeof(pilha));
                colunas[numColunas-1] = iniciarPilha();
                verify(&colunas[numColunas-1], cor);
            }
            else {
                verify(&colunas[coluna-1], cor);
            }
            
            for (int i = 0; i < numColunas; i++) {
                if (colunas[i].tamanho == 0) {
                    liberarPilha(&colunas[i]);
                    for (int j = i; j < numColunas - 1; j++) {
                        colunas[j] = colunas[j+1];
                    }
                    numColunas--;
                    i--;
                }
            }
        }
        
        printf("caso %d:", caso);
        if (numColunas > 0) {
            for (int i = 0; i < numColunas; i++) {
                printf(" %d", topo(&colunas[i]));
                liberarPilha(&colunas[i]);
            }
        }
        printf("\n");
        
        if (colunas != NULL) {
            free(colunas);
        }
        
        char linha[2];
        fgets(linha, sizeof(linha), stdin);
    }
    
    return 0;
}