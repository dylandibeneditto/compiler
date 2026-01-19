from enum import Enum, auto
from collections import deque

class TokenType(Enum):
    EXIT = auto()
    PRINT = auto()

    SEMICOLON = auto()
    COMMA = auto()

    LPAREN = auto()
    RPAREN = auto()
    LBRACK = auto()
    RBRACK = auto()
    LSQUARE = auto()
    RSQUARE = auto()

    LET = auto()
    ASSIGN = auto()
    FN = auto()
    RETURN = auto()
    IF = auto()
    ELSE = auto()
    WHILE = auto()

    INT_LITERAL = auto()
    FLOAT_LITERAL = auto()
    BOOL_LITERAL = auto()

    IDENTIFIER = auto()

    PLUS = auto()
    MINUS = auto()
    STAR = auto()
    DIVIDE = auto()
    MODULUS = auto()

    PLUS_ASSIGN = auto()
    MINUS_ASSIGN = auto()
    STAR_ASSIGN = auto()
    DIVIDE_ASSIGN = auto()
    MODULUS_ASSIGN = auto()

    EQ = auto()
    GT = auto()
    LT = auto()
    GTEQ = auto()
    LTEQ = auto()
    NEQ = auto()

    AND = auto()
    OR = auto()
    NOT = auto()

    COLON = auto()
    QUESTION = auto()

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
            case "let":
                return Token(TokenType.LET)
            case "true":
                return Token(TokenType.BOOL_LITERAL, "1")
            case "false":
                return Token(TokenType.BOOL_LITERAL, "0")
            case "fn":
                return Token(TokenType.FN)
            case "return":
                return Token(TokenType.RETURN)
            case "if":
                return Token(TokenType.IF)
            case "else":
                return Token(TokenType.ELSE)
            case "while":
                return Token(TokenType.WHILE)
            case "exit":
                return Token(TokenType.EXIT)
            case "print":
                return Token(TokenType.PRINT)
            case _:
                return Token(TokenType.IDENTIFIER, buffer)

    def integer_or_decimal(self, buffer: str) -> Token:
        if "." in buffer:
            return Token(TokenType.FLOAT_LITERAL, buffer)
        else:
            return Token(TokenType.INT_LITERAL, buffer)

    def match_tokens(self, buffer: str, matches: list[tuple[str, TokenType]]) -> TokenType | None:
        for m in matches:
            target = m[0]
            ttype = m[1]
            if buffer == target:
                return ttype
        return None

    def tokenize(self) -> list[Token]:
        tokens: list[Token] = []

        buffer = deque()
        i: int = 0

        while i < len(self.source):

            def c(index) -> str: # shorthand to make referencing characters better readable
                if index < 0 or index >= len(self.source):
                    return ""
                return self.source[index]

            if c(i).isalpha(): # keyword or identifier

                while c(i).isalnum():
                    print(f"keyword {c(i)} at {i}")
                    buffer.append(c(i))
                    i += 1

                joined_buffer = "".join(buffer)
                tokens.append(self.keyword_or_identifier(joined_buffer))
                buffer.clear()

            elif c(i).isdigit() or c(i) == ".": # integer or float

                while c(i).isdigit() or c(i) == ".":
                    print(f"digit {c(i)} at {i}")
                    buffer.append(c(i))
                    i += 1

                joined_buffer = "".join(buffer)
                tokens.append(self.integer_or_decimal(joined_buffer))
                buffer.clear()

            # elif c(i) == '\"' or c(i) == "\'": # string starting with " or '
            #
            #     check = c(i)
            #
            #     i += 1
            #     while i < len(self.source) and c(i) != check:
            #         if c(i):
            #             print(f"char literal {c(i)} at {i}")
            #         buffer.append(c(i))
            #         i += 1
            #
            #     i += 1
            #
            #     joined_buffer = "".join(buffer)
            #     tokens.append(Token(TokenType.STRING_LITERAL, joined_buffer))
            #     buffer.clear()

            elif c(i).isspace(): # whitespace is ignored

                print(f"whitespace at {i}")
                i += 1

            elif c(i)+c(i+1) == "//": # ignore comments '//'

                i += 2
                while i < len(self.source) and c(i) != "\n":
                    if c(i):
                        print(f"commented out {c(i)}")
                    i += 1

            else: # simple operator checks

                double_matches: list[tuple[str, TokenType]] = [
                    ("||", TokenType.OR),
                    ("&&", TokenType.AND),
                    ("==", TokenType.EQ),
                    (">=", TokenType.GTEQ),
                    ("<=", TokenType.LTEQ),
                    ("!=", TokenType.NEQ),
                    ("+=", TokenType.PLUS_ASSIGN),
                    ("-=", TokenType.MINUS_ASSIGN),
                    ("*=", TokenType.STAR_ASSIGN),
                    ("/=", TokenType.DIVIDE_ASSIGN),
                    ("%=", TokenType.MODULUS_ASSIGN),
                ]

                dt = self.match_tokens(c(i)+c(i+1), double_matches)

                if dt:
                    print(f"{dt} at {i}")
                    tokens.append(Token(dt))
                    i += 1
                else:

                    matches: list[tuple[str, TokenType]] = [
                        (";", TokenType.SEMICOLON),
                        ("=", TokenType.ASSIGN),
                        (",", TokenType.COMMA),
                        ("+", TokenType.PLUS),
                        ("-", TokenType.MINUS),
                        ("*", TokenType.STAR),
                        ("/", TokenType.DIVIDE),
                        ("%", TokenType.MODULUS),
                        ("(", TokenType.LPAREN),
                        (")", TokenType.RPAREN),
                        ("{", TokenType.LBRACK),
                        ("}", TokenType.RBRACK),
                        ("[", TokenType.LSQUARE),
                        ("]", TokenType.RSQUARE),
                        (":", TokenType.COLON),
                        ("!", TokenType.NOT),
                        ("?", TokenType.QUESTION),
                        (">", TokenType.GT),
                        ("<", TokenType.LT),
                    ]

                    t = self.match_tokens(c(i), matches)

                    if t:
                        print(f"{t} at {i}")
                        tokens.append(Token(t))

                i += 1

        return tokens
