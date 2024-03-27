from typing import Dict


class OpcodeTable:
    # 設定 __table 為 private 變數 (只能在 class 內部使用)
    __table: Dict[str, int]

    # 初始化 OpcodeTable
    def __init__(self, table: Dict[str, int]):
        self.__table = table

    # 透過檔案建立 OpcodeTable，cls 是 class 的簡寫，指的是 OpcodeTable 本身
    @classmethod
    def from_file(cls, file_name: str) -> "OpcodeTable":
        table: Dict[str, int] = {}
        with open(file_name, "r") as file:
            for line in file:
                mnemonic, opcode = line.strip().split()
                table[mnemonic] = int(opcode, 16)
        return cls(table)

    # 用助記詞尋找對應的 opcode
    def find(self, mnemonic: str) -> int | None:
        return self.__table.get(mnemonic, None)


def main():
    opcode_table = OpcodeTable.from_file("opCode.txt")
    mnemonic = input("search(Input a mnemonic): ").strip().upper()
    opcode = opcode_table.find(mnemonic)
    # 使用 16 進位印出 Opcode，如果找不到助記詞，就印出 "Invalid mnemonic!"
    print(f"opCode: 0x{opcode:02X}" if opcode is not None else "Invalid mnemonic!")


if __name__ == "__main__":
    main()
