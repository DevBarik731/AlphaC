#include "board.h"
#include "rook.h"
using namespace std;

// Validation Function for rook
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int Rook_validate(Board &v,int a,int b,int x,int y){

    if(a!=x && b!=y) return 0;
    if(v.board[x][y]*v.board[x][y]>0) return 0; // checking of same pairity

    // rook only moves in empty straight lane, here we are checking if the lane is empty or not
    for(size_t i=a+1;i<x;i++) if(v.board[i][b]) return 0;
    for(size_t i=b+1;i<y;i++) if(v.board[a][i]) return 0;
    if(v.board[x][y]) return 2;
    else return 1;

}
