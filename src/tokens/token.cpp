#include "./token.h"
#include <string>

std::string Token::str() {
  std::stringstream ss;

  ss << type << " " << lexeme << " ";

  std::visit(
      [&](auto &&value) {
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, std::monostate>) {
          ss << "nil";
        } else {
          ss << value;
        }
      },
      literal);

  ss << " (line " << line << ")";
  return ss.str();
}
