#pragma once
#include "board.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "queen.hpp"

using namespace std;

int validate(Board &v,int x_curr, int y_curr, int x_new, int y_new,int x_king,int y_king);

int game_end(Board& v,int x_king,int y_king);