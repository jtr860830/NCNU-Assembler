use std::collections::HashMap;

pub enum Address {
    Unallocated,
    Allocated(u32),
}

pub struct Symbol {
    address: Address,
    waiting_list: Vec<u32>,
}

pub struct SymbolTable {
    table: HashMap<String, Symbol>,
}

impl SymbolTable {
    pub fn new() -> SymbolTable {
        SymbolTable {
            table: HashMap::new(),
        }
    }

    pub fn is_label_legal(label: &str) -> bool {
        // Check if the label is empty
        if label.is_empty() {
            return false;
        }

        // Check format
        let mut chars = label.chars();
        match chars.next() {
            Some(c) if c.is_ascii_uppercase() => (),
            _ => return false,
        }
        for c in chars {
            if !c.is_ascii_uppercase() && !c.is_ascii_digit() {
                return false;
            }
        }
        
        true
    }

    pub fn insert(&mut self, label: String, address: Address) -> () {}

    pub fn remove(&mut self, label: &str) -> () {}

    pub fn find(&self, label: &str) -> () {}

    pub fn update(&mut self, label: &str, address: Address) -> () {}

    pub fn print(&self) {
        for (label, symbol) in &self.table {
            match symbol.address {
                Address::Unallocated => println!("{}: Unallocated", label),
                Address::Allocated(addr) => println!("{}: Allocated at {}", label, addr),
            }
        }
    }
}
