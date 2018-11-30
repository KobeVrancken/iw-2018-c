#ifndef LIST_H_INC
#define LIST_H_INC

/* ==================== ALIAS KEY->VALUE ==================== */

struct alias {
	char *key;
	char *value;
    struct alias *next;
};

struct alias *alias_create(char *key, char *value);
void alias_delete(struct alias *alias);
void alias_print(struct alias *alias);


/* ==================== ALIAS LOOKUP: SINGLE LINKED LIST ==================== */

struct alias_list {
    struct alias *first;
};

struct alias_list *alias_list_create(void);
void alias_list_print(struct alias_list *list);
int alias_list_length(struct alias_list *list);
void alias_list_delete(struct alias_list *list);

void alias_list_append(struct alias_list *list, char *key, char *value);
char *alias_list_lookup(struct alias_list *list, char *key);
int alias_list_remove(struct alias_list *list, char *key);


/* ==================== TEST ==================== */

int alias_list_test(void);

#endif
