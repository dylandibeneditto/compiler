#include <string>
#include <vector>
#include <variant>
#include "./token.h"
#include "./tokenizer.h"

std::vector<Token> Tokenizer::scanTokens() {
    while(!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", std::monostate{}, line));
    return tokens;
}

void Tokenizer::scanToken() {
    char c = advance();
    switch(c) {
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '(': addToken(TokenType::LEFT_PAREN); break;
    }
}

char Tokenizer::advance() {
    if(isAtEnd()) return '\0';
    return source.at(current++);
}

void Tokenizer::addToken(TokenType type) {
    addToken(type, std::monostate{});
}

void Tokenizer::addToken(TokenType type, Literal literal) {
    if (current < start) return;  // safety guard

    std::string sub = source.substr(start, current-start);
    tokens.push_back(Token(type, sub, literal, line));
}

bool Tokenizer::isAtEnd() const {
    return current >= source.length();
}
