#include <iostream>
#include <string>
#include "scan/scan.h"

int main(int argc, char* argv[]) {
    Scan scan;
    if(argc > 1) {
        std::cout << "Usage: ditto [filename]" << std::endl;
        exit(64);
    } else if (argc == 1) {
        std::string path(argv[0]);
        scan.runFile(path);
    } else {
        // run prompt
        scan.runPrompt();
    }
    return 0;
}
