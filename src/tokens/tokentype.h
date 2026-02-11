enum TokenType {
    // single char
    // parens
    LEFT_PAREN, RIGHT_PAREN, 
    LEFT_BRACE, RIGHT_BRACE,
    LEFT_SQUARE, RIGHT_SQUARE,

    // arithm
    PLUS, MINUS, STAR, SLASH, MOD,
    // other
    DOT, COMMA, SEMICOLON,

    // two char
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // literals
    IDENTIFIER, STRING, NUMBER,
    
    // keywords
    AND, OR, 
    IF, ELSE, 
    FALSE, TRUE,
    CLASS, SUPER, THIS,
    LET,
    NIL,
    FN, RETURN,
    FOR, WHILE,
    PRINT,

    END_OF_FILE
};
