//
// Created by KnightLeo on 11/18/2022.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include "linkedlist.h"

typedef struct stack{
    Linkedlist list;
} Stack;
Stack *stack_new();
void *stack_poll(Stack *stack);
void *stack_peek(Stack *stack);
#endif //DATASTRUCTURES_STACK_H
