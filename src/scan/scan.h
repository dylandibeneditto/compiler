#pragma once
#include <string>

class Scan {
public:
    void runFile(const std::string& file);

    void runPrompt();

    void run(const std::string& source);
};
