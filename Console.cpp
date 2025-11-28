#include "Console.h"

Console::Console(Game* g) : game(g) {}

void Console::play(int a){
	for (int i = 0; i <= a; i++) {
		game->checkGrid();
	}
}

void Console::load(std::string n){}

void Console::save() {

}

void Console::menu() {
	std::cout << "           ###################" << std::endl;
	std::cout << "           #  Jeu de la vie  #" << std::endl;
	std::cout << "           ###################" << std::endl << std::endl;
	std::cout << "par Logan et Raphaël" << std::endl << std::endl;

}