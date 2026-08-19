#pragma once
#include "valid/board.hpp"
#include "valid/knight.hpp"
#include "valid/king.hpp"
#include "valid/rook.hpp"
#include "valid/pawn.hpp"
#include "valid/bishop.hpp"
#include "valid/queen.hpp"

using namespace std;

int validate(Board &v,int x_curr, int y_curr, int x_new, int y_new,int x_king,int y_king);

int game_end(Board& v,int x_king,int y_king);