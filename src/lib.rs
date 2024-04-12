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

    pub fn insert(&mut self, label: String, address: Address) -> Result<(), String> {
        if !SymbolTable::is_label_legal(&label) {
            return Err("Illegal label".to_string());
        }

        if self.is_label_exists(&label) {
            return Err("Label already exists".to_string());
        }

        self.table.insert(label, Symbol {
            address,
            waiting_list: Vec::new(),
        });

        Ok(())
    }

    pub fn find(&self, label: &str) -> Option<&Symbol> {
        self.table.get(label)
    }

    pub fn push_waiting_list(&mut self, label: &str, address: u32) -> Result<(), String> {
        if !self.is_label_exists(label) {
            return Err("Label does not exist".to_string());
        }

        let symbol = self.table.get_mut(label).unwrap();
        match symbol.address {
            Address::Unallocated => {
                symbol.waiting_list.push(address);
            },
            Address::Allocated(_) => {
                return Err("Label already allocated".to_string());
            },
        }

        Ok(())
    }

    pub fn allocate(&mut self, label: &str, address: u32) -> Result<(), String> {
        if !self.is_label_exists(label) {
            return Err("Label does not exist".to_string());
        }

        let symbol = self.table.get_mut(label).unwrap();
        match symbol.address {
            Address::Unallocated => {
                symbol.address = Address::Allocated(address);
            },
            Address::Allocated(_) => {
                return Err("Label already allocated".to_string());
            },
        }

        Ok(())
    }

    pub fn print(&self) {
        for (label, symbol) in &self.table {
            match symbol.address {
                Address::Unallocated => println!("{}: Unallocated", label),
                Address::Allocated(addr) => println!("{}: Allocated at {}", label, addr),
            }
        }
    }

    pub fn is_label_exists(&self, label: &str) -> bool {
        self.table.contains_key(label)
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
}
