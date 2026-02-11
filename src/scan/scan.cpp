#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "../tokens/token.h"
#include "./scan.h"

void Scan::runFile(const std::string& file) {
    // Open the file in binary mode for verbatim reading
    std::ifstream f(file, std::ios_base::binary | std::ios_base::in);
    
    if (!f.is_open()) { // check if file opened
        throw std::runtime_error("Failed to open " + file);
    }

    // Use iterators to read the entire file content into the string
    std::string source((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    if (!f && !f.eof()) { // check for read errors
         throw std::runtime_error("Failed to read " + file);
    }

    run(source);
}

void Scan::runPrompt() {
    while(true) {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);

        run(line);
    }
}

void Scan::run(const std::string& source) {
    std::cout<<source<<std::endl;
    // Tokenizer tokenizer(source);
    // std::vector<Token> tokens = tokenizer.scanTokens();
    //
    // for(Token t : tokens) {
    //     std::cout<<t<<std::endl;
    // }
}

void Scan::error(const int line, const std::string& message) {
    report(line, "", message);
}

void Scan::report(const int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " << line << "] Error " << where << ": " << message;
}
