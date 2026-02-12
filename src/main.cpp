#include "scan/scan.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  Scan scan;
  if (argc > 2) {
    std::cout << "Usage: ditto [filename]" << std::endl;
    exit(64);
  } else if (argc == 2) {
    std::string path(argv[1]);
    scan.runFile(path);
  } else {
    scan.runPrompt();
  }
  return 0;
}
