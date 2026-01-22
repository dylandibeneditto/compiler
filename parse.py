from token import Token, Tokenizer, TokenType

class Expression:
    pass

class Statement:
    pass

class Literal(Expression):
    def __init__(self, value):
        self.value = value

class Variable(Expression):
    def __init__(self, name):
        self.name = name

class Binary(Expression):
    def __init__(self, left: Expression, operator: str, right: Expression):
        self.left = left
        self.operator = operator
        self.right = right

class Unary(Expression):
    def __init__(self, operator: str, operand: Expression):
        self.operator = operator
        self.operand = operand

class Let(Statement):
    # let name = expression;
    def __init__(self, name: str, initializer: Expression):
        self.name = name
        self.initializer = initializer

class Exit(Statement):
    # exit value;
    def __init__(self, value: Expression):
        self.value = value

class Parser:
    
    def __init__(self, tokens: list[Token]):
        self.tokens = tokens
        self.index = 0

    def current(self):
        return self.tokens[self.index]

    def advance(self):
        t = self.current()
        self.index += 1
        return t

    def expect(self, kind: TokenType):
        if self.current().type != kind:
            raise ValueError(f"{self.current().type} is not of type {kind}")
        return self.advance()
