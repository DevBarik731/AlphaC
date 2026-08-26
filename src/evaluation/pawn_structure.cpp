#include "pawn_structure.hpp"

int pawn_structure::evaluatePawnStructure(const Board &board)
{
    score=0;
    const vector<vector<int>> &b=board.board;
    vector<int> white(8,0);
    vector<int> black(8,0);
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            if(b[r][c]==1)
            {
                white[c]++;
            }
            else if(b[r][c]==-1)
            {
                black[c]++;
            }
        }
    }
    for(int file=0;file<8;file++)
    {
        if(white[file]>0)
        {
            score-=20*(white[file]-1);
        }
        if(black[file]>0)
        {
            score+=20*(black[file]-1);
        }
    }
    for(int c=0;c<8;c++)
    {
        if(white[c]>0)
        {
            bool isIsolatedWhite=true;   
        if(c>0&&white[c-1]>0)
        {
            isIsolatedWhite=false;
        }
        if(c<7&&white[c+1]>0)
        {
            isIsolatedWhite=false;
        }
        if(isIsolatedWhite)
        {
            score-=15;
        }
    }
    if(black[c]>0)
    {
    bool isIsolatedBlack=true;
        if(c>0&&black[c-1]>0)
        {
            isIsolatedBlack=false;
        }
        if(c<7&&black[c+1]>0)
        {
            isIsolatedBlack=false;
        }
        if(isIsolatedBlack)
        {
            score+=15;
        }
    }
}
    for(int r=0;r<8;r++)
    {
        for(int c=0;c<8;c++)
        {
            if(b[r][c]==1)
            {
            bool isAheadWhite=true;
            for(int rr=r-1;rr>=0;rr--)
            {
                if(b[rr][c]==-1)
                {
                    isAheadWhite=false;
                }
                if(c>0&&b[rr][c-1]==-1)
                {
                    isAheadWhite=false;
                }
                if(c<7&&b[rr][c+1]==-1)
                {
                    isAheadWhite=false;
                }
            }
            if(isAheadWhite)
            {
                score+=20+(6-r)*10;
            }
        }
            if(b[r][c]==-1)
            {
            bool isAheadBlack=true;
            for(int rr=r+1;rr<8;rr++)
            {
                if(b[rr][c]==1)
                {
                    isAheadBlack=false;
                }
                if(c>0&&b[rr][c-1]==1)
                {
                    isAheadBlack=false;
                }
                if(c<7&&b[rr][c+1]==1)
                {
                    isAheadBlack=false;
                }
            }
            if(isAheadBlack)
            {
                score-=20+(r-1)*10;
            }
        }
        }
    }

return score;
}