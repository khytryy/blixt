#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>


int main() {
    ftxui::Component renderer = ftxui::Renderer ([] {
        return ftxui::vbox({
            ftxui::text("Blixt") | ftxui::hcenter,
        }) | ftxui::borderEmpty | ftxui::center;
    });
    ftxui::App app = ftxui::ScreenInteractive::Fullscreen();

    app.Loop(renderer);

    return 0;
}