#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *elements; 
    int size;      
    int front;    
    int rear;      
    int capacity;  
} Queue;

void iniciar(Queue *queue, int initialCapacity) {
    queue->elements = (int *)malloc(initialCapacity * sizeof(int));
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = initialCapacity;
}

void resize(Queue *queue) {
    int newCapacity = queue->capacity * 2;
    int *newElements = (int *)realloc(queue->elements, newCapacity * sizeof(int));
    queue->elements = newElements;
    queue->capacity = newCapacity;
}

void enqueue(Queue *queue, int element) {
    if (queue->size == queue->capacity) {
        resize(queue);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = element;
    queue->size++;
}

void dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("A fila está vazia.\n");
        return;
    }
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size--;
}

int front(Queue *queue) {
    if (queue->size == 0) {
        printf("A fila está vazia.\n");
        exit(1);
    }
    return queue->elements[queue->front];
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

int size(Queue *queue) {
    return queue->size;
}

void clear(Queue *queue) {
    free(queue->elements);
    queue->elements = NULL;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
}

int main() {
    Queue myQueue;
    iniciar(&myQueue, 5);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    printQueue(&myQueue);

    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    printQueue(&myQueue);

    dequeue(&myQueue);
    printQueue(&myQueue);

    printf("Elemento na frente: %d\n", front(&myQueue));

    printf("Tamanho da fila: %d\n", size(&myQueue));
    printf("Está vazia? %s\n", isEmpty(&myQueue) ? "Sim" : "Não");

    clear(&myQueue);

    printf("Está vazia após limpar? %s\n", isEmpty(&myQueue) ? "Sim" : "Não");

    return 0;
}
