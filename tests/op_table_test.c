#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "op_table.h"

int main(void) {
  op_table_t *table = new_op_table();
  // read user input and find opcode
  char mnemonic[10] = {0};
  while (true) {
    printf("Enter mnemonic: ");
    scanf("%s", mnemonic);
    if (strcmp(mnemonic, "exit") == 0) {
      break;
    }
    uint8_t code = op_table_find(table, mnemonic);
    printf("Opcode: 0x%02x\n", code);
  }
  free_op_table(table);
  return EXIT_SUCCESS;
}
