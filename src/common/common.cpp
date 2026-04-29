#include <common/common.hpp>

namespace blixt {
    std::string currentFileContent;
    std::string input_text;
    std::string err;
    std::string inf;

    std::ifstream    currentFile;
}

char blixt::stringPeek(std::string str, size_t offset) {
    if (offset > str.size()) {
        return '\0';
    }
    return str[offset];
}

void blixt::openFile(std::string path) {
    blixt::currentFile = std::ifstream(path);

    std::string t;
    if (!std::getline(blixt::currentFile, t)) {
        blixt::err = std::format("Error opening {} ({})", path, strerror(errno));
    }

    while (std::getline(blixt::currentFile, t)) {
        blixt::currentFileContent.append(t);
    }
}