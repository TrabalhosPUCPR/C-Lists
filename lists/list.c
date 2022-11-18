//
// Created by KnightLeo on 11/17/2022.
//
#include <malloc.h>
#include <stdio.h>
#include "list.h"

typedef enum boolean{
    false = 0,
    true = 1
} boolean;

int list_size(List *list){
    return list->size;
}

Arraylist *arraylist_new(int initial_capacity){
    struct Arraylist *list = malloc(sizeof(Arraylist));
    list->data = malloc(initial_capacity * sizeof(void *));
    list->maxSize = initial_capacity;
    list->list.size = 0;
    return list;
}


void arraylist_reallocate(struct Arraylist *list, int size){
    if(list->list.size > size) list->list.size = size;
    list->data = realloc(list->data, size * sizeof(void *));
    list->maxSize = size;
}

void arraylist_add(struct Arraylist *list, void *data) {
    if (list->list.size == list->maxSize) arraylist_reallocate(list, list->maxSize + (list->maxSize/2));
    list->data[list->list.size] = data;
    list->list.size++;
}

void *arraylist_get(Arraylist *list, int index){
    return list->data[index];
}

void arraylist_remove(struct Arraylist *list, int index){
    for(int i = index; i < list->list.size-1; i++){
        list->data[i] = list->data[i+1];
    }
    list->list.size--;
    list->maxSize--;
    arraylist_reallocate(list, list->maxSize);
}

void arraylist_printAll(char *format, struct Arraylist *list){
    printf("[");
    for(int i = 0; i < list->list.size; i++){
        printf(format, list->data[i]);
        if(i + 1 < list->list.size){
            printf(", ");
        }
    }
    printf("]\n");
}

