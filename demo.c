#include <stdio.h>

#include "list.h"
#include "demo.h"

void print_person(Person person)
{
	printf("{name: %s, age: %d}", person.name, person.age);
}

int main(void)
{
	List * list = list_new();

	list_set_print_data(print_person);

	list_print(list);
	list_append(list, (Person){"Joe", 9});
	list_append(list, (Person){"Bob", 99});
	list_append(list, (Person){"Alice", 23});
	list_print(list);

	list_delete(list);
	return 0;
}
