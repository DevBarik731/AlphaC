#pragma once
#include "../board.hpp"

class pawn_structure{
    public:
    int score;
    int evaluatePawnStructure(const Board &board);
};