from token import Tokenizer, TokenType
from parse import Parser

if __name__ == "__main__":
    with open("source.dt") as f:
        source = f.read()
        t = Tokenizer(source)
        tokens = t.tokenize()
        print("TOKENS = [")
        for t in tokens:
            print(f"\t{t}")
            if t.type == TokenType.SEMICOLON:
                print()
        print("]")


