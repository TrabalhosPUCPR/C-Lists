//
// Created by KnightLeo on 11/17/2022.
//

#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"

struct Linkedelement{
    void *data;
    struct Linkedelement *next_element;
    struct Linkedelement *previous_element;
};

struct Linkedelement *linkedelement_new(void* data){
    struct Linkedelement *element = malloc(sizeof(int));
    element->data = data;
    element->next_element = NULL;
    element->previous_element = NULL;
    return element;
}

Linkedlist *linkedlist_new(){
    Linkedlist *list = malloc(sizeof (struct Linkedlist));
    list->list.size = 0;
    return list;
}
void linkedlist_add_on_index(Linkedlist *list, int index, void *element){
    if(list->list.size == 0 || list->list.size < index){
        return;
    }
    if(index == 0){
        linkedlist_add_first(list, element);
        return;
    }
    if(index == list->list.size){
        linkedlist_add_last(list, element);
        return;
    }
    struct Linkedelement *e = list->head;
    int cont = 0;
    while (e != NULL){
        if(cont == index){
            struct Linkedelement *linkedelement = linkedelement_new(element);
            e->previous_element->next_element = linkedelement;
            linkedelement->previous_element = e->previous_element;
            linkedelement->next_element = e;
            e->previous_element = linkedelement;
            list->list.size++;
            return;
        }
        cont++;
        e = e->next_element;
    }
}
void linkedlist_add_first(Linkedlist *list, void *element){
    struct Linkedelement *linkedelement = linkedelement_new(element);
    if(list->list.size == 0){
        list->head = linkedelement;
        list->tail = linkedelement;
    }else{
        linkedelement->next_element = list->head;
        list->head->previous_element = linkedelement;
        list->head = linkedelement;
    }
    list->list.size++;
}
void linkedlist_add_last(Linkedlist *list, void *element){
    struct Linkedelement *e = linkedelement_new(element);
    if(list->list.size == 0){
        list->tail = e;
        list->head = e;
    }else{
        list->tail->next_element = e;
        e->previous_element = list->tail;
        list->tail = e;
    }
    list->list.size++;
}

void linkedlist_printAll(Linkedlist *list, char *format){
    printf("[");
    struct Linkedelement *e = list->head;
    while (e != NULL){
        printf(format, e->data);
        if(e->next_element != NULL){
            printf(", ");
        }
        e = e->next_element;
    }
    printf("]\n");
}

void *linkedlist_get_first(Linkedlist *list){
    return list->head->data;
}

void *linkedlist_get_last(Linkedlist *list){
    return list->tail->data;
}

void *linkedlist_get(Linkedlist *list, int index){
    if(index > list->list.size*0.5){
        int count = list->list.size-1;
        struct Linkedelement *e = list->tail;
        while (e != NULL){
            if(count-- == index){
                return e->data;
            }
            e = e->previous_element;
        }
    }else{
        int count = 0;
        struct Linkedelement *e = list->head;
        while (e != NULL){
            if(count++ == index){
                return e->data;
            }
            e = e->next_element;
        }
    }
    return NULL;
}

void linkedlist_remove_on_index(Linkedlist *list, int index){
    if(index == list->list.size-1) linkedlist_remove_last(list);
    else if(index == 0) linkedlist_remove_first(list);
    else if(index > list->list.size*0.5){
        int count = list->list.size-1;
        struct Linkedelement *e = list->tail;
        while (e != NULL){
            if(count-- == index){
                struct Linkedelement *temp = e;
                temp->previous_element->next_element = temp->next_element;
                temp->next_element->previous_element = temp->previous_element;
                free(temp);
                list->list.size--;
                return;
            }
            e = e->previous_element;
        }
    }else{
        int count = 0;
        struct Linkedelement *e = list->head;
        while (e != NULL){
            if(count++ == index){
                struct Linkedelement *temp = e;
                temp->previous_element->next_element = temp->next_element;
                temp->next_element->previous_element = temp->previous_element;
                free(temp);
                list->list.size--;
                return;
            }
            e = e->next_element;
        }
    }
}
void linkedlist_remove_first(Linkedlist *list){
    struct Linkedelement *first = list->head;
    list->head = first->next_element;
    list->head->previous_element = NULL;
    list->list.size--;
    free(first);
}
void linkedlist_remove_last(Linkedlist *list){
    struct Linkedelement *last = list->tail;
    list->tail = last->previous_element;
    list->tail->next_element = NULL;
    list->list.size--;
    free(last);
}
