#include "UI.h"
#include "Game.h"

int main() {
	UI ui;
	ui.Windows();
    Game game(nullptr);
    game.launchGame();
    return 0;
} 