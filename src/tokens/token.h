#pragma once
#include <string>
#include <variant>
#include <sstream>
#include <ostream>
#include "./tokentype.h"

using Literal = std::variant<std::monostate, double, std::string, bool>;

class Token {
public:
    TokenType type;
    std::string lexeme;
    Literal literal;
    int line;

    Token(TokenType type, std::string lexeme, Literal literal, int line) : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}

    std::string str() const {
        std::stringstream ss;

        ss << static_cast<int>(type) << " " << lexeme << " ";

        std::visit([&](auto&& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, std::monostate>) {
                ss << "nil";
            } else {
                ss << value;
            }
        }, literal);

        ss << " (line " << line << ")";
        return ss.str();
    }
};

inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    return os << token.str();
}
