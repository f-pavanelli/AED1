#include "pilhaDinamica.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct student data;
    struct node* next;
} Node;

typedef struct stack {
    struct node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->top = NULL;
        stack->size = 0;
    }
    return stack;
}

void freeStack(Stack* stack) {
    if (stack != NULL) {
        Node* node;
        while (stack->top != NULL) {
            node = stack->top;
            stack->top = stack->top->next;
            free(node);
        }

        free(stack);
    }
}

int push(Stack* stack, Student student) {
    if (stack == NULL) return 0;
    Node* node = malloc(sizeof(Node));
    if (node == NULL) return 0;

    node->data = student;
    node->next = stack->top;

    stack->top = node;
    stack->size++;
    return 1;
}

int pop(Stack* stack, Student* student) {
    if (stack == NULL || stack->top == NULL) return 0;

    Node* node = stack->top;
    *student = node->data;
    stack->top = node->next;
    stack->size--;
    free(node);

    return 1;
}
