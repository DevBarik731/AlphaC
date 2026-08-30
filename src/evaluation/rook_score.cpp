#include "rook_score.hpp"

int rook_score(const Board &board)
{
    int score=0;
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            int piece=board.board[r][c];
            if(piece==WHITE_ROOK)
            {
                bool whitepawn=false;
                bool blackpawn=false;
                for(int row=0;row<8;row++)
                {
                    if(board.board[row][c]==WHITE_PAWN)
                    {
                        whitepawn=true;
                    }
                    if(board.board[row][c]==BLACK_PAWN)
                    {
                        blackpawn=true;
                    }
                }
                if(!whitepawn&&!blackpawn)
                {
                    score+=15;
                }
                else if(!whitepawn)
                {
                    score+=8;
                }
                if(r==1)
                {
                    score+=20;
                }
            }
            else if(piece==BLACK_ROOK)
            {
                bool whitepawn=false;
                bool blackpawn=false;
                for(int row=0;row<8;row++)
                {
                    if(board.board[row][c]==WHITE_PAWN)
                    {
                        whitepawn=true;
                    }
                    if(board.board[row][c]==BLACK_PAWN)
                    {
                        blackpawn=true;
                    }
                }
                if(!whitepawn&&!blackpawn)
                {
                    score-=15;
                }
                else if(!whitepawn)
                {
                    score-=8;
                }
                if(r==6)
                {
                    score-=20;
                }
            }
        }
    }
    return score;
}