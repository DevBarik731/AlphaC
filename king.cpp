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