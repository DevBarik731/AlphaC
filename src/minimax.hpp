#pragma once
#include "validate.hpp"
using namespace std;
void rook_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
void bishop_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
void queen_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
void knight_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
void king_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
void pawn_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds);
vector<vector<int>> generateMoves(Board &v,int x_king,int y_king);
int minimax(Board &v,int depth,int player);
vector<int> best_move(Board &v,int x_king,int y_king);