#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/* ==================== ALIAS KEY->VALUE ==================== */

// Create and initialize an alias struct.
//
// Python: alias = (key, value)
struct alias *alias_create(char *key, char *value)
{
	struct alias *alias = malloc(sizeof(struct alias));

	alias->key = malloc(strlen(key)+1);
    strcpy(alias->key, key);

	alias->value = malloc(strlen(value)+1);
    strcpy(alias->value, value);

    alias->next = NULL;

	return alias;
}

// Delete an alias struct and free all of its associated resources. NOTE: The
// provided alias pointer may not be used anymore after this function call.
void alias_delete(struct alias *alias)
{
    free(alias->key);
    free(alias->value);
    free(alias);
}

// Print a human-readable representation of the alias struct
//
// Python: print(list)
void alias_print(struct alias *alias)
{
    if (alias)
    {
        printf("%s:'%s'", alias->key, alias->value);
    }
}


/* ==================== ALIAS LOOKUP: SINGLE LINKED LIST ==================== */

// Create an empty list
//
// Python: list = []
struct alias_list *alias_list_create(void)
{
	struct alias_list *list = malloc(sizeof(struct alias_list));
	list->first = NULL;
	return list;
}

// Print a human-readable representation of the given list
//
// Python: print(list)
void alias_list_print(struct alias_list *list)
{
	printf("[");

	struct alias *current = list->first;
	while (current != NULL)
	{
        alias_print(current);

		// no comma after last value
		if (current->next != NULL)
			printf(", ");

		current = current->next;
	}

	printf("]\n");
}

// Return the length of the given list (i.e., the number of values in it)
//
// Python: length = len(list)
int alias_list_length(struct alias_list *list)
{
	int length = 0;
	struct alias *current = list->first;

	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return length;
}

// Delete the given list
//
// Python: del list
void alias_list_delete(struct alias_list *list)
{
	struct alias *current = list->first;

	while (current != NULL)
	{
		struct alias *previous = current;
		current = current->next;
        alias_delete(previous);
	}

	free(list);
}

// Append the given (key, value) pair to the given list
//
// Python: list.append((key, value))
void alias_list_append(struct alias_list *list, char *key, char *value)
{
}

// Return the value of the element with the given key. If the given key was not
// found, the value NULL is returned.
char *alias_list_lookup(struct alias_list *list, char *key)
{
}

// Remove the element with given key from the given list. If the given key
// was not found, 0 is returned, otherwise 1 is returned.
int alias_list_remove(struct alias_list *list, char *key)
{
}

/* ==================== TEST ==================== */

int alias_list_test()
{
	struct alias_list *list = alias_list_create();

	if (alias_list_length(list) != 0)
    {
		printf("list_length of empty list should be zero\n");
        alias_list_print(list);
		return 0;
	}

    struct alias *alias = alias_create("MY_KEY", "MY_VAL");

    if (alias == NULL ||
        (strcmp(alias->key, "MY_KEY")!=0) ||
        (strcmp(alias->value, "MY_VAL")!=0) ||
        alias->next != NULL)
    {
		printf("alias_create failure\n");
        alias_print(alias);
		return 0;
	}
    alias_delete(alias);
   
    // TODO add your own tests for append, lookup, remove (!!!)


	return 1;
}
