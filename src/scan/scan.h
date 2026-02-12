#pragma once
#include <string>

class Scan {
public:
  bool hadError;
  Scan();
  void runFile(const std::string &file);
  void runPrompt();
  void run(const std::string &source);
  static void error(int line, const std::string &message);
  static void report(int line, const std::string &where,
                     const std::string &message);
};
