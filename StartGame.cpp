#include "StartGame.h"

StartGame::StartGame() {};

void StartGame::chooseGame() {
    std::cout << "Mode de lancement:" << std::endl;
    std::cout << "1: Console" << std::endl;
    std::cout << "2: UI" << std::endl;
    int choix;
    std::cin >> choix;
    switch (choix) {
    case 1:
        game = new Console();
        return;
    case 2:
        game = new UI();
        return;
    }
}

void StartGame::launchGame() {
    chooseGame();
    UI ui;
    game->grid = new Grid();
	GridSaveLoad Gload(game->grid);
    ui.gameRun();
    delete game->grid;
    game->grid = nullptr;
}