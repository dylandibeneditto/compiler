from token import Tokenizer

if __name__ == "__main__":
    with open("source.dt") as f:
        source = f.read()
        t = Tokenizer(source)
        tokens = t.tokenize()
        print(tokens)


