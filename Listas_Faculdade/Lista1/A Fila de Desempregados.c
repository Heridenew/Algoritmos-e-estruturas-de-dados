#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista circular
typedef struct Node {
    int id;
    struct Node *next;
} Node;

// Estrutura para a lista circular
typedef struct {
    Node *head;
    int qtd;
} CircularList;

// Função para criar um novo nó
Node* createNode(int id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

// Função para inicializar a lista circular
CircularList* createList() {
    CircularList *list = (CircularList*)malloc(sizeof(CircularList));
    if (!list) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    list->head = NULL;
    list->qtd = 0;
    return list;
}

// Função para adicionar um nó à lista circular
void add(CircularList *list, int id) {
    Node *newNode = createNode(id);
    if (!list->head) {
        list->head = newNode;
        newNode->next = newNode; // Torna a lista circular
    } else {
        Node *current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head;
    }
    list->qtd++;
}

// Função para remover um nó específico da lista circular
Node* removeNode(CircularList *list, Node *target) {
    if (list->qtd == 0 || !target) return NULL;

    Node *current = list->head;
    Node *prev = NULL;

    // Encontra o nó a ser removido
    do {
        if (current == target) {
            if (prev) {
                prev->next = current->next;
            }
            if (current == list->head) {
                list->head = current->next;
            }
            if (list->qtd == 1) {
                list->head = NULL;
            }
            list->qtd--;
            Node *nextNode = current->next;
            free(current);
            return nextNode;
        }
        prev = current;
        current = current->next;
    } while (current != list->head);

    return NULL;
}

// Função principal
int main() {
    int N, K, M;

    while (1) {
        scanf("%d %d %d", &N, &K, &M);
        if (N == 0 && K == 0 && M == 0) break;

        CircularList *candidatos = createList();

        // Preenche a lista circular
        for (int i = 1; i <= N; i++) {
            add(candidatos, i);
        }

        Node *indexH = candidatos->head;
        Node *indexA = candidatos->head;

        // Move indexA para a última posição
        for (int i = 1; i < N; i++) {
            indexA = indexA->next;
        }

        int first = 1;
        while (candidatos->qtd > 0) {
            // Avança K posições no sentido horário
            for (int i = 1; i < K; i++) {
                indexH = indexH->next;
            }

            // Avança M posições no sentido anti-horário
            for (int i = 1; i < M; i++) {
                Node *prev = indexA;
                while (prev->next != indexA) {
                    prev = prev->next;
                }
                indexA = prev;
            }

            // Imprime as escolhas
            if (!first) printf(", ");
            first = 0;

            if (indexH == indexA) {
                printf("%3d", indexH->id);
                Node *next = removeNode(candidatos, indexH);
                indexH = next;
                indexA = next;
            } else {
                printf("%3d %3d", indexH->id, indexA->id);
                Node *nextH = removeNode(candidatos, indexH);
                Node *nextA = removeNode(candidatos, indexA);
                indexH = nextH;
                indexA = nextA;
            }
        }

        printf("\n");

        // Libera a memória da lista
        while (candidatos->qtd > 0) {
            removeNode(candidatos, candidatos->head);
        }
        free(candidatos);
    }

    return 0;
}