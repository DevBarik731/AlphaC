#include<iostream>
#include "board.hpp"
#include "rook.hpp"
using namespace std;

// Validation Function for rook
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int Rook_validate(Board &v,int a,int b,int x,int y){
    if(a!=x && b!=y) return 0;
    int step_x;
    int step_y;
    if(x>=a) step_x=1;
    else step_x=-1;
    if(y>=b) step_y=1;
    else step_y=-1;

    if(v.board[x][y]*v.board[a][b]>0) return 0; // checking of same pairity

    // rook only moves in empty straight lane, here we are checking if the lane is empty or not
    for(int i=a+step_x;(step_x>0 && i<x) || (step_x<0 && i>x);i+=step_x) if(v.board[i][b]) return 0;
    for(int i=b+step_y;(step_y>0 && i<y) || (step_y<0 && i>y);i+=step_y) if(v.board[a][i]) return 0;
    if(v.board[x][y]) return 2;
    else return 1;

}

