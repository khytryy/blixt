#pragma once

#include <iostream>
#include <fstream>

#include <format>
#include <cerrno>
#include <cstring>

#define BLIXT_MAJOR 1
#define BLIXT_MINOR 0
#define BLIXT_PATCH 0

#define BLIXT_IDENT "pre-alpha"

namespace blixt {
    extern std::string      currentFileContent;
    extern std::string      input_text;
    extern std::string      err;
    extern std::string      inf;
    
    extern std::ifstream    currentFile;

    enum Mode {
        MODE_COMMAND
    };

    char stringPeek(std::string str, size_t offset);
    void openFile(std::string path);
};