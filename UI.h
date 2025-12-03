#pragma once
#include "Console.h"

class Grid;

class UI: public Game{
public :
    UI();
    void gameRun() override;
    void Windows(Grid* grid);
};

