#include "Controls.h"
#include "UI.h"

Controls::Controls() {}
void Controls::checkControls(UIRun& UiR) {
    if (event->is<sf::Event::Closed>()) {
        ui.window.close();
    }
    if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
        ui.handleCellClick(UiR.grid, ui.window, *mouse);
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::Space) {
            UiR.Run = !UiR.Run;
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::Escape) {
            exit(0);
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::S) {
            Gload->save();
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::R) {
            UiR.game->randomizeGrid();
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::L) {
            Gload->load();
        }
    }

    if (auto wheel = event->getIf<sf::Event::MouseWheelScrolled>()) { //zoom
        if (wheel->delta > 0) {// Zoom avant
            Zoom.zoomIn(ui.window);
        }
        else {// Zoom arrière
            Zoom.zoomOut(ui.window);
        }
    }
    return;
}
