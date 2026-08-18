
#pragma once

#include "board.hpp"
using namespace std;

int Pawn_validate(Board &b,int initial_row,int initial_column,int final_row,int final_column);
void promote_pawn(Board &v,int x,int y);
