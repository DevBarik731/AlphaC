#include<iostream>
#include "src/evaluation/evaluation.hpp"
#include "src/evaluation/pawn_structure.hpp"
#include "src/evaluation/Attack_Defence.hpp"
#include "src/evaluation/king_safety.hpp"
#include "src/evaluation/rook_score.hpp"
using namespace std;

int main(){
    PieceSquareTable p;
    pawn_structure pwn;
    Board b=Board();
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>b.board[i][j];
            }
        }
        kingFeature kf=kingFeature(b);
        double material=p.evaluateBoard(b.board);
        double mobility=p.evaluateMobility(b);
        pair<int,int> tp=pressure(b);
        double pawn_structure=pwn.evaluatePawnStructure(b);
        double pressure=tp.first;
        double threat=tp.second;
        double check=kf.check_value(b);
        double kingSafety=kf.king_safety(b);
        double kingPosition=kf.position_value(b);
        double RookScore=rook_score(b);
        cout<<material<<" "<<mobility<<" "<<pawn_structure<<" "<<pressure<<" "<<threat<<" "<<RookScore<<" "<<check<<" "<<kingSafety<<" "<<kingPosition<<endl;
    }
}