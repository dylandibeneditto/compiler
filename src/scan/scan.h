#pragma once
#include <string>

class Scan {
public:
    void runFile(const std::string& file);
    void runPrompt();
    void run(const std::string& source);
    void error(int line, const std::string& message);
    void report(int line, const std::string& where, const std::string& message);
};
