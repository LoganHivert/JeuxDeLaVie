#include "Console.h"
#include <algorithm>
#include "GridSaveLoad.h"
#include "Grid.h"

Console::Console() : grid(), game(&grid){}

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