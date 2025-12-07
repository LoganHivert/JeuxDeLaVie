#include "GridSaveLoad.h"
#include "SFML/Graphics.hpp"
#include "Grid.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>

GridSaveLoad::GridSaveLoad(Grid* g) : grid(g) {}

void GridSaveLoad::save() { //sauvegarde avec ajout _out
    std::string tempFile = this->file;
    tempFile.erase(this->file.size() - 4);
    std::ofstream save((tempFile + "_out.txt"), std::ios::out | std::ios::trunc);
    if (!save) {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return;
    }
    if (!this->grid) {
        std::cerr << "Pas de grille à sauvegarder !" << std::endl;
        return;
    }

    save << ROWS << std::endl;
    save << COLS << std::endl << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            save << this->grid->getCell(i, j);
        }
        save << std::endl;
    }
}

void GridSaveLoad::saveVoid() { //sauvegarde fichier
    std::cout << "Indiquez ou vous voulez créer votre fichier vide" << std::endl;
    std::cin >> this->file;
    std::ofstream savevoid((this->file), std::ios::out | std::ios::trunc);
    if (!savevoid) {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return;
    }
    if (!this->grid) {
        std::cerr << "Pas de grille à sauvegarder !" << std::endl;
        return;
    }

    savevoid << ROWS << std::endl;
    savevoid << COLS << std::endl << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            savevoid << this->grid->getCell(i, j);
        }
        savevoid << std::endl;
    }
}

void GridSaveLoad::load() {
    std::cout << "Indiquez le chemin du fichier depuis lequel vous voulez charger votre pattern." << std::endl;
    std::cin >> this->file;
    if (file == "1") {
        file = "Pattern/Pattern1.txt";
    }
    std::ifstream load(this->file, std::ios::in);
    if (!load) {
        std::cerr << "Impossible d'ouvrir le fichier de pattern !" << std::endl;
        return;
    }
    if (!this->grid) {
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
            this->grid->cells[i][j].alive = (ch == '1') ? 1 : 0;
        }
    }
}