#pragma once
#include "validate.hpp"
using namespace std;

class PieceSquareTable{
    public:
  int getScore(int,int,int);
  int evaluateBoard(const vector<vector<int>> &Board); 
      public:
// Pawns want to advance to the 8th rank and control the center.

// They are penalized for being on their starting squares blocking other pieces.

const int pawn_pst[64] = {

      0,  0,  0,  0,  0,  0,  0,  0,

     50, 50, 50, 50, 50, 50, 50, 50,

     10, 10, 20, 30, 30, 20, 10, 10,

      5,  5, 10, 25, 25, 10,  5,  5,

      0,  0,  0, 20, 20,  0,  0,  0,

      5, -5,-10,  0,  0,-10, -5,  5,

      5, 10, 10,-20,-20, 10, 10,  5,

      0,  0,  0,  0,  0,  0,  0,  0

};



// Knights are heavily penalized on the rim/corners ("knights on the rim are dim").

// They get massive bonuses in the center of the board.

const int knight_pst[64] = {

    -50,-40,-30,-30,-30,-30,-40,-50,

    -40,-20,  0,  0,  0,  0,-20,-40,

    -30,  0, 10, 15, 15, 10,  0,-30,

    -30,  5, 15, 20, 20, 15,  5,-30,

    -30,  0, 15, 20, 20, 15,  0,-30,

    -30,  5, 10, 15, 15, 10,  5,-30,

    -40,-20,  0,  5,  5,  0,-20,-40,

    -50,-40,-30,-30,-30,-30,-40,-50

};



// Bishops like long diagonals and want to avoid corners and the absolute edges.

const int bishop_pst[64] = {

    -20,-10,-10,-10,-10,-10,-10,-20,

    -10,  0,  0,  0,  0,  0,  0,-10,

    -10,  0,  5, 10, 10,  5,  0,-10,

    -10,  5,  5, 10, 10,  5,  5,-10,

    -10,  0, 10, 10, 10, 10,  0,-10,

    -10, 10, 10, 10, 10, 10, 10,-10,

    -10,  5,  0,  0,  0,  0,  5,-10,

    -20,-10,-10,-10,-10,-10,-10,-20

};



// Rooks belong on the 7th rank (bonus) and like to be centralized.

// They are slightly penalized for sitting awkwardly in the corners.

const int rook_pst[64] = {

      0,  0,  0,  0,  0,  0,  0,  0,

      5, 10, 10, 10, 10, 10, 10,  5,

     -5,  0,  0,  0,  0,  0,  0, -5,

     -5,  0,  0,  0,  0,  0,  0, -5,

     -5,  0,  0,  0,  0,  0,  0, -5,

     -5,  0,  0,  0,  0,  0,  0, -5,

     -5,  0,  0,  0,  0,  0,  0, -5,

      0,  0,  0,  5,  5,  0,  0,  0

};



// Queens should not be brought out too early; they prefer slightly back/central 

// squares where they command space without getting trapped.

const int queen_pst[64] = {

    -20,-10,-10, -5, -5,-10,-10,-20,

    -10,  0,  0,  0,  0,  0,  0,-10,

    -10,  0,  5,  5,  5,  5,  0,-10,

     -5,  0,  5,  5,  5,  5,  0, -5,

      0,  0,  5,  5,  5,  5,  0, -5,

    -10,  5,  5,  5,  5,  5,  0,-10,

    -10,  0,  5,  0,  0,  0,  0,-10,

    -20,-10,-10, -5, -5,-10,-10,-20

};



// Middle Game King: Keep him tucked away safely in the corners/flanks.

// End Game King: Needs to be a fighting piece and get to the center.

const int king_eg_pst[64] = {

    -50,-40,-30,-20,-20,-30,-40,-50,

    -30,-20,-10,  0,  0,-10,-20,-30,

    -30,-10, 20, 30, 30, 20,-10,-30,

    -30,-10, 30, 40, 40, 30,-10,-30,

    -30,-10, 30, 40, 40, 30,-10,-30,

    -30,-10, 20, 30, 30, 20,-10,-30,

    -30,-30,  0,  0,  0,  0,-30,-30,

    -50,-30,-30,-30,-30,-30,-30,-50

};
};
