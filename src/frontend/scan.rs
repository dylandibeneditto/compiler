use std::fs;
use std::io::{self, Write};
use std::process;

use crate::frontend::{Tokenizer, TokenType};

pub struct Scan {
    had_error: bool,
}

impl Scan {
    pub fn new() -> Self {
        return Self {
            had_error: false,
        }
    }

    pub fn run_file(&mut self, file: &str) {
        let source = fs::read_to_string(file)
            .unwrap_or_else(|_| panic!("Failed to read file {}", file));

        self.run(&source);
    }

    pub fn run(&mut self, content: str) {
        if self.had_error {
            process::exit(65);
        }

        let mut tokenizer = Tokenizer::new(content);
        let tokens: Vec<Token> = tokenize.scan_tokens();

        for i in tokens {
            println!("{}", i);
        }
    }
}
