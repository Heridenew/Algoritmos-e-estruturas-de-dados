#include <stdio.h>
#include <stdlib.h>  

// Definição da estrutura da pilha
typedef struct pilha {
    char* elementos;    // Ponteiro para o array que armazena os elementos da pilha
    int tamanho;   // Tamanho atual da pilha
} pilha;

// Função para iniciar a pilha
pilha iniciarPilha() {
    pilha p;
    p.tamanho = 0;
    p.elementos = (char*)malloc(255 * sizeof(char));  // Aloca memória suficiente para 255 caracteres
    return p;
}

// Função para adicionar um elemento à pilha
void push(pilha* p, char c){
    p->elementos[p->tamanho++] = c;
}

// Função para remover um elemento da pilha
char pop(pilha* p) {
    if (p->tamanho == 0) return '\0';
    return p->elementos[--p->tamanho];
}

char topo(pilha* p) {
    if (p->tamanho == 0) return '\0';
    return p->elementos[p->tamanho - 1];
}

int estaBalanceada(char* str) {
    pilha p = iniciarPilha();
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == ' ' || c == '\n') continue;  // Ignora espaços em branco e novas linhas
        if (c == '(' || c == '[' || c == "{") {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == "}") {
            char topoElemento = topo(&p);
            if ((c == ')' && topoElemento == '(') || (c == ']' && topoElemento == '[') || (c == '}' && topoElemento == '{')) {
                pop(&p);
            } else {
                free(p.elementos);
                return 0;  // Não está balanceada
            }
        }
    }
    int resultado = (p.tamanho == 0);
    free(p.elementos);
    return resultado;
}


int main() {
    int n;
    scanf("%d\n", &n);  // Lê o número de strings

    for (int i = 0; i < n; i++) {
        char str[256];
        fgets(str, 256, stdin);  // Lê a string

        if (strlen(str) == 0 || (strlen(str) == 1 && str[0] == '\n')) {
            printf("Yes\n");
        } else {
            if (estaBalanceada(str)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
