#include <parser/parser.hpp>

void blixt::parseCommand(std::function<void()> quit) {
    blixt::err.clear();
    std::vector<std::string> args;

    if (blixt::input_text.empty()) {
        return;
    }

    size_t      offset = 0;
    std::string buffer;

    char current = blixt::stringPeek(blixt::input_text, offset);
    while (offset < blixt::input_text.size()) {
        if (std::isspace(current)) {
            if (!buffer.empty()) args.push_back(buffer);
            buffer.clear();
        } else {
            buffer += current;
        }
        offset++;
        current = blixt::stringPeek(blixt::input_text, offset);
    }

    if (!buffer.empty()) args.push_back(buffer);

    if (args.size() >= 1 && args[0] == "q") {
        quit();
    } else if (args.size() >= 1 && args[0] == "o") {
        if (args.size() < 2) {
            blixt::err = "Too little args for open (o)";
            return;
        }

        blixt::openFile(args[1]);

    } else if (args.size() == 0) {
        return;
    } else {
        blixt::err = std::format("No such command as {}", args[0]);
    }
}