#include "./tokenizer.h"
#include "../scan/scan.h"
#include "./token.h"
#include <iostream>
#include <string>
#include <variant>
#include <vector>

std::vector<Token> Tokenizer::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }

  tokens.push_back(Token(TokenType::END_OF_FILE, "", std::monostate{}, line));
  return tokens;
}

void Tokenizer::scanToken() {
  char c = advance();
  switch (c) {
  case ')':
    addToken(TokenType::RIGHT_PAREN);
    break;
  case '(':
    addToken(TokenType::LEFT_PAREN);
    break;
  case ']':
    addToken(TokenType::RIGHT_SQUARE);
    break;
  case '[':
    addToken(TokenType::LEFT_SQUARE);
    break;
  case '}':
    addToken(TokenType::RIGHT_BRACE);
    break;
  case '{':
    addToken(TokenType::LEFT_BRACE);
    break;
  case '+':
    addToken(TokenType::PLUS);
    break;
  case '-':
    addToken(TokenType::MINUS);
    break;
  case '*':
    addToken(TokenType::STAR);
    break;
  case '/':
    if (match('/')) {
      while (peek() != '\n' && !isAtEnd())
        advance();
    } else {
      addToken(TokenType::SLASH);
    }
    break;
  case '%':
    addToken(TokenType::MOD);
    break;
  case '.':
    addToken(TokenType::DOT);
    break;
  case ',':
    addToken(TokenType::COMMA);
    break;
  case ';':
    addToken(TokenType::SEMICOLON);
    break;
  case ':':
    addToken(TokenType::COLON);
    break;
  case '!':
    addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    break;
  case '>':
    addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  case '<':
    addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    break;

  case '"':
    string();
    break;

  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    line++;
    break;
  default:
    if (std::isdigit(c)) {
      number();
    } else {
      Scan::error(line, "Unexpected character: " + std::string(1, c));
    }
    break;
  }
}

char Tokenizer::advance() {
  if (isAtEnd())
    return '\0';
  return source.at(current++);
}

void Tokenizer::number() {
  while (std::isdigit(peek()))
    advance();

  if (peek() == '.' && std::isdigit(peekNext())) {
    advance(); // consume decimal

    while (std::isdigit(peek()))
      advance();
  }

  addToken(TokenType::NUMBER, std::stod(source.substr(start, current - start)));
}

void Tokenizer::string() {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n')
      line++;
    advance();
  }

  if (isAtEnd()) {
    Scan::error(line, "Unterminated String.");
    return;
  }

  advance(); // enclose the final quote

  std::string sub =
      source.substr(start + 1, current - start - 2); // excludes quotes
  std::cout << sub << std::endl;
  addToken(TokenType::STRING, sub);
}

bool Tokenizer::match(char target) {
  if (isAtEnd())
    return false;
  if (source.at(current) != target)
    return false;

  current++;
  return true;
}

char Tokenizer::peek() {
  if (isAtEnd())
    return '\0';
  return source.at(current);
}

char Tokenizer::peekNext() {
  if (current + 1 >= source.length())
    return '\0';
  return source.at(current + 1);
}

void Tokenizer::addToken(TokenType type) { addToken(type, std::monostate{}); }

void Tokenizer::addToken(TokenType type, Literal literal) {
  if (current < start)
    return; // safety guard

  std::string sub = source.substr(start, current - start);
  tokens.push_back(Token(type, sub, literal, line));
}

bool Tokenizer::isAtEnd() const { return current >= source.length(); }
