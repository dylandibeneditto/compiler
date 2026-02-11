#include <fstream>
#include <string>
#include <iostream>

class Scan {
public:
    void runFile(const std::string& file) {
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

        Scan::run(source);
    }

    void runPrompt() {
        while(true) {
            std::string line;
            std::cout << "> ";
            std::cin >> line;

            Scan::run(line);
        }
    }

    void run(const std::string source) {

    }
};
