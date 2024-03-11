use sic::OpTable;
use std::io::{self, Write};

fn main() {
    let op_table = OpTable::new();
    let mut input = String::new();

    // helper message
    println!("Enter a mnemonic to get its opcode, or type 'exit' to quit:");

    loop {
        // Clear input_string for the next input
        input.clear();

        print!("Mnemonic: ");
        // Ensure the "Mnemonic: " prompt is displayed immediately
        io::stdout().flush().unwrap();

        // Get user input
        match io::stdin().read_line(&mut input) {
            Ok(_) => {
                // Remove potential whitespace or newline character
                let mnemonic = input.trim();

                // Check if the input is 'exit'
                if mnemonic.eq_ignore_ascii_case("exit") {
                    break;
                }

                match op_table.find(mnemonic) {
                    Some(opcode) => println!("Opcode for '{}': 0x{:X}\n", mnemonic, opcode),
                    None => println!("No opcode found for '{}'\n", mnemonic),
                }
            }
            Err(error) => println!("Error reading input: {}\n", error),
        }
    }
}
