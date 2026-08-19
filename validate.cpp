#include "validate.hpp"

using namespace std;
bool check(int x){
    if(x<0 || x>=8) return false;
    return true;
}

// here we are inputing current position of king as well to check the "check" on king
int validate(Board &v,int x_curr, int y_curr, int x_new, int y_new,int x_king,int y_king){
    if(!check(x_curr) || !check(y_curr) || !check(x_new) || !check(y_new)) return 0;
    int flag=abs(v.board[x_curr][y_curr]);

    // after each validation of pieces , if move is vaid piece is moved and then the current check on
    // king is examined. and the piece movement is reversed.

    if(flag==1){
        int temp=Pawn_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;
        int checked=King_check(v,x_king,y_king);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else if(flag==2){
        int temp= Rook_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;
        int checked=King_check(v,x_king,y_king);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else if(flag==3){
        int temp= Knight_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;
        int checked=King_check(v,x_king,y_king);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else if(flag==4){
        int temp= Bishop_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;
        int checked=King_check(v,x_king,y_king);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else if(flag==5){
        int temp= Queen_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;
        int checked=King_check(v,x_king,y_king);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else if(flag==6){
        int temp= King_validate(v, x_curr,y_curr, x_new,y_new);
        if(!temp) return 0;
        int tp=v.board[x_new][y_new];
        v.board[x_new][y_new]=v.board[x_curr][y_curr];
        v.board[x_curr][y_curr]=0;

        // in case of king movement we use x_new and y_new positions to check if king is "checked".
        int checked=King_check(v,x_new,y_new);
        v.board[x_curr][y_curr]=v.board[x_new][y_new];
        v.board[x_new][y_new]=tp;
        if(checked) return 0;
        return temp;
    }
    else return 0;

}