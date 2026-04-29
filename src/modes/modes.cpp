#include <modes/modes.hpp>

ftxui::Element blixt::printMode(blixt::Mode currentMode) {
    switch (currentMode) {
        case blixt::MODE_COMMAND:
            return ftxui::text(std::format("COMMAND > {}", blixt::input_text));
            break;
    }

    return ftxui::text(std::format("NONE > {}", blixt::input_text));
}