#include <stdio.h>
#include "lists/Lists.h"

int main() {
    Arraylist * arraylist = arraylist_new(5);
    arraylist_add(arraylist, 5);
    arraylist_add(arraylist, 1);
    arraylist_add(arraylist, 4);
    arraylist_add(arraylist, 6);
    arraylist_add(arraylist, 2);
    arraylist_add(arraylist, 44);
    arraylist_printAll("%d", arraylist);
    arraylist_remove(arraylist, 3);
    arraylist_printAll("%d", arraylist);

    Linkedlist *linkedlist = linkedlist_new();
    linkedlist_add_last(linkedlist, 15);
    linkedlist_add_last(linkedlist, 17);
    linkedlist_add_last(linkedlist, 12);
    linkedlist_add_last(linkedlist, 20);
    linkedlist_printAll(linkedlist, "%d");
    linkedlist_add_first(linkedlist, 8);
    linkedlist_printAll(linkedlist, "%d");
    linkedlist_add_on_index(linkedlist, 4, 44);
    linkedlist_printAll(linkedlist, "%d");
    printf("%d\n", linkedlist_get(linkedlist, 4));
    printf("%d\n", linkedlist_get_first(linkedlist));
    printf("%d\n", linkedlist_get_last(linkedlist));
    linkedlist_remove_last(linkedlist);
    linkedlist_printAll(linkedlist, "%d");
    linkedlist_remove_first(linkedlist);
    linkedlist_printAll(linkedlist, "%d");
    linkedlist_remove_on_index(linkedlist, 0);
    linkedlist_printAll(linkedlist, "%d");

    Queue *queue = queue_new();
    linkedlist_add_last((Linkedlist *) queue, 77);
    linkedlist_add_last((Linkedlist *) queue, 100);
    linkedlist_add_last((Linkedlist *) queue, 66);
    linkedlist_add_last((Linkedlist *) queue, 12);


    linkedlist_printAll((Linkedlist *) queue, "%d");
    int a = queue_poll(queue);
    printf("%d\n", a);
    linkedlist_printAll((Linkedlist *) queue, "%d");

    Stack *stack = stack_new();
    linkedlist_add_last( stack, 888);
    linkedlist_add_last( stack, 555);
    linkedlist_add_last( stack, 666);
    linkedlist_add_last( stack, 777);
    linkedlist_printAll(stack, "%d");
    a = stack_poll(stack);
    printf("%d", a);
    return 0;
}
