use crate::frontend::{TokenType, Literal}

pub struct Token {
    ty: TokenType,
    lexeme: str,
    literal: Literal,
    line: usize,
}

impl Token {
    pub fn new(
    ty: TokenType,
    lexeme: str,
    literal: Literal,
    line: usize) -> Self {
        Self {
            ty,
            lexeme,
            literal,
            line
        }
    }
}
