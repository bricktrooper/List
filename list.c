#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR    -1
#define SUCCESS   0

#define LOG(...)   do { printf("%s: ", __func__); printf(__VA_ARGS__); printf("\n"); } while (0)
#define ASSERT(condition, finally, ...)   do { if (!(condition)) { LOG(__VA_ARGS__); finally } } while (0)
#define ASSERT_LIST_PROVIDED(list)   ASSERT(list != NULL, return ERROR;, "List was not provided")

typedef struct Node Node;

struct Node
{
	Node * next;
	void * data;
};

struct List
{
	int length;
	Node * head;
	Node * tail;
};

static void initialize(List * list)
{
	list->length = 0;
	list->head = NULL;
	list->tail = list->head;
}

static Node * traverse(List * list, int index)
{
	if (index < 0)
	{
		return NULL;
	}

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
	ASSERT_LIST_PROVIDED(list);
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
	ASSERT_LIST_PROVIDED(list);
	ASSERT(list_clear(list) == SUCCESS, return ERROR;, "Failed to clear list");
	free(list);
	return SUCCESS;
}

int list_append(List * list, void * data)
{
	ASSERT_LIST_PROVIDED(list);

	Node * node = malloc(sizeof(Node));
	ASSERT(node != NULL, return ERROR;, "Failed to allocate memory for new node");
	node->next = NULL;
	node->data = data;

	if (list->head == NULL)
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

int list_insert(List * list, int index, void * data)
{
	ASSERT_LIST_PROVIDED(list);
	ASSERT(index >= 0 || index <= list->length, return ERROR;, "Invalid list index '%d'", index);

	Node * node = malloc(sizeof(Node));
	ASSERT(node != NULL, return ERROR;, "Failed to allocate memory for new node");
	node->next = NULL;
	node->data = data;

	Node * previous = traverse(list, index - 1);

	if (previous == NULL)
	{
		node->next = list->head;
		list->head = node;
	}
	else
	{
		node->next = previous->next;
		previous->next = node;
	}

	if (previous == list->tail)
	{
		list->tail = node;
	}

	list->length++;
	return SUCCESS;
}

void * list_remove(List * list, int index); // make sure length not zero
void * list_get(List * list, int index);
int list_set(List * list, int index, void * data);

int list_length(List * list)
{
	ASSERT_LIST_PROVIDED(list);
	return list->length;
}

int list_print(List * list)
{
	ASSERT_LIST_PROVIDED(list);
	Node * current = list->head;

	printf("+------- LIST -------+\n");
	printf("| Length: %10d |\n", list->length);
	printf("|--------------------|\n");

	if (list->length == 0)
	{
		printf("| EMPTY              |\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("| %-18p |\n", current->data);
			current = current->next;
		}
	}

	printf("+--------------------+\n");
	return SUCCESS;
}
