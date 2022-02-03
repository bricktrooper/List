#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR    -1
#define SUCCESS   0

#define INVALID   LIST_DATA_TYPE_INVALID_VALUE

#define LOG(...)   do { printf("%s: ", __func__); printf(__VA_ARGS__); printf("\n"); } while (0)
#define ASSERT(condition, finally, ...)   do { if (!(condition)) { LOG(__VA_ARGS__); finally } } while (0)

typedef struct Node Node;

struct Node
{
	Node * next;
	Data data;
};

struct List
{
	int length;
	Node * head;
	Node * tail;
};

static void (* list_print_data)(Data data) = NULL;   // function pointer for printing a single list item (user defined)

static void initialize(List * list)
{
	list->length = 0;
	list->head = NULL;
	list->tail = list->head;
}

static Node * traverse(List * list, int index)
{
	Node * current = list->head;
	int i = 0;

	while (i < index)
	{
		if (current->next == NULL)
		{
			return NULL;
		}

		current = current->next;
		i++;
	}

	return current;
}

// ================================================= //

int list_clear(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	Node * current = list->head;

	while (current != NULL)
	{
		Node * target = current;
		current = current->next;
		free(target);
	}

	initialize(list);
	return SUCCESS;
}

List * list_new(void)
{
	List * list = malloc(sizeof(List));
	ASSERT(list != NULL, return NULL;, "Failed to allocate memory for list");
	initialize(list);
	return list;
}

int list_delete(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	ASSERT(list_clear(list) == SUCCESS, return ERROR;, "Failed to clear list");
	free(list);
	return SUCCESS;
}

int list_append(List * list, Data data)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");

	Node * node = malloc(sizeof(Node));
	ASSERT(node != NULL, return ERROR;, "Failed to allocate memory for new node");
	node->next = NULL;
	node->data = data;

	if (list->length == 0)
	{
		list->head = node;
	}
	else
	{
		list->tail->next = node;
	}

	list->tail = node;
	list->length++;
	return SUCCESS;
}

int list_insert(List * list, int index, Data data)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	ASSERT(index >= 0 && index <= list->length, return ERROR;, "Invalid list index '%d'", index);

	Node * node = malloc(sizeof(Node));
	ASSERT(node != NULL, return ERROR;, "Failed to allocate memory for new node");
	node->next = NULL;
	node->data = data;

	if (index == 0)
	{
		node->next = list->head;
		list->head = node;

		if (list->length == 0)
		{
			list->tail = list->head;
		}
	}
	else
	{
		Node * previous = traverse(list, index - 1);
		node->next = previous->next;
		previous->next = node;

		if (list->tail == previous)
		{
			list->tail = node;
		}
	}

	list->length++;
	return SUCCESS;
}

Data list_remove(List * list, int index) // make sure length not zero
{
	ASSERT(list != NULL, return INVALID;, "List not provided");
	ASSERT(index >= 0 && index < list->length, return INVALID;, "Invalid list index '%d'", index);
	ASSERT(list->length > 0, return INVALID;, "Cannot remove from an empty list");

	Node * node = NULL;

	if (index == 0)
	{
		node = list->head;
		list->head = node->next;

		if (list->length == 0)
		{
			list->tail = list->head;
		}
	}
	else
	{
		Node * previous = traverse(list, index - 1);
		node = previous->next;
		previous->next = node->next;

		if (list->tail == node)
		{
			list->tail = previous;
		}
	}

	list->length--;
	Data data = node->data;
	free(node);
	return data;
}

Data list_get(List * list, int index)
{
	ASSERT(list != NULL, return INVALID;, "List not provided");
	ASSERT(index >= 0 && index < list->length, return INVALID;, "Invalid list index '%d'", index);
	ASSERT(list->length > 0, return INVALID;, "Cannot get from an empty list");

	Node * node = traverse(list, index);
	return node->data;
}

int list_set(List * list, int index, Data data)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	ASSERT(index >= 0 && index < list->length, return ERROR;, "Invalid list index '%d'", index);
	ASSERT(list->length > 0, return ERROR;, "Cannot set to an empty list");

	Node * node = traverse(list, index);
	node->data = data;
	return SUCCESS;
}

int list_length(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	return list->length;
}

int list_set_print_data(void (* function)(Data data))
{
	ASSERT(function != NULL, return ERROR;, "Function not provided");
	list_print_data = function;
	return SUCCESS;
}

int list_print(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List not provided");
	ASSERT(list_print_data != NULL, return ERROR;, "list_print_data() is not configured");
	Node * current = list->head;

	printf("[");

	while (current != NULL)
	{
		list_print_data(current->data);
		current = current->next;

		if (current != NULL)
		{
			printf(", ");
		}
	}

	printf("]\n");
	return SUCCESS;
}
