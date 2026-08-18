#pragma once

#include "board.hpp"
using namespace std;

// Validation Function for King
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int King_validate(Board &v,int a,int b,int x,int y);
int King_check(Board &v,int x,int y);