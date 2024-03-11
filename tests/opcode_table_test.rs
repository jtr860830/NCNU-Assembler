use sic::OpTable;

#[test]
fn get_opcode_by_mnemonic() {
    let table = OpTable::new();
    assert_eq!(*table.find("ADD").unwrap(), 0x18);
    assert_eq!(*table.find("ADDF").unwrap(), 0x58);
    assert_eq!(*table.find("ADDR").unwrap(), 0x90);
    assert_eq!(*table.find("AND").unwrap(), 0x40);
    assert_eq!(*table.find("CLEAR").unwrap(), 0xB4);
    assert_eq!(*table.find("COMP").unwrap(), 0x28);
    assert_eq!(*table.find("COMPF").unwrap(), 0x88);
    assert_eq!(*table.find("COMPR").unwrap(), 0xA0);
    assert_eq!(*table.find("DIV").unwrap(), 0x24);
    assert_eq!(*table.find("DIVF").unwrap(), 0x64);
    assert_eq!(*table.find("DIVR").unwrap(), 0x9C);
    assert_eq!(*table.find("FIX").unwrap(), 0xC4);
    assert_eq!(*table.find("FLOAT").unwrap(), 0xC0);
    assert_eq!(*table.find("HIO").unwrap(), 0xF4);
    assert_eq!(*table.find("J").unwrap(), 0x3C);
    assert_eq!(*table.find("JEQ").unwrap(), 0x30);
    assert_eq!(*table.find("JGT").unwrap(), 0x34);
    assert_eq!(*table.find("JLT").unwrap(), 0x38);
    assert_eq!(*table.find("JSUB").unwrap(), 0x48);
    assert_eq!(*table.find("LDA").unwrap(), 0x00);
    assert_eq!(*table.find("LDB").unwrap(), 0x68);
    assert_eq!(*table.find("LDCH").unwrap(), 0x50);
    assert_eq!(*table.find("LDF").unwrap(), 0x70);
    assert_eq!(*table.find("LDL").unwrap(), 0x08);
    assert_eq!(*table.find("LDS").unwrap(), 0x6C);
    assert_eq!(*table.find("LDT").unwrap(), 0x74);
    assert_eq!(*table.find("LDX").unwrap(), 0x04);
    assert_eq!(*table.find("LPS").unwrap(), 0xD0);
    assert_eq!(*table.find("MUL").unwrap(), 0x20);
    assert_eq!(*table.find("MULF").unwrap(), 0x60);
    assert_eq!(*table.find("MULR").unwrap(), 0x98);
    assert_eq!(*table.find("NORM").unwrap(), 0xC8);
    assert_eq!(*table.find("OR").unwrap(), 0x44);
    assert_eq!(*table.find("RD").unwrap(), 0xD8);
    assert_eq!(*table.find("RMO").unwrap(), 0xAC);
    assert_eq!(*table.find("RSUB").unwrap(), 0x4C);
    assert_eq!(*table.find("SHIFTL").unwrap(), 0xA4);
    assert_eq!(*table.find("SHIFTR").unwrap(), 0xA8);
    assert_eq!(*table.find("SIO").unwrap(), 0xF0);
    assert_eq!(*table.find("SSK").unwrap(), 0xEC);
    assert_eq!(*table.find("STA").unwrap(), 0x0C);
    assert_eq!(*table.find("STB").unwrap(), 0x78);
    assert_eq!(*table.find("STCH").unwrap(), 0x54);
    assert_eq!(*table.find("STF").unwrap(), 0x80);
    assert_eq!(*table.find("STI").unwrap(), 0xD4);
    assert_eq!(*table.find("STL").unwrap(), 0x14);
    assert_eq!(*table.find("STS").unwrap(), 0x7C);
    assert_eq!(*table.find("STSW").unwrap(), 0xE8);
    assert_eq!(*table.find("STT").unwrap(), 0x84);
    assert_eq!(*table.find("STX").unwrap(), 0x10);
    assert_eq!(*table.find("SUB").unwrap(), 0x1C);
    assert_eq!(*table.find("SUBF").unwrap(), 0x5C);
    assert_eq!(*table.find("SUBR").unwrap(), 0x94);
    assert_eq!(*table.find("SVC").unwrap(), 0xB0);
    assert_eq!(*table.find("TD").unwrap(), 0xE0);
    assert_eq!(*table.find("TIO").unwrap(), 0xF8);
    assert_eq!(*table.find("TIX").unwrap(), 0x2C);
    assert_eq!(*table.find("TIXR").unwrap(), 0xB8);
    assert_eq!(*table.find("WD").unwrap(), 0xDC);
}

#[test]
fn unknown_mnemonic_should_return_none() {
    let table = OpTable::new();
    assert_eq!(table.find("UNKNOWN"), None);
}
