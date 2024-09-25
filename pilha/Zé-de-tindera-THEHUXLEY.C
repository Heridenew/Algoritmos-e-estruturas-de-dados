#include <stdio.h>
#include <stdlib.h>

#define MAXP 1000
#define MAXC 1000000

typedef struct {
    int camisa[MAXC];
    int topo;
} Pilha;

Pilha pilhas[MAXP];
int fila_roupas[MAXC];
int inicio_fila = 0, fim_fila = 0;

void adicionar_fila(int camisa) {
    fila_roupas[fim_fila++] = camisa;
}

int retirar_fila() {
    if (inicio_fila == fim_fila) {
        return -1;
    }
    return fila_roupas[inicio_fila++];
}

void ir_festa(int festa) {
    for (int i = 0; i < MAXP; i++) {
        if (pilhas[i].topo > 0) {
            int camisa = pilhas[i].camisa[pilhas[i].topo - 1];
            if (camisa >= festa - 1 && camisa <= festa + 1) {
                pilhas[i].topo--;
                adicionar_fila(camisa);
                return;
            }
        }
    }
    printf("ze nao vai pra festa %d\n", festa);
}

int main() {
    int T, Q, P;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &Q, &P);
        for (int p = 0; p < P; p++) {
            int tam;
            scanf("%d", &tam);
            pilhas[p].topo = tam;
            for (int j = 0; j < tam; j++) {
                scanf("%d", &pilhas[p].camisa[j]);
            }
        }
        for (int q = 0; q < Q; q++) {
            int tipo, festa;
            scanf("%d", &tipo);
            if (tipo == 1) {
                scanf("%d", &festa);
                ir_festa(festa);
            } else if (tipo == 2) {
                int camisa = retirar_fila();
                if (camisa == -1) {
                    printf("nao tem roupa pra lavar\n");
                } else {
                    printf("%d\n", camisa);
                }
            }
        }
    }
    return 0;
}
