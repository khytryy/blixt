#include <common/common.hpp>
#include <format>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <iostream>
#include <modes/modes.hpp>

int main() {
    blixt::Mode      mode     = blixt::MODE_COMMAND;
    ftxui::Component renderer = ftxui::Renderer([&mode] {
        return ftxui::vbox(
                       {ftxui::vbox(
                                {ftxui::text("Blixt") | ftxui::hcenter,
                                 ftxui::separatorEmpty(),
                                 ftxui::text(std::format("Version {}.{}.{}-{}",
                                                         BLIXT_MAJOR,
                                                         BLIXT_MINOR,
                                                         BLIXT_PATCH,
                                                         BLIXT_IDENT)) |
                                         ftxui::hcenter |
                                         ftxui::bgcolor(ftxui::Color::White),
                                 ftxui::text("by Yehor Khytryy") |
                                         ftxui::hcenter,
                                 ftxui::separator(),
                                 ftxui::text("Type    q to quit"),
                                 ftxui::text("Type    o <file> to open a file"),
                                 ftxui::text(
                                         "Type    help to bring up help menu"),
                                 ftxui::separatorEmpty(),
                                 ftxui::text("Press   ! to switch to COMMAND "
                                             "mode")}) |
                                ftxui::borderRounded |
                                ftxui::size(ftxui::HEIGHT,
                                            ftxui::GREATER_THAN,
                                            10) |
                                ftxui::center,
                        ftxui::separatorEmpty(),
                        ftxui::filler(),

                        ftxui::hbox({
                                blixt::printMode(mode),
                                ftxui::filler(),

                        })}) |
               ftxui::borderEmpty | ftxui::flex;
    });

    ftxui::ComponentDecorator keyhandler =
            ftxui::CatchEvent([&](ftxui::Event e) {
                if (e.is_character()) {
                    blixt::input_text += e.character();
                    return true;
                }
                if (e == ftxui::Event::Backspace) {
                    if (!blixt::input_text.empty())
                        blixt::input_text.pop_back();
                    return true;
                }
                if (e == ftxui::Event::Return) {
                    blixt::input_text.clear();
                    return true;
                }
                if (e == ftxui::Event::Delete) {
                    blixt::input_text.clear();
                    return true;  
                }
                return false;
            });
    ftxui::App app = ftxui::ScreenInteractive::Fullscreen();
    auto component = renderer | keyhandler;

    app.Loop(component);

    return 0;
}