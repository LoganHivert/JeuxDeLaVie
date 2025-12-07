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
        Gtype = true;
        gameCons = new ConsoleRun();
        return;
    case 2:
        Gtype = false;
        gameUi = new UIRun();
        return;
    }
}

void StartGame::launchGame() {
    chooseGame();
    grid = new Grid();
    Game game(this->grid);
	GridSaveLoad Gload(grid);
    if (Gtype) {
        gameCons->gameRun();
    }
    else {
        gameUi->gameRun();
    }
    delete grid;
    grid = nullptr;
}