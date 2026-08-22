#include "evaluation.hpp"

int PieceSquareTable::getScore(int piece, int row, int col)
{
    int index = row * 8 + col;

    if(piece > 0)
        index = 56 - 8 * row + col;

    if(piece == WHITE_PAWN || piece == BLACK_PAWN)
        return pawn_pst[index];

    if(piece == WHITE_KNIGHT || piece == BLACK_KNIGHT)
        return knight_pst[index];

    if(piece == WHITE_BISHOP || piece == BLACK_BISHOP)
        return bishop_pst[index];

    if(piece == WHITE_ROOK || piece == BLACK_ROOK)
        return rook_pst[index];

    if(piece == WHITE_QUEEN || piece == BLACK_QUEEN)
        return queen_pst[index];

    return 0;
}

int PieceSquareTable::evaluateBoard(const vector<vector<int>>& board)
{
    int score = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(abs(board[i][j]) == 5)
                continue;

            if(board[i][j] != EMPTY)
            {
                int value = getScore(board[i][j], i, j);

                if(board[i][j] > 0)
                    score += value;
                else
                    score -= value;
            }
        }
    }

    return score;
}