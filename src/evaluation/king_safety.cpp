#include "king_safety.hpp"
using namespace std;
int kingFeature::check_value(Board &v){
    
    int black_val=0,white_val=0;

    if(King_check(v,black_x,black_y)) white_val+=1;

    if(King_check(v,white_x,white_y)) black_val+=1;

    return white_val-black_val;

}
int kingFeature::checkMate_value(Board &v){
    int black_val=0,white_val=0;

    if(game_end(v,black_x,black_y)==1) white_val+=1;

    if(game_end(v,white_x,white_y)==1) black_val+=1;

    return white_val-black_val;
}


