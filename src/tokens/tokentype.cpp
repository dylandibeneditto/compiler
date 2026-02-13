#include "./tokentype.h"

extern const std::unordered_map<std::string, TokenType> keywords = {
    {"and", TokenType::AND},       {"or", TokenType::OR},
    {"if", TokenType::IF},         {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},   {"true", TokenType::TRUE},
    {"class", TokenType::CLASS},   {"super", TokenType::SUPER},
    {"this", TokenType::THIS},     {"let", TokenType::LET},
    {"nil", TokenType::NIL},       {"fn", TokenType::FN},
    {"return", TokenType::RETURN}, {"for", TokenType::FOR},
    {"while", TokenType::WHILE},   {"print", TokenType::PRINT},
};

std::ostream &operator<<(std::ostream &os, TokenType type) {
  static const std::string nameToken[] = {
      // single char
      // parens
      "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_SQUARE",
      "RIGHT_SQUARE",

      // arithm
      "PLUS", "MINUS", "STAR", "SLASH", "MOD",
      // other
      "DOT", "COMMA", "SEMICOLON", "COLON",

      "BANG", "BANG_EQUAL", "EQUAL", "EQUAL_EQUAL", "GREATER", "GREATER_EQUAL",
      "LESS", "LESS_EQUAL",

      // literals
      "IDENTIFIER", "STRING", "NUMBER",

      // keywords
      "AND", "OR", "IF", "ELSE", "FALSE", "TRUE", "CLASS", "SUPER", "THIS",
      "LET", "NIL", "FN", "RETURN", "FOR", "WHILE", "PRINT",

      "END_OF_FILE"};
  return os << nameToken[static_cast<int>(type)];
}
