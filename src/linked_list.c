#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

list_t *new_list(void) {
  list_t *list = malloc(sizeof(list_t));
  if (list == NULL) {
    fprintf(stderr, "Failed to allocate memory for list\n");
    return NULL;
  }
  list->head = NULL;
  list->length = 0;
  return list;
}

void free_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = current->next;
    free_node(current);
    current = next;
  }
  free(list);
}

node_t *new_node(char *key, uint8_t value) {
  node_t *node = malloc(sizeof(node_t));
  if (node == NULL) {
    fprintf(stderr, "Failed to allocate memory for node\n");
    return NULL;
  }
  node->key = key;
  node->value = value;
  node->next = NULL;
  return node;
}

void free_node(node_t *node) { free(node); }

bool list_is_empty(list_t *list) {
  return (list->head == NULL) && (list->length == 0);
}

node_t *list_find_node(list_t *list, char *key) {
  node_t *current = list->head;
  while (current != NULL) {
    if (strcmp(current->key, key) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void list_print(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    printf("%s:%02x -> ", current->key, current->value);
    current = current->next;
  }
  printf("\n");
}

bool list_append(list_t *list, node_t *node) {
  if (list_is_empty(list)) {
    list->head = node;
  } else {
    node_t *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
  list->length++;
  return true;
}

bool list_insert_after(list_t *list, node_t *target, node_t *node) {
  if (target == NULL) {
    return false;
  }
  node_t *next = target->next;
  target->next = node;
  node->next = next;
  list->length++;
  return true;
}

bool list_insert_before(list_t *list, node_t *target, node_t *node) {
  if (target == NULL) {
    return false;
  }
  node_t **indirect = &list->head;
  while ((*indirect) != target) {
    indirect = &(*indirect)->next;
  }
  *indirect = node;
  node->next = target;
  list->length++;
  return true;
}

node_t *list_remove(list_t *list, node_t *node) {
  if (node == NULL) {
    return NULL;
  }
  node_t **indirect = &list->head;
  while ((*indirect) != node) {
    indirect = &(*indirect)->next;
  }
  *indirect = node->next;
  list->length--;
  return node;
}
