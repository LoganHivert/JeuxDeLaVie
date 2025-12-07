#include "ConsoleRun.h"
#include "StartGame.h"

void ConsoleRun::gameRun(Grid* _grid) {
    grid = _grid;
    Game game;
    Console cons;
    GridSaveLoad Gload;
    std::cout << "           ###################" << std::endl;
    std::cout << "           #  Jeu de la vie  #" << std::endl;
    std::cout << "           ###################" << std::endl << std::endl;
    std::cout << "par Logan et Raphaël" << std::endl << std::endl;
    while (1) {
        switch (cons.menu()) {
        case 1:
            Gload.saveVoid(grid);
            break;
        case 2:
            int nbtour;
            std::cout << "Indiquez le nombre de tour que vous désirez effectuer:" << std::endl;
            std::cin >> nbtour;
            game.play(nbtour, grid);
            break;
        case 3:
            Gload.save(grid);
            break;
        case 4:
            Gload.load(grid);
            break;
        case 5:
            game.randomizeGrid(grid);
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
}