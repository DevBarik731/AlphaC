#pragma once
#include "../validate.hpp"
using namespace std;
#include "../board.hpp"
#include "Attack_Defence.hpp"

class kingFeature{
    public:
    int white_x,white_y,black_x,black_y;
    kingFeature(Board &v){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(v.board[i][j]==6){
                    white_x=i;
                    white_y=j;
                }
                if(v.board[i][j]==-6){
                    black_x=i;
                    black_y=j;
                }
            }
        }
    }
    int check_value(Board &v);
    int checkMate_value(Board &v);
    int king_attack_defence(Board &v,int a,int b,int flag);
    int king_safety(Board &v);
    int position_value(Board &v);
};

// 1. King Opening (Encourages quick castling to g1 or c1)
const int king_opening[64] = {
    -30, -40, -40, -50, -50, -40, -40, -30,

    -30, -40, -40, -50, -50, -40, -40, -30,

    -30, -40, -40, -50, -50, -40, -40, -30,

    -30, -40, -40, -50, -50, -40, -40, -30,

    -20, -30, -30, -40, -40, -30, -30, -20,

    -10, -20, -20, -20, -20, -20, -20, -10,

     20,  20,   0,   0,   0,   0,  20,  20,

     20,  30,  10,   0,   0,  10,  30,  20  // e1 (index 60) is 0, g1 (62) is 30
};

// 2. King Middlegame (Strict bunker safety, heavily penalizes the center)
const int king_middlegame[64] = {
    -50, -50, -50, -50, -50, -50, -50, -50,

    -50, -50, -50, -50, -50, -50, -50, -50,

    -50, -50, -50, -50, -50, -50, -50, -50,

    -50, -50, -50, -50, -50, -50, -50, -50,

    -50, -50, -50, -50, -50, -50, -50, -50,

    -20, -20, -20, -20, -20, -20, -20, -20,

    0,   0, -10, -10, -10, -10,   0,   0,
      
    10,  30,  10, -10, -10,  10,  30,  10  // Hiding on b1, g1, h1 gives the best scores
};

// 3. King Endgame (Maximum centralization, King becomes an attacking piece)
const int king_endgame[64] = {
    -50, -40, -30, -20, -20, -30, -40, -50,

    -30, -20, -10,   0,   0, -10, -20, -30,

    -30, -10,  20,  30,  30,  20, -10, -30,

    -30, -10,  30,  40,  40,  30, -10, -30,

    -30, -10,  30,  40,  40,  30, -10, -30,

    -30, -10,  20,  30,  30,  20, -10, -30,

    -30, -30,   0,   0,   0,   0, -30, -30,

    -50, -30, -30, -30, -30, -30, -30, -50 
};
