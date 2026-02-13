#include <string>
#include <unordered_map>

enum TokenType {
  // single char
  // parens
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_SQUARE,
  RIGHT_SQUARE,

  // arithm
  PLUS,
  MINUS,
  STAR,
  SLASH,
  MOD,
  // other
  DOT,
  COMMA,
  SEMICOLON,
  COLON,

  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  // literals
  IDENTIFIER,
  STRING,
  NUMBER,

  // keywords
  AND,
  OR,
  IF,
  ELSE,
  FALSE,
  TRUE,
  CLASS,
  SUPER,
  THIS,
  LET,
  NIL,
  FN,
  RETURN,
  FOR,
  WHILE,
  PRINT,

  END_OF_FILE
};

extern const std::unordered_map<std::string, TokenType> keywords;

std::ostream &operator<<(std::ostream &os, TokenType type);
