//
// Created by KnightLeo on 11/17/2022.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H
#include "list.h"
typedef struct Linkedlist{
    List list;
    struct Linkedelement *head;
    struct Linkedelement *tail;
} Linkedlist;

Linkedlist *linkedlist_new();
void linkedlist_add_on_index(Linkedlist *list, int index, void *element);
void linkedlist_add_first(Linkedlist *list, void *element);
void linkedlist_add_last(Linkedlist *list, void *element);
void linkedlist_printAll(Linkedlist *list, char *format);
void *linkedlist_get(Linkedlist *list, int index);
void *linkedlist_get_first(Linkedlist *list);
void *linkedlist_get_last(Linkedlist *list);
void linkedlist_remove_on_index(Linkedlist *list, int index);
void linkedlist_remove_first(Linkedlist *list);
void linkedlist_remove_last(Linkedlist *list);
#endif //DATASTRUCTURES_LINKEDLIST_H
