#include "Console.h"
#include <algorithm>

Console::Console() : Game(nullptr){}

int Console::menu() {
    std::cout << "1: créer un nouveau fichier" << std::endl;
    std::cout << "2: Lancer le jeu" << std::endl;
    std::cout << "3: Sauvegarder" << std::endl;
    std::cout << "4: Charger" << std::endl;
    std::cout << "5: Générer aléatoirement la grille" << std::endl;
    std::cout << "6: Quitter" << std::endl;
    int a;
    std::cin >> a;
    return a;
}

void Console::gameRun() {
    std::cout << "           ###################" << std::endl;
    std::cout << "           #  Jeu de la vie  #" << std::endl;
    std::cout << "           ###################" << std::endl << std::endl;
    std::cout << "par Logan et Raphaël" << std::endl << std::endl;
    while (1) {
        switch (menu()) {
        case 1:
            this->saveVoid();
            break;
        case 2:
            int nbtour;
            std::cout << "Indiquez le nombre de tour que vous désirez effectuer:" << std::endl;
            std::cin >> nbtour;
            play(nbtour);
            break;
        case 3:
            save();
            break;
        case 4:
            load();
            break;
        case 5:
            this->randomizeGrid();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
}