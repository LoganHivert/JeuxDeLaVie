#include "ConsoleRun.h"
#include "StartGame.h"


void ConsoleRun::gameRun() {
    grid = new Grid();
    Game game(this->grid);
    Console cons;
    GridSaveLoad Gload(this->grid);
    std::cout << "           ###################" << std::endl;
    std::cout << "           #  Jeu de la vie  #" << std::endl;
    std::cout << "           ###################" << std::endl << std::endl;
    std::cout << "par Logan et Raphaël" << std::endl << std::endl;
    while (1) {
        switch (cons.menu()) {
        case 1:
            Gload.saveVoid();
            break;
        case 2:
            int nbtour;
            std::cout << "Indiquez le nombre de tour que vous désirez effectuer:" << std::endl;
            std::cin >> nbtour;
            game.play(nbtour);
            break;
        case 3:
            Gload.save();
            break;
        case 4:
            Gload.load();
            break;
        case 5:
            game.randomizeGrid();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
}