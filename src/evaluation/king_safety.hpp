#pragma once
#include "../validate.hpp"
using namespace std;
#include "../board.hpp"

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
};