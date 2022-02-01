#ifndef LIST_H
#define LIST_H

// These can be redefined to a custom data type
#define LIST_DATA_TYPE                 int
#define LIST_DATA_TYPE_INVALID_VALUE   -1

typedef struct List List;
typedef LIST_DATA_TYPE Data;

List * list_new(void);
int list_delete(List * list);
int list_clear(List * list);
int list_append(List * list, Data data);
int list_insert(List * list, int index, Data data);
Data list_remove(List * list, int index);
Data list_get(List * list, int index);
int list_set(List * list, int index, Data data);
int list_length(List * list);
int list_print(List * list);   // only works for int

#endif /* LIST_H */
