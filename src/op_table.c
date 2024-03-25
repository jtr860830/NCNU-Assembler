#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"
#include "op_table.h"

// SIC opcode table
op_table_t *new_op_table(void) {
  op_table_t *op_table = malloc(sizeof(op_table_t));
  if (op_table == NULL) {
    fprintf(stderr, "Failed to allocate memory for op_table\n");
    return NULL;
  }
  op_table->table = new_map(59);
  if (op_table->table == NULL) {
    free(op_table);
    return NULL;
  }
  map_insert(op_table->table, "ADD", 0x18);
  map_insert(op_table->table, "ADDF", 0x58);
  map_insert(op_table->table, "ADDR", 0x90);
  map_insert(op_table->table, "AND", 0x40);
  map_insert(op_table->table, "CLEAR", 0xB4);
  map_insert(op_table->table, "COMP", 0x28);
  map_insert(op_table->table, "COMPF", 0x88);
  map_insert(op_table->table, "COMPR", 0xA0);
  map_insert(op_table->table, "DIV", 0x24);
  map_insert(op_table->table, "DIVF", 0x64);
  map_insert(op_table->table, "DIVR", 0x9C);
  map_insert(op_table->table, "FIX", 0xC4);
  map_insert(op_table->table, "FLOAT", 0xC0);
  map_insert(op_table->table, "HIO", 0xF4);
  map_insert(op_table->table, "J", 0x3C);
  map_insert(op_table->table, "JEQ", 0x30);
  map_insert(op_table->table, "JGT", 0x34);
  map_insert(op_table->table, "JLT", 0x38);
  map_insert(op_table->table, "JSUB", 0x48);
  map_insert(op_table->table, "LDA", 0x00);
  map_insert(op_table->table, "LDB", 0x68);
  map_insert(op_table->table, "LDCH", 0x50);
  map_insert(op_table->table, "LDF", 0x70);
  map_insert(op_table->table, "LDL", 0x08);
  map_insert(op_table->table, "LDS", 0x6C);
  map_insert(op_table->table, "LDT", 0x74);
  map_insert(op_table->table, "LDX", 0x04);
  map_insert(op_table->table, "LPS", 0xD0);
  map_insert(op_table->table, "MUL", 0x20);
  map_insert(op_table->table, "MULF", 0x60);
  map_insert(op_table->table, "MULR", 0x98);
  map_insert(op_table->table, "NORM", 0xC8);
  map_insert(op_table->table, "OR", 0x44);
  map_insert(op_table->table, "RD", 0xD8);
  map_insert(op_table->table, "RMO", 0xAC);
  map_insert(op_table->table, "RSUB", 0x4C);
  map_insert(op_table->table, "SHIFTL", 0xA4);
  map_insert(op_table->table, "SHIFTR", 0xA8);
  map_insert(op_table->table, "SIO", 0xF0);
  map_insert(op_table->table, "SSK", 0xEC);
  map_insert(op_table->table, "STA", 0x0C);
  map_insert(op_table->table, "STB", 0x78);
  map_insert(op_table->table, "STCH", 0x54);
  map_insert(op_table->table, "STF", 0x80);
  map_insert(op_table->table, "STI", 0xD4);
  map_insert(op_table->table, "STL", 0x14);
  map_insert(op_table->table, "STS", 0x7C);
  map_insert(op_table->table, "STSW", 0xE8);
  map_insert(op_table->table, "STT", 0x84);
  map_insert(op_table->table, "STX", 0x10);
  map_insert(op_table->table, "SUB", 0x1C);
  map_insert(op_table->table, "SUBF", 0x5C);
  map_insert(op_table->table, "SUBR", 0x94);
  map_insert(op_table->table, "SVC", 0xB0);
  map_insert(op_table->table, "TD", 0xE0);
  map_insert(op_table->table, "TIO", 0xF8);
  map_insert(op_table->table, "TIX", 0x2C);
  map_insert(op_table->table, "TIXR", 0xB8);
  map_insert(op_table->table, "WD", 0xDC);
  return op_table;
}

void free_op_table(op_table_t *op_table) {
  free_map(op_table->table);
  free(op_table);
}

uint8_t op_table_find(op_table_t *op_table, char *key) {
  return map_find(op_table->table, key);
}

void op_table_print(op_table_t *op_table) { map_print(op_table->table); }
