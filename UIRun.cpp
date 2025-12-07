#include "UIRun.h"
#include "Bouton.h"
#include "GridSaveLoad.h"
#include "Controls.h"

void UIRun::gameRun() {
    GridSaveLoad Gload(this->grid);
    Game game(this->grid);
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
    ui.monBouton = new Button(300, 250, 200, 100, font, "Cliquez ici!");

    ui.initializeWindow();
    Run = false;
    //randomizeGrid();
    while (ui.window.isOpen()) {
        while ((controls.event = ui.window.pollEvent()).has_value()) {
            controls.checkControls(*this);
        }
        if (Run) {
            game.checkGrid();
        }
        ui.displayWindow(this->grid);
    }
}