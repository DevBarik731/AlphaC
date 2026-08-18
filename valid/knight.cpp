#include "board.hpp"
#include "knight.hpp"
using namespace std;

// Validation Function for Knight
// 0 : not possible
// 1 : possible with no kill
// 2 : possible with kill
// move from (a,b) -> (x,y)
int Knight_validate(Board &v,int a,int b,int x,int y){
    
    // here dx and dy enlist all possible movements of knight
    if(v.board[a][b]*v.board[x][y]>0) return 0; // checking if same colour
    vector<int> dx={1,1,-1,-1,2,2,-2,-2};
    vector<int> dy={-2,2,-2,2,1,-1,1,-1};
    for(size_t i=0;i<8;i++){
        if(a+dx[i]==x && b+dy[i]==y){
            if(v.board[x][y]) return 2;
            else return 1;
        }
    }
    return 0;
    
}