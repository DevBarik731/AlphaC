
#include<vector>
#include <stdlib.h>
#include "board.hpp"
#include "queen.hpp"

using namespace std;

int Queen_validate(Board &b,int initial_row,int initial_column,int final_row,int final_column)
{
    vector<vector<int>> board=b.board;
    int piece = board[initial_row][initial_column];
    bool diagonal=(abs(final_row-initial_row)==abs(final_column-initial_column));
    bool vertical=initial_column==final_column;
    bool horizontal=initial_row==final_row;
    if(!diagonal&&!vertical&&!horizontal)
    {
        return 0;
    }
    int rowstep=0,colstep=0;
    if(final_row>initial_row)
    {
         rowstep=1;
    }
    else if(final_row<initial_row)
    {
        rowstep=-1;
    }
    if(final_column>initial_column)
    {
        colstep=1;
    }
    else if(final_column<initial_column)
    {
        colstep=-1;
    }
    int r=initial_row+rowstep;
    int c=initial_column+colstep;
    while(r!=final_row||c!=final_column)
    {
        if(board[r][c]!=0)
        {
            return 0;
        }
        r+=rowstep;
        c+=colstep;
    }
    if(board[final_row][final_column]==0)
    {
        return 1;
    }
    if(piece*board[final_row][final_column]<0)
    {
        return 2;
    }
    return 0;
}