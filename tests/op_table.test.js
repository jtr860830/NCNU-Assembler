import { describe, it } from "node:test";
import assert from "node:assert";

import OpTable from "../op_table.js";

describe("test SIC opcode table", () => {
  const table = new OpTable();

  it("should find opcode by valid mnemonic", () => {
    assert.strictEqual(table.find("ADD"), 0x18);
    assert.strictEqual(table.find("ADDF"), 0x58);
    assert.strictEqual(table.find("ADDR"), 0x90);
    assert.strictEqual(table.find("AND"), 0x40);
    assert.strictEqual(table.find("CLEAR"), 0xb4);
    assert.strictEqual(table.find("COMP"), 0x28);
    assert.strictEqual(table.find("COMPF"), 0x88);
    assert.strictEqual(table.find("COMPR"), 0xa0);
    assert.strictEqual(table.find("DIV"), 0x24);
    assert.strictEqual(table.find("DIVF"), 0x64);
    assert.strictEqual(table.find("DIVR"), 0x9c);
    assert.strictEqual(table.find("FIX"), 0xc4);
    assert.strictEqual(table.find("FLOAT"), 0xc0);
    assert.strictEqual(table.find("HIO"), 0xf4);
    assert.strictEqual(table.find("J"), 0x3c);
    assert.strictEqual(table.find("JEQ"), 0x30);
    assert.strictEqual(table.find("JGT"), 0x34);
    assert.strictEqual(table.find("JLT"), 0x38);
    assert.strictEqual(table.find("JSUB"), 0x48);
    assert.strictEqual(table.find("LDA"), 0x00);
    assert.strictEqual(table.find("LDB"), 0x68);
    assert.strictEqual(table.find("LDCH"), 0x50);
    assert.strictEqual(table.find("LDF"), 0x70);
    assert.strictEqual(table.find("LDL"), 0x08);
    assert.strictEqual(table.find("LDS"), 0x6c);
    assert.strictEqual(table.find("LDT"), 0x74);
    assert.strictEqual(table.find("LDX"), 0x04);
    assert.strictEqual(table.find("LPS"), 0xd0);
    assert.strictEqual(table.find("MUL"), 0x20);
    assert.strictEqual(table.find("MULF"), 0x60);
    assert.strictEqual(table.find("MULR"), 0x98);
    assert.strictEqual(table.find("NORM"), 0xc8);
    assert.strictEqual(table.find("OR"), 0x44);
    assert.strictEqual(table.find("RD"), 0xd8);
    assert.strictEqual(table.find("RMO"), 0xac);
    assert.strictEqual(table.find("RSUB"), 0x4c);
    assert.strictEqual(table.find("SHIFTL"), 0xa4);
    assert.strictEqual(table.find("SHIFTR"), 0xa8);
    assert.strictEqual(table.find("SIO"), 0xf0);
    assert.strictEqual(table.find("SSK"), 0xec);
    assert.strictEqual(table.find("STA"), 0x0c);
    assert.strictEqual(table.find("STB"), 0x78);
    assert.strictEqual(table.find("STCH"), 0x54);
    assert.strictEqual(table.find("STF"), 0x80);
    assert.strictEqual(table.find("STI"), 0xd4);
    assert.strictEqual(table.find("STL"), 0x14);
    assert.strictEqual(table.find("STS"), 0x7c);
    assert.strictEqual(table.find("STSW"), 0xe8);
    assert.strictEqual(table.find("STT"), 0x84);
    assert.strictEqual(table.find("STX"), 0x10);
    assert.strictEqual(table.find("SUB"), 0x1c);
    assert.strictEqual(table.find("SUBF"), 0x5c);
    assert.strictEqual(table.find("SUBR"), 0x94);
    assert.strictEqual(table.find("SVC"), 0xb0);
    assert.strictEqual(table.find("TD"), 0xe0);
    assert.strictEqual(table.find("TIO"), 0xf8);
    assert.strictEqual(table.find("TIX"), 0x2c);
    assert.strictEqual(table.find("WD"), 0xdc);
  });

  it("should return undefined for invalid mnemonic", () => {
    assert.strictEqual(table.find("UNKNOWN"), undefined);
  });
});
