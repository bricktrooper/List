#include <stdio.h>

#include "list.h"

int main(void)
{
	int data [] = {1, 2, 3, 4, 6, 7};
	List * list = list_new();

	list_print(list);
	list_append(list, &data[0]);
	list_print(list);
	list_append(list, &data[1]);
	list_append(list, &data[2]);
	list_append(list, &data[4]);
	list_append(list, &data[4]);
	list_append(list, &data[3]);
	list_print(list);
	list_clear(list);
	list_print(list);

	list_delete(list);
	return 0;
}
