#pragma once

#include "board.h"
using namespace std;

// Validation Function for rook
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int Rook_validate(Board &v,int a,int b,int x,int y);
