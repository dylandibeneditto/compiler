#include "./tokentype.h"

extern const std::unordered_map<std::string, TokenType> keywords = {
    {"and", TokenType::AND},       {"or", TokenType::OR},
    {"if", TokenType::IF},         {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},   {"true", TokenType::TRUE},
    {"class", TokenType::CLASS},   {"super", TokenType::SUPER},
    {"this", TokenType::THIS},     {"let", TokenType::LET},
    {"nil", TokenType::NIL},       {"fn", TokenType::FN},
    {"return", TokenType::RETURN}, {"for", TokenType::FOR},
    {"WHILE", TokenType::WHILE},   {"PRINT", TokenType::PRINT},
};
