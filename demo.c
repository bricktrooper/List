#include <stdio.h>

#include "list.h"

int main(void)
{
	List * list = list_new();

	list_print(list);
	list_append(list, (void *)0);
	list_print(list);
	list_append(list, (void *)1);
	list_append(list, (void *)2);
	list_append(list, (void *)4);
	list_append(list, (void *)4);
	list_append(list, (void *)3);
	list_print(list);
	list_clear(list);
	list_print(list);

	list_insert(list, 0, (void *)1);
	list_insert(list, 0, (void *)1);
	list_print(list);
	list_insert(list, 0, (void *)2);
	list_insert(list, 0, (void *)2);
	list_print(list);
	list_insert(list, 0, (void *)1);
	list_print(list);
	list_insert(list, 1, (void *)3);
	list_print(list);
	list_insert(list, 4, (void *)4);
	list_print(list);
	list_insert(list, list_length(list) - 1, (void *)5);
	list_print(list);
	list_insert(list, list_length(list), (void *)6);
	list_print(list);
	list_insert(list, list_length(list), (void *)7);
	list_insert(list, list_length(list), (void *)8);
	list_print(list);

	list_remove(list, 5);
	list_print(list);
	list_remove(list, 0);
	list_print(list);
	list_remove(list, list_length(list) - 1);
	list_print(list);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_remove(list, 0);
	list_print(list);
	list_append(list, (void *)1);
	list_append(list, (void *)2);
	list_append(list, (void *)4);
	list_append(list, (void *)4);
	list_append(list, (void *)3);
	list_print(list);
	list_remove(list, list_length(list) - 1);
	list_remove(list, list_length(list) - 1);
	list_remove(list, list_length(list) - 1);
	list_remove(list, list_length(list) - 1);
	list_remove(list, list_length(list) - 1);
	list_print(list);

	list_delete(list);
	return 0;
}
