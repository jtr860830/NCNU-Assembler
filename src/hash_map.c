#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"
#include "linked_list.h"

uint32_t hash(char *key) {
  uint32_t hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

map_t *new_map(size_t size) {
  map_t *map = malloc(sizeof(map_t));
  if (map == NULL) {
    fprintf(stderr, "Failed to allocate memory for map\n");
    return NULL;
  }
  map->size = size;
  map->buckets = malloc(size * sizeof(list_t));
  if (map->buckets == NULL) {
    fprintf(stderr, "Failed to allocate memory for buckets\n");
    free(map);
    return NULL;
  }
  for (size_t i = 0; i < size; i++) {
    map->buckets[i] = *new_list();
  }
  return map;
}

void free_map(map_t *map) {
  for (size_t i = 0; i < map->size; i++) {
    free_list(&map->buckets[i]);
  }
  free(map->buckets);
  free(map);
}

bool map_is_empty(map_t *map) {
  for (size_t i = 0; i < map->size; i++) {
    if (!list_is_empty(&map->buckets[i])) {
      return false;
    }
  }
  return true;
}

uint8_t map_find(map_t *map, char *key) {
  size_t index = hash(key) % map->size;
  node_t *node = list_find_node(&map->buckets[index], key);
  if (node == NULL) {
    return 0;
  }
  return node->value;
}

bool map_insert(map_t *map, char *key, uint8_t value) {
  size_t index = hash(key) % map->size;
  node_t *node = new_node(key, value);
  if (node == NULL) {
    return false;
  }
  return list_append(&map->buckets[index], node);
}

void map_print(map_t *map) {
  for (size_t i = 0; i < map->size; i++) {
    printf("%zu: ", i);
    list_print(&map->buckets[i]);
  }
}
