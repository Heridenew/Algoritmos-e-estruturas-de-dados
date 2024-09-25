#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura da lista dinâmica
typedef struct {
    int *elements; 
    int size;      
} List;

void iniciar(List *list, int initialCapacity) {
    list->elements = (int *)malloc(initialCapacity * sizeof(int));
    list->size = 0;
}

// Redimensiona o vetor da lista
void resize(List *list) {
    int newCapacity = list->size + 1;
    int *newElements = (int *)realloc(list->elements, newCapacity * sizeof(int));
    list->elements = newElements;
    list->size = newCapacity;
}

// Adiciona um elemento ao final da lista
void add(List *list, int element) {
    resize(list); 
    list->elements[list->size++] = element;
    list->size++;
}

void addAt(List *list, int position, int element) {
    resize(list); 
    for (int i = list->size; i > position; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[position] = element;
    list->size++;
}

void removeElement(List *list, int element) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i] == element) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Elemento %d não encontrado na lista.\n", element);
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

void removeAt(List *list, int position) {
    for (int i = position; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}


int getElement(List *list, int position) {
    return list->elements[position];
}

bool isEmpty(List *list) {
    return list->size == 0;
}

int size(List *list) {
    return list->size;
}

void clear(List *list) {
    free(list->elements);
    list->elements = NULL;
    list->size = 0;
}

// Função principal para testes
int main() {
    List myList;
    iniciar(&myList, 5);

    add(&myList, 10);
    add(&myList, 20);
    add(&myList, 30);
    printList(&myList); 

    addAt(&myList, 1, 15);
    printList(&myList); 

    removeElement(&myList, 20);
    printList(&myList); 

    removeAt(&myList, 1);
    printList(&myList);

    printf("Elemento na posição 1: %d\n", getElement(&myList, 1));

    printf("Tamanho: %d\n", size(&myList)); 
    printf("Está vazia? %s\n", isEmpty(&myList) ? "Sim" : "Não");

    clear(&myList);

    printf("Está vazia? %s\n", isEmpty(&myList) ? "Sim" : "Não"); 

    return 0;
}
