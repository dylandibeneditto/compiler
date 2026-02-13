#pragma once
#include "./tokentype.h"
#include <ostream>
#include <sstream>
#include <string>
#include <variant>

using Literal = std::variant<std::monostate, double, std::string, bool>;

class Token {
public:
  TokenType type;
  std::string lexeme;
  Literal literal;
  int line;

  Token(TokenType type, std::string lexeme, Literal literal, int line)
      : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)),
        line(line) {}

  std::string str();
};
