from tokens import Token, Tokenizer, TokenType
from dataclasses import dataclass

class Expression:
    pass

class Statement:
    pass

@dataclass
class Literal(Expression):
    value: str

@dataclass
class Variable(Expression):
    name: str

@dataclass
class Binary(Expression):
    left: Expression
    operator: str
    right: Expression

@dataclass
class Unary(Expression):
    operator: str
    operand: Expression

@dataclass
class Let(Statement):
    # let name = expression;
    name: str
    initializer: Expression

@dataclass
class Exit(Statement):
    # exit value;
    value: Expression

class Parser:

    def __init__(self, tokens: list[Token]):
        self.tokens = tokens
        self.index = 0

    def current(self) -> Token:
        if self.index >= len(self.tokens):
            return Token(TokenType.EOF)
        return self.tokens[self.index]

    def advance(self) -> Token:
        t = self.current()
        self.index += 1
        return t

    def expect(self, kind: TokenType) -> Token:
        if self.current().type != kind:
            raise SyntaxError(f"{self.current().type} is not of type {kind}")
        return self.advance()

    def precedence(self, token: TokenType) -> int:
        match token:
            case TokenType.STAR | TokenType.DIVIDE | TokenType.MODULUS:
                return 20
            case TokenType.PLUS | TokenType.MINUS | TokenType.NOT:
                return 10
            case TokenType.EQ | TokenType.GTEQ | TokenType.LTEQ | TokenType.GT | TokenType.LT:
                return 5
            case _:
                return -1

    def parse_primary(self) -> Expression:
        token = self.advance()

        match token.type:
            case TokenType.INT_LITERAL | TokenType.FLOAT_LITERAL | TokenType.BOOL_LITERAL:
                return Literal(token.value)
            case TokenType.IDENTIFIER:
                return Variable(token.value)
            case TokenType.LPAREN:
                expr = self.parse_expression()
                self.expect(TokenType.RPAREN)
                return expr

    def parse_expression(self, min_precedence=0) -> Expression:
        left = self.parse_primary()

        while True:
            token = self.current()
            if token.type == TokenType.EOF:
                break

            prec = self.precedence(token.type)
            if prec < min_precedence:
                break

            operator = self.advance()
            right = self.parse_expression(self.precedence(operator)+1)
            left = Binary(left, operator, right)

        return left

    def parse_assignment(self):
        self.expect(TokenType.LET)
        name = self.expect(TokenType.IDENTIFIER).value
        self.expect(TokenType.ASSIGN)
        expr = self.parse_expression()
        self.expect(TokenType.SEMICOLON)
        return Let(name, expr)

    def parse_exit(self):
        self.expect(TokenType.EXIT)
        expr = self.parse_expression()
        self.expect(TokenType.SEMICOLON)
        return Exit(expr)

    def parse_statement(self):
        match self.current().type:
            case TokenType.LET:
                return self.parse_assignment()
            case TokenType.EXIT:
                return self.parse_exit()

        raise ValueError("expected statement")

    def parse(self):
        statements = []
        while self.current().type != TokenType.EOF:
            statements.append(self.parse_statement())
        return statements
