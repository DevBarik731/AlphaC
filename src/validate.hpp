#pragma once
#include "board.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "queen.hpp"

using namespace std;

enum Piece {
    EMPTY = 0,

    BLACK_PAWN = -1,
    BLACK_ROOK = -2,
    BLACK_KNIGHT = -3,
    BLACK_BISHOP = -4,
    BLACK_QUEEN = -5,
    BLACK_KING = -6,

    WHITE_PAWN = 1,
    WHITE_ROOK = 2,
    WHITE_KNIGHT = 3,
    WHITE_BISHOP = 4,
    WHITE_QUEEN = 5,
    WHITE_KING = 6
};

int validate(Board &v,int x_curr, int y_curr, int x_new, int y_new,int x_king,int y_king);

int game_end(Board& v,int x_king,int y_king);