#pragma once

#include <ftxui/dom/elements.hpp>
#include <format>

namespace blixt {
    enum Mode {
        MODE_COMMAND
    };

    std::string input_text;

    ftxui::Element printMode(blixt::Mode currentMode) {
        switch (currentMode) {
            case blixt::MODE_COMMAND:
                return ftxui::text(std::format("COMMAND > {}", blixt::input_text));
        }

        return ftxui::text("NONE >");
    }
};