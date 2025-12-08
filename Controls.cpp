#include "Controls.h"
#include "UI.h"
#include "GridSaveLoad.h"
#include "Grid.h"
#include "GridGenerate.h"
#include "View.h"

Controls::Controls() {}

void Controls::checkControls(UIRun& UiR, Grid& grid) {
    GridGenerate gridGenerate;
    if (event->is<sf::Event::Closed>()) {
        UiR.ui->window.close();
    }
    if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
        UiR.ui->handleCellClick(UiR.grid, UiR.ui->window, *mouse, &UiR);
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
            Gload.save(UiR.grid);
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::R) {
            UiR.game->randomizeGrid(UiR.grid);
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::L) {
            Gload.load(UiR.grid);
        }
    }
    if (auto key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->code == sf::Keyboard::Key::N) {
            Gload.saveVoid(UiR.grid);
        }
    }

    if (auto wheel = event->getIf<sf::Event::MouseWheelScrolled>()) { //zoom
        if (wheel->delta > 0) {// Zoom avant
            UiR.ui->Zoom->zoomIn(UiR.ui->window);
        }
        else {// Zoom arrière
            UiR.ui->Zoom->zoomOut(UiR.ui->window);
        }
        GridGenerate::updateGridLinesThickness(UiR.ui->gridLines, grid, UiR.ui->Zoom->getZoomLevel());
    }
    return;
}
