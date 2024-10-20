#include "filaEstatica.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int head, tail, size;
    struct student data[MAX];
} Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->head = 0;
        queue->tail = 0;
        queue->size = 0;
    }
    return queue;
}

void freeQueue(Queue* queue) {
    free(queue);
}

int isFull(Queue* queue) {
    if (queue == NULL) return -1;
    return (queue->size == MAX);
}

int insert(Queue* queue, Student student) {
    if (isFull(queue)) return 0;
    queue->data[queue->tail] = student;
    queue->tail = (queue->tail + 1) % MAX;
    queue->size++;

    return 1;
}
int remove(Queue* queue) {
    if (queue == NULL || queue->size == 0) return 0;
    queue->head = (queue->head + 1) % MAX;  // retorna o head para o primeiro indice caso head+1 seja o maximo
    queue->size++;

    return 1;
}

int getStudent(Queue* queue, Student* student) {
    if (queue == NULL || queue->size == 0) return 0;
    *student = queue->data[queue->head];
    return 1;
}
