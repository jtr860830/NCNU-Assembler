#ifndef OP_TABLE_H
#define OP_TABLE_H

#include <stdint.h>

#include "hash_map.h"

typedef struct OpTable {
  map_t *table;
} op_table_t;

op_table_t *new_op_table(void);
void free_op_table(op_table_t *);
uint8_t op_table_find(op_table_t *, char *);
void op_table_print(op_table_t *);

#endif // !OP_TABLE_H
