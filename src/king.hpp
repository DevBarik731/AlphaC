
#pragma once

#include "board.hpp"
using namespace std;

// Validation Function for King
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
const int hor[4]={0,0,1,-1};
const int ver[4]={1,-1,0,0};
const int dig_x[4]={1,1,-1,-1};
const int dig_y[4]={1,-1,1,-1};
const int knight_x[8]={1,1,-1,-1,2,2,-2,-2};
const int knight_y[8]={-2,2,-2,2,1,-1,1,-1};

int King_validate(Board &v,int a,int b,int x,int y);

// function to check if king in its current position is checked or not
int King_check(Board &v,int x,int y);

bool castle_validate(Board &b,bool white,bool kingSide);