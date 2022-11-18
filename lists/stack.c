//
// Created by KnightLeo on 11/18/2022.
//

#include <malloc.h>
#include "stack.h"

Stack *stack_new(){
    Stack *stack = malloc(sizeof (Stack));
    stack->list.list.size = 0;
    return stack;
}
void *stack_poll(Stack *stack){
    void *data = linkedlist_get_last(&stack->list);
    linkedlist_remove_last(&stack->list);
    return data;
}

void *stack_peek(Stack *stack){
    void *data = linkedlist_get_last(&stack->list);
    return data;
}
