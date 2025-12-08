#include "UIRun.h"
#include "Buttons.h"
#include "GridSaveLoad.h"
#include "Controls.h"
using namespace std;

void UIRun::gameRun(Grid* _grid) {
    ui = new UI;
    grid = _grid;
    GridSaveLoad Gload;
    Game game;
    Controls controls;
    std::filesystem::path p("Font/LEMONMILK-Regular.otf");
    if (std::filesystem::exists(p)) {
        std::cout << "OK" << std::endl;

    }
    sf::Font font;

    if (!font.openFromFile(p)) {
        std::cout << "Erreur lors du chargement de la police." << std::endl;
        return;
    }

    Button* btn_start_pause = new Button(10, 10, 200, 75, font, "Pause/Start");
    ui->buttons.push_back(btn_start_pause);
    Button* btn_random = new Button(230, 10, 200, 75, font, "Random");
    ui->buttons.push_back(btn_random);

    ui->initializeWindow(grid);
    ui->window.setView(ui->Zoom->view); //test
    Run = false;
    //randomizeGrid();
    while (ui->window.isOpen()) {
        while ((controls.event = ui->window.pollEvent()).has_value()) {
            controls.checkControls(*this, *grid);
        }
        if (Run) {
            game.checkGrid(grid);
        }
        ui->CheckGridColor(grid);
        ui->displayWindow(grid);
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