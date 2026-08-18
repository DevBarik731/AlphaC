#include "validate.hpp"

using namespace std;
bool check(int x){
    if(x<0 || x>=8) return false;
    return true;
}
int validate(Board &v,int x_curr, int y_curr, int x_new, int y_new){
    if(!check(x_curr) || !check(y_curr) || !check(x_new) || !check(y_new)) return 0;
    int flag=abs(v.board[x_curr][y_curr]);
    if(flag==1){
        return Pawn_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else if(flag==2){
        return Rook_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else if(flag==3){
        return Knight_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else if(flag==4){
        return Bishop_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else if(flag==5){
        return Queen_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else if(flag==6){
        return King_validate(v, x_curr,y_curr, x_new,y_new);
    }
    else return 0;

}