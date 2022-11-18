//
// Created by KnightLeo on 11/18/2022.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H
#include "linkedlist.h"
typedef struct QUEUE{
    Linkedlist list;
} Queue;
Queue *queue_new();
void *queue_poll(Queue *queue);
void *queue_peek(Queue *queue);
#endif //DATASTRUCTURES_QUEUE_H
