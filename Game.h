#pragma once
#include "Board.h"

class Game {
public:
    void start();

private:
    Board board;
    void play(int r, int c, int mines);
};