#pragma once
#include <string>
#include <vector>
#include "./token.h"

class Tokenizer {
public:
    std::string source;
    std::vector<Token> tokens;
    size_t start = 0;
    size_t current = 0;
    int line = 1;

    Tokenizer(std::string src) : source(src) {};

    std::vector<Token> scanTokens();
    void scanToken();

    char advance();
    bool match(char target);
    char peek();
    char peekNext();

    void string();
    void number();

    void addToken(TokenType type);
    void addToken(TokenType type, Literal literal);

    bool isAtEnd() const;
};
