#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "linked_list.h"

typedef struct Map {
  size_t size;
  list_t *buckets;
} map_t;

uint32_t hash(char *);
map_t *new_map(size_t);
void free_map(map_t *);
bool map_is_empty(map_t *);
uint8_t map_find(map_t *, char *);
bool map_insert(map_t *, char *, uint8_t);
void map_print(map_t *);

#endif // !HASH_MAP_H
