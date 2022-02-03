#ifndef LIST_H
#define LIST_H

// The list data type MUST support copy-by-value with '=' assignment.
// All C data types except arrays should work.

typedef int Data;                           // Data can be redefined using a custom data type instead of 'int'.
#define LIST_DATA_TYPE_INVALID_VALUE   -1   // invalid value for list functions that return 'Data' values

typedef struct List List;

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


int list_set_print_data(void (* function)(Data data));

#endif /* LIST_H */
