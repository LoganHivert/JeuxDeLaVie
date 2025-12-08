#include "UIRun.h"
#include "Buttons.h"
#include "GridSaveLoad.h"
#include "Controls.h"
using namespace std;

void UIRun::gameRun(Grid* _grid) {
    grid = _grid;
    GridSaveLoad Gload;
    Game game;
    Controls controls;
    std::filesystem::path p("Font/Roboto_Condensed-Bold.ttf");
    if (std::filesystem::exists(p)) {
        std::cout << "OK" << std::endl;

    }
    sf::Font font;

    if (!font.openFromFile(p)) {
        std::cout << "Erreur lors du chargement de la police." << std::endl;
        return;
    }
    ui.myButton = new Button(10, 10, 200, 100, font, "Cliquez ici!");

    ui.initializeWindow(grid);
    ui.window.setView(this->ui.Zoom->view); //test
    Run = false;
    //randomizeGrid();
    while (ui.window.isOpen()) {
        while ((controls.event = ui.window.pollEvent()).has_value()) {
            controls.checkControls(*this, *grid);
        }
        if (Run) {
            game.checkGrid(grid);
        }
        ui.CheckGridColor(grid);
        ui.displayWindow(grid);
        gameSpeed();
    }
}

void UIRun::gameSpeed() {

    if (!game) {
        // gérer le cas nul (valeur par défaut / log / return)
        return;
    }

    if (game->getSpeed() > 100) {
        std::this_thread::sleep_for(std::chrono::milliseconds(game->getSpeed()));
    }
    return;
}