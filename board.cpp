#include<iostream>
#include "board.h"
#include<vector>
using namespace std;


    
Board::Board():board(8,vector<int>(8,0)){
        board[1]=vector<int>(8,-1);
        board[6]=vector<int>(8,1);
        for(size_t i=0;i<4;i++){
            board[7][i]=i+2;
            board[7][7-i]=i+2;
            board[0][i]=-(i+2);
            board[0][7-i]=-(i+2);
        }
        board[0][4]=-6;
        board[7][4]=6;
    }

void Board::display(){
        for(size_t i=0;i<8;i++){
            for(size_t j=0;j<8;j++){
                cout<<board[i][j]<<" ";
                if(board[i][j]>=0) cout<<" ";
            }
            cout<<"\n";
        }
    } 

