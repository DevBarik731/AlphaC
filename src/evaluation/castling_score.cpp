#include "castling_score.hpp"
#include "../king.hpp"
int castlingScore(const Board &board)
{
    int score=0;
    Board b=board;
    if(b.whiteHasCastled)
    {
        score+=30;
    }
    if(b.blackHasCastled)
    {
        score-=30;
    }
    return score;
}