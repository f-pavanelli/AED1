#include "pilhaEstatica.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int size;
    struct student data[MAX];
} Stack;

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->size = 0;
    }
    return stack;
}

void freeStack(Stack* stack) {
    free(stack);
}

int push(Stack* stack, Student student) {
    if (stack == NULL || stack->size == MAX) return 0;
    stack->data[stack->size] = student;
    stack->size++;

    return 1;
}

int pop(Stack* stack, Student* student) {
    if (stack == NULL || stack->size == 0) return 0;
    *student = stack->data[stack->size - 1];
    stack->size--;

    return 1;
}

int remove(Stack* stack) {
    if (stack == NULL || stack->size == 0) return 0;
    stack->size--;

    return 1;
}

int getStudent(Stack* stack, Student* student) {
    if (stack == NULL || stack->size == 0) return 0;
    *student = stack->data[stack->size - 1];
    return 1;
}
