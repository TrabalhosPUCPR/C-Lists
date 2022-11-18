//
// Created by KnightLeo on 11/17/2022.
//
#ifndef DATASTRUCTURES_LIST_H
#define DATASTRUCTURES_LIST_H

typedef struct List{
    int size;
}List;

typedef struct Arraylist{
    List list;
    int maxSize;
    void **data;
} Arraylist;

int list_size(List *list);
Arraylist *arraylist_new(int initial_capacity);
void arraylist_add(Arraylist *list, void *data);
void *arraylist_get(Arraylist *list, int index);
void arraylist_remove(Arraylist *list, int index);
void arraylist_printAll(char *format, Arraylist *list);
#endif //DATASTRUCTURES_LIST_H
