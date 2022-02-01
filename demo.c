#include <stdio.h>

#include "list.h"

int main(void)
{
	List * list = list_new();

	list_print(list);
	list_append(list, 0);
	list_print(list);
	list_append(list, 1);
	list_append(list, 2);
	list_append(list, 4);
	list_append(list, 4);
	list_append(list, 3);
	list_print(list);
	list_clear(list);
	list_print(list);

	list_insert(list, 0, 1);
	list_insert(list, 0, 1);
	list_print(list);
	list_insert(list, 0, 2);
	list_insert(list, 0, 2);
	list_print(list);
	list_insert(list, 0, 1);
	list_print(list);
	list_insert(list, 1, 3);
	list_print(list);
	list_insert(list, 4, 4);
	list_print(list);
	list_insert(list, list_length(list) - 1, 5);
	list_print(list);
	list_insert(list, list_length(list), 6);
	list_print(list);
	list_insert(list, list_length(list), 7);
	list_insert(list, list_length(list), 8);
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
	list_append(list, 1);
	list_append(list, 2);
	list_append(list, 4);
	list_append(list, 4);
	list_append(list, 3);
	list_print(list);
	printf("%d\n", list_remove(list, list_length(list) - 1));
	printf("%d\n", list_remove(list, list_length(list) - 1));
	printf("%d\n", list_remove(list, list_length(list) - 1));
	printf("%d\n", list_remove(list, list_length(list) - 1));
	printf("%d\n", list_remove(list, list_length(list) - 1));
	list_print(list);

	list_append(list, 1);
	list_append(list, 2);
	list_append(list, 4);
	list_append(list, 4);
	list_append(list, 3);
	list_print(list);
	printf("%d\n", list_get(list, 2));
	list_set(list, 4, 8);
	list_print(list);

	list_clear(list);
	list_print(list);

	list_delete(list);
	return 0;
}
