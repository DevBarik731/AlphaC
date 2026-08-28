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
int kingFeature::king_attack_defence(Board &v,int x,int y,int flag){
    int result=0;
    if(flag>0){
        for(int it=0;it<4;it++){
            int a=x+ver[it];
            int b=y+hor[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=ver[it];
                b+=hor[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-5 || v.board[a][b]==-2) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==5 || v.board[a][b]==2) result-=victim_value[abs(v.board[a][b])];
            }
        }
        for(int it=0;it<4;it++){
            int a=x+dig_x[it];
            int b=y+dig_y[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=dig_x[it];
                b+=dig_y[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-5 || v.board[a][b]==-4) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==-1 && (abs(x-a)+abs(y-b))==2 && x>a) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==5 || v.board[a][b]==4) result-=victim_value[abs(v.board[a][b])]; 
                if(v.board[a][b]==1 && (abs(x-a)+abs(y-b))==2 && x<a) result-=victim_value[abs(v.board[a][b])];
            }
            }
        

        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==-3) result+=victim_value[abs(v.board[a][b])];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==3) result-=victim_value[abs(v.board[a][b])];
        }
    }
    

    else{
        for(int it=0;it<4;it++){
            int a=x+ver[it];
            int b=y+hor[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=ver[it];
                b+=hor[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-5 || v.board[a][b]==-2) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==5 || v.board[a][b]==2) result-=victim_value[abs(v.board[a][b])];
            }
        }
        for(int it=0;it<4;it++){
            int a=x+dig_x[it];
            int b=y+dig_y[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=dig_x[it];
                b+=dig_y[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-5 || v.board[a][b]==-4) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==-1 && (abs(x-a)+abs(y-b))==2 && x>a) result+=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==5 || v.board[a][b]==4) result-=victim_value[abs(v.board[a][b])];
                if(v.board[a][b]==1 && (abs(x-a)+abs(y-b))==2 && x<a) result-=victim_value[abs(v.board[a][b])];
            }
        }
        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==-3) result+=victim_value[abs(v.board[a][b])];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==3) result-=victim_value[abs(v.board[a][b])];
        }

    }

    return result;
}
int kingFeature::king_safety(Board &v){
    int white_safety=0,black_safety=0;
    for(int it=0;it<4;it++){
        int x=black_x+hor[it];
        int y=black_y+ver[it];
        if(x>=0 && x<8 && y>=0 && y<8){
            if(v.board[x][y]<=0){
                int tp=king_attack_defence(v,x,y,-1);
                black_safety+=tp;
            }
        }
        x=black_x+dig_x[it];
        y=black_y+dig_y[it];
        if(x>=0 && x<8 && y>=0 && y<8){
            if(v.board[x][y]<=0){
                int tp=king_attack_defence(v,x,y,-1);
                black_safety+=tp;
            }
        }
    }
    for(int it=0;it<4;it++){
        int x=white_x+hor[it];
        int y=white_y+ver[it];
        if(x>=0 && x<8 && y>=0 && y<8){
            if(v.board[x][y]>=0){
                int tp=king_attack_defence(v,x,y,1);
                white_safety+=tp;
            }
        }
        x=white_x+dig_x[it];
        y=white_y+dig_y[it];
        if(x>=0 && x<8 && y>=0 && y<8){
            if(v.board[x][y]>=0){
                int tp=king_attack_defence(v,x,y,1);
                white_safety+=tp;
            }
        }
    }

    return white_safety-black_safety;

}

int kingFeature::position_value(Board &v){
    int index_white = 56-white_x * 8 +white_y;
    int index_black=black_x * 8 +black_y;
    int black_phase=0;
    int white_phase=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(v.board[i][j]==2) white_phase+=2;
            if(v.board[i][j]==3) white_phase+=1;
            if(v.board[i][j]==4) white_phase+=1;
            if(v.board[i][j]==5) white_phase+=4;
            if(v.board[i][j]==-2) black_phase+=2;
            if(v.board[i][j]==-3) black_phase+=1;
            if(v.board[i][j]==-4) black_phase+=1;
            if(v.board[i][j]==-5) black_phase+=4;
        }
    }
    int black_val=0,white_val=0;
    if(white_phase>=10) white_val+=king_opening[index_white];
    else if(white_phase>4) white_val+=king_middlegame[index_white];
    else white_val+=king_endgame[index_white];

    if(black_phase>=10) black_val+=king_opening[index_black];
    else if(black_phase>4) black_val+=king_middlegame[index_black];
    else black_val+=king_endgame[index_black];

    return white_val-black_val;
}


