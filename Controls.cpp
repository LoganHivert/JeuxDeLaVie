#include "Controls.h"
#include "UI.h"

Controls::Controls() {}
void Controls::checkControls(UIRun& UiR) {
    if (event->is<sf::Event::Closed>()) {
        UiR.ui.window.close();
    }
    if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
        UiR.ui.handleCellClick(UiR.grid, UiR.ui.window, *mouse);
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
            UiR.ui.Zoom.zoomIn(UiR.ui.window);
        }
        else {// Zoom arrière
            UiR.ui.Zoom.zoomOut(UiR.ui.window);
        }
    }
    return;
}
