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
    int score=0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(abs(board[i][j]) == 6)
                continue;

            if(board[i][j] != EMPTY)
            {   
                int idx=abs(board[i][j]);
                int value = initial_value[idx-1]+getScore(board[i][j], i, j);

                if(board[i][j] > 0)
                    score += value;
                else
                    score -= value;
            }
        }
    }

    return score;
}

int PieceSquareTable::mobilityFactor(int piece)
{
    switch(abs(piece))
    {
        case 1: return 1;  // pawn
        case 2: return 2;  // rook
        case 3: return 4;  // knight
        case 4: return 4;  // bishop
        case 5: return 1;  // queen
        case 6: return 3;  // king
    }

    return 0;
}
void PieceSquareTable::findKing(
    Board& board,
    int color,
    int& x,
    int& y)
{
    int king = color > 0 ? WHITE_KING : BLACK_KING;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board.board[i][j] == king)
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}
int PieceSquareTable::getPieceMobility(
    Board& board,
    int row,
    int col,
    int x_king,
    int y_king)
{
    
    int piece = board.board[row][col];

    if(piece == EMPTY)
        return 0;

    int moves = 0;

    for(int newRow = 0; newRow < 8; newRow++)
    {
        for(int newCol = 0; newCol < 8; newCol++)
        {
            if(validate(
                board,
                row,
                col,
                newRow,
                newCol,
                x_king,
                y_king))
            {
                moves++;
            }
        }
    }
    return moves * mobilityFactor(piece);
}

int PieceSquareTable::evaluateMobility(Board& board)
{
    int score = 0;

    int whiteKingX, whiteKingY;
    int blackKingX, blackKingY;

    findKing(board, 1, whiteKingX, whiteKingY);
    findKing(board, -1, blackKingX, blackKingY);

    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            int piece = board.board[row][col];

            if(piece == EMPTY)
                continue;

            int value;

            if(piece > 0)
            {
                value = getPieceMobility(
                    board,
                    row,
                    col,
                    whiteKingX,
                    whiteKingY);

                score += value;
            }
            else
            {
                value = getPieceMobility(
                    board,
                    row,
                    col,
                    blackKingX,
                    blackKingY);

                score -= value;
            }
        }
    }

    return score;
}