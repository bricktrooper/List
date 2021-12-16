#ifndef LIST_H
#define LIST_H

typedef struct List List;

List * list_new();
int list_delete(List * list);
int list_clear(List * list);
int list_append(List * list, void * data);
int list_insert(List * list, int index, void * data);
void * list_remove(List * list, int index);
void * list_get(List * list, int index);
int list_set(List * list, int index, void * data);
int list_print(List * list);

#endif /* LIST_H */
