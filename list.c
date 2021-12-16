#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR    -1
#define SUCCESS   0

#define LOG(...)   do { printf("%s: ", __func__); printf(__VA_ARGS__); printf("\r\n"); } while (0)
#define ASSERT(condition, finally, ...)   do { if (!(condition)) { LOG(__VA_ARGS__); finally } } while (0)

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

List * list_new()
{
	List * list = malloc(sizeof(List));
	ASSERT(list != NULL, return NULL;, "Failed to allocate memory for list");
	initialize(list);
	return list;
}

int list_delete(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List was not provided");
	ASSERT(list_clear(list) == SUCCESS, return ERROR;, "Failed to clear list");
	free(list);
	return SUCCESS;
}

int list_clear(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List was not provided");
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

int list_append(List * list, void * data)
{
	ASSERT(list != NULL, return ERROR;, "List was not provided");

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
	return SUCCESS;
}

int list_insert(List * list, int index, void * data);
void * list_remove(List * list, int index);
void * list_get(List * list, int index);
int list_set(List * list, int index, void * data);

int list_print(List * list)
{
	ASSERT(list != NULL, return ERROR;, "List was not provided");
	Node * current = list->head;
	int i = 0;

	printf("======= LIST =======\r\n");
	printf("Length: %d\r\n", list->length);
	printf("--------------------\r\n");

	while (current != NULL)
	{
		printf("%p\r\n", current->data);
		current = current->next;
	}

	printf("====================\r\n");
	return SUCCESS;
}
