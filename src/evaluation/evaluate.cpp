#include "evaluate.hpp"
#include "features.hpp"
#include "../../Neural_Network/neural_network.h"
#include <vector>

using namespace std;

double evaluate(Board &board)
{   
    vector<double> features = getFeatures(board);
    int x_white=-1,y_white=-1,x_black=-1,y_black=-1;
    for(int i=0;i<board.board.size();i++){
        for(int j=0;j<board.board.size();j++){
            if(board.board[i][j]==-6){
                x_black=i;
                y_black=j;
            }
            if(board.board[i][j]==6){
                x_white=i;
                y_white=j;
            }
        }
    }
    int result=game_end(board,x_white,y_white);
    if(result==2) return 0;
    if(result) return -10000;
    result=game_end(board,x_black,y_black);
    if(result==2) return 0;
    if(result) return 10000;
    return neuralNetwork(features);
}