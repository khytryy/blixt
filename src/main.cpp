#include <common/common.hpp>
#include <format>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>

int main() {
    ftxui::Component renderer = ftxui::Renderer([] {
        return ftxui::vbox({
                       ftxui::vbox({
                               ftxui::text("Blixt") | ftxui::hcenter,
                               ftxui::separatorEmpty(),
                               ftxui::text(std::format("Version {}.{}.{}-{}",
                                                       BLIXT_MAJOR,
                                                       BLIXT_MINOR,
                                                       BLIXT_PATCH,
                                                       BLIXT_IDENT)) |
                                       ftxui::hcenter,
                               ftxui::text("by Yehor Khytryy") | ftxui::hcenter,
                               ftxui::separator(),
                               ftxui::text("Type    !q to exit"),
                               ftxui::text("Type    !o <file> to open a file")
                       }) | ftxui::border |
                               ftxui::size(ftxui::HEIGHT,
                                           ftxui::GREATER_THAN,
                                           10),
                       ftxui::separatorEmpty(),
               }) |
               ftxui::borderEmpty | ftxui::center;
    });
    ftxui::App       app      = ftxui::ScreenInteractive::Fullscreen();

    app.Loop(renderer);

    return 0;
}