
#include "board.hpp"
#include "king.hpp"
using namespace std;

// Validation Function for King
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int King_validate(Board &v,int a,int b,int x,int y){

    if(v.board[a][b]*v.board[x][y]>0) return 0; // checking if same colour 

    // dx and dy storing all possible movements of king
    vector<int> dx={1,-1,0,0,1,1,-1,-1};
    vector<int> dy={0,0,1,-1,1,-1,1,-1};
    for(size_t i=0;i<8;i++){
        int an=a+dx[i];
        int bn=b+dy[i];
        if(a+dx[i]==x && b+dy[i]==y){
            if(v.board[x][y]) return 2;
            else return 1;
        }
    }

    return 0;
}

// function to check if king in its current position is checked or not
int King_check(Board &v,int x,int y){

    vector<int> hor={0,0,1,-1};
    vector<int> ver={1,-1,0,0};
    vector<int> dig_x={1,1,-1,-1};
    vector<int> dig_y={1,-1,1,-1};
    vector<int> knight_x={1,1,-1,-1,2,2,-2,-2};
    vector<int> knight_y={-2,2,-2,2,1,-1,1,-1};

    if(v.board[x][y]>0){
        for(int it=0;it<4;it++){
            int a=x+ver[it];
            int b=y+hor[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=ver[it];
                b+=hor[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==1) return 1;
                if(v.board[a][b]==-5 || v.board[a][b]==-2) return 1;
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
                if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==2) return 1;
                if(v.board[a][b]==-5 || v.board[a][b]==-4) return 1;
                if(v.board[a][b]==-1 && (abs(x-a)+abs(y-b))==2 && x>a) return 1;
            }
        }

        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==-3) return 1;
        }


        return 0;
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
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==1) return 1;
                if(v.board[a][b]==5 || v.board[a][b]==2) return 1;
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
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==2) return 1;
                if(v.board[a][b]==5 || v.board[a][b]==4) return 1;
                if(v.board[a][b]==1 && (abs(x-a)+abs(y-b))==2 && x<a) return 1;
            }
        }
        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==3) return 1;
        }

        return 0;
    }

}

bool castle_validate(Board &b,bool white,bool kingSide)
{
    int row=white?0:7;
    if(white&&b.whiteKingMoved)
    {
        return false;
    }
}