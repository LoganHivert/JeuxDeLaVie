#include "Console.h"
#include "Game.h"
#include <algorithm>

Console::Console(Game* g) : game(g) {}

void Console::play(int a){
	if (!game || !game->grid) {
		std::cerr << "Pas de grille disponible pour jouer !" << std::endl;
		return;
	}
	for (int i = 0; i < a; ++i) {
		game->checkGrid();
	}
}

void Console::load(){
    std::string file;
    std::cout << "Indiquez le chemin du fichier dans lequel vous voulez enregistrer votre pattern." << std::endl;
    std::cin >> file;
    if (file == "1") {
        file = "Pattern/Pattern1.txt";
    }
    std::ifstream load(file, std::ios::in);
    if (!load) {
        std::cerr << "Impossible d'ouvrir le fichier de pattern !" << std::endl;
        return;
    }
    if (!game || !game->grid) {
        std::cerr << "Pas de grille à charger !" << std::endl;
        return;
    }

    int fileRows = 0;
    int fileCols = 0;
    if (!(load >> fileRows)) {
        std::cerr << "Fichier de pattern invalide (rows) !" << std::endl;
        return;
    }
    if (!(load >> fileCols)) {
        std::cerr << "Fichier de pattern invalide (cols) !" << std::endl;
        return;
    }

    std::string line;
    std::getline(load, line); // consume end of line
    std::getline(load, line); // consume blank line

    int maxRows = std::min(fileRows, ROWS);
    int maxCols = std::min(fileCols, COLS);

    for (int i = 0; i < maxRows; ++i) {
        if (!std::getline(load, line)) break;
        for (int j = 0; j < maxCols && j < (int)line.size(); ++j) {
            char ch = line[j];
            game->grid->cells[i][j].alive = (ch == '1') ? 1 : 0;
        }
    }
}

void Console::save() {
    std::string file;
    std::cout << "Indiquez le chemin du fichier dans lequel vous voulez enregistrer votre pattern." << std::endl;
    std::cin >> file;
    if (file == "1") {
        file = "Pattern/Pattern1.txt";
    }
    std::ofstream save(file, std::ios::out | std::ios::trunc);
    if (!save) {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return;
    }
    if (!game || !game->grid) {
        std::cerr << "Pas de grille à sauvegarder !" << std::endl;
        return;
    }

    save << ROWS << std::endl;
    save << COLS << std::endl << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            save << game->grid->getCell(i, j);
        }
        save << std::endl;
    }
}

void Console::menu() {
	std::cout << "           ###################" << std::endl;
	std::cout << "           #  Jeu de la vie  #" << std::endl;
	std::cout << "           ###################" << std::endl << std::endl;
	std::cout << "par Logan et Raphaël" << std::endl << std::endl;
    std::cout << "1: Lancer le jeu" << std::endl;
    std::cout << "2: Sauvegarder" << std::endl;
    std::cout << "3: Charger" << std::endl;
    std::cout << "4: Quitter" << std::endl;
    int choix;
    std::cin >> choix;
    switch (choix){
    case 1:
        int nbtour;
        std::cout << "Indiquez le nombre de tour que vous désirez effectuer:" << std::endl;
        std::cin >> nbtour;
        play(nbtour);
        break;
    case 2:
        save();
        break;
    case 3:
        load();
        break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }
}