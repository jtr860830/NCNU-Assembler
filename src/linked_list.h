#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct Node node_t;
typedef struct List list_t;

typedef struct Node {
  char *key;
  uint8_t value;
  node_t *next;
} node_t;

typedef struct List {
  node_t *head;
  size_t length;
} list_t;

node_t *new_node(char *, uint8_t);
void free_node(node_t *);
list_t *new_list(void);
void free_list(list_t *);
bool list_is_empty(list_t *);
node_t *list_find_node(list_t *, char *);
void list_print(list_t *);
bool list_append(list_t *, node_t *);
bool list_insert_after(list_t *, node_t *, node_t *);
bool list_insert_before(list_t *, node_t *, node_t *);
node_t *list_remove(list_t *, node_t *);

#endif // !LINKED_LIST_H
