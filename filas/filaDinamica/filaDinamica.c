#include "filaDinamica.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct student data;
    struct node* next;
} Node;

typedef struct queue {
    struct node* head;
    struct node* tail;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    if (queue != NULL) {
        queue->head = NULL;
        queue->tail = NULL;
    }
    return queue;
}

void freeQueue(Queue* queue) {
    if (queue != NULL) {
        Node* node;
        while (queue->head != NULL) {
            node = queue->head;
            queue->head = queue->head->next;
            free(node);
        }

        free(queue);
    }
}

int insert(Queue* queue, Student student) {  // no final
    if (queue == NULL) return 0;
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return 0;

    node->data = student;
    node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = node;
    } else {
        queue->tail->next = node;
    }
    queue->tail = node;

    return 1;
}

int remove(Queue* queue) {
    if (queue == NULL || queue->head == NULL) return 0;
    Node* node = queue->head;
    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(node);
    return 1;
}

int getStudent(Queue* queue, Student* student) {
    if (queue == NULL || queue->head == NULL) return 0;
    *student = queue->head->data;
    return 1;
}
