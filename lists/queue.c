//
// Created by KnightLeo on 11/18/2022.
//
#include <malloc.h>
#include "queue.h"

Queue *queue_new(){
    Queue *queue = malloc(sizeof (Queue));
    queue->list.list.size = 0;
    return queue;
}
void *queue_poll(Queue *queue){
    void *data = linkedlist_get_first(&queue->list);
    linkedlist_remove_first(&queue->list);
    return data;
}

void *queue_peek(Queue *queue){
    void *data = linkedlist_get_first(&queue->list);
    return data;
}
