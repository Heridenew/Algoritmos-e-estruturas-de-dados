#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    typedef struct Node {
        int data;           
        struct Node *next;  
    } Node;


    typedef struct {
        Node *head;  
        int size;     
    } List;

    void iniciar(List *list) {
        list->head = NULL; 
        list->size = 0;
    }

    Node* createNode(int data) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void add(List *list, int element) {
        Node *newNode = createNode(element);

        if (list->head == NULL) {
            list->head = newNode; // Se a lista estiver vazia, o novo nó é o primeiro
        } else {
            Node *current = list->head;
            while (current->next != NULL) {
                current = current->next; // Vai até o último nó
            }
            current->next = newNode; // Adiciona o novo nó no final
        }
        list->size++;
    }

    void addAt(List *list, int position, int element) {
        Node *newNode = createNode(element);
        if (position == 0) {
            newNode->next = list->head;
            list->head = newNode; 
        } else {
            Node *current = list->head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next; 
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        list->size++;
    }

void removeElement(List *list, int element) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if (list->head->data == element) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Elemento %d não encontrado na lista.\n", element);
        return;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
}

void removeElement(List *list, int element) {
    if (list->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if (list->head->data == element) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }

    Node *current = list->head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Elemento %d não encontrado na lista.\n", element);
        return;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
}

void removeAt(List *list, int position) {
    if (position < 0 || position >= list->size) {
        fprintf(stderr, "Posição inválida: %d\n", position);
        return;
    }

    if (position == 0) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    list->size--;
}

int getElement(List *list, int position) {
    if (position < 0 || position >= list->size) {
        fprintf(stderr, "Posição inválida: %d\n", position);
        exit(EXIT_FAILURE);
    }
    Node *current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

bool isEmpty(List *list) {
    return list->size == 0;
}

int size(List *list) {
    return list->size;
}

void clear(List *list) {
    Node *current = list->head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->size = 0;
}

int main() {
    List myList;
    iniciar(&myList);

    // Adicionando elementos
    add(&myList, 10);
    add(&myList, 20);
    add(&myList, 30);
    printList(&myList); // [10, 20, 30]

    // Adicionando em posições específicas
    addAt(&myList, 1, 15);
    printList(&myList); // [10, 15, 20, 30]

    // Removendo por valor
    removeElement(&myList, 20);
    printList(&myList); // [10, 15, 30]

    // Removendo por posição
    removeAt(&myList, 1);
    printList(&myList); // [10, 30]

    // Obtendo elemento
    printf("Elemento na posição 1: %d\n", getElement(&myList, 1)); // 30

    // Verificando tamanho e se está vazia
    printf("Tamanho: %d\n", size(&myList)); // 2
    printf("Está vazia? %s\n", isEmpty(&myList) ? "Sim" : "Não"); // Não

    // Limpando a lista
    clear(&myList);

    // Verificando após limpar
    printf("Está vazia? %s\n", isEmpty(&myList) ? "Sim" : "Não"); // Sim

    return 0;
}