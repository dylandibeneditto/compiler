from enum import Enum, auto
from collections import deque

class TokenType(Enum):
    EXIT = auto()
    INT_LITERAL = auto()
    FLOAT_LITERAL = auto()
    IDENTIFIER = auto()
    SEMICOLON = auto()

class Token:
    def __init__(self, type: TokenType, value: str | None = None):
        self.type = type
        self.value = value

    def __repr__(self):
        return f"{self.type.name}{f'({self.value})' if self.value is not None else ''}"

class Tokenizer:
    def __init__(self, source: str):
        self.source = source

    def keyword_or_identifier(self, buffer: str) -> Token:
        match buffer:
            case "exit":
                return Token(TokenType.EXIT)
            case _:
                return Token(TokenType.IDENTIFIER, buffer)

    def integer_or_decimal(self, buffer: str) -> Token:
        if "." in buffer:
            return Token(TokenType.FLOAT_LITERAL, buffer)
        else:
            return Token(TokenType.INT_LITERAL, buffer)

    def single_char_operator(self, buffer: str) -> Token | KeyError:
        match buffer:
            case ";":
                return Token(TokenType.SEMICOLON)
            case _:
                return KeyError(f"Couldn't resolve single character operator token: {buffer}")

    def tokenize(self) -> list[Token]:
        tokens: list[Token] = []

        buffer = deque()
        i: int = 0

        while i < len(self.source):

            def c(index) -> str: # shorthand to make referencing characters better readable
                return self.source[index]

            if c(i).isalpha(): # keyword or identifier

                while(c(i).isalnum()):
                    print(f"keyword {c(i)} at {i}")
                    buffer.append(c(i))
                    i += 1

                joined_buffer = "".join(buffer)
                tokens.append(self.keyword_or_identifier(joined_buffer))
                buffer.clear()

            elif c(i).isdigit() or c(i) == ".": # integer or decimal

                while(c(i).isdigit() or c(i) == "."):
                    print(f"digit {c(i)} at {i}")
                    buffer.append(c(i))
                    i += 1

                joined_buffer = "".join(buffer)
                tokens.append(self.integer_or_decimal(joined_buffer))
                buffer.clear()

            elif c(i).isspace(): # whitespace is ignored

                print(f"whitespace at {i}")
                i += 1

            else: # single character operator

                t = self.single_char_operator(c(i))
                if isinstance(t, Token):
                    tokens.append(t)
                i += 1

        return tokens
