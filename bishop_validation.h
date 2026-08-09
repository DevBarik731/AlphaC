#include <vector>
using namespace std;

int validateBishopMove(Board &b,int initial_row,int initial_column,int final_row,int final_column)
{
    vector<vector<int>> board=b.board;
    int piece=board[initial_row][initial_column];
    if(abs(final_column-initial_column)!=abs(final_row-initial_row))
    {
        return 0;
    }
    int rowstep,colstep;
    if(final_row>initial_row)
    {
        rowstep=1;
    }
    else
    {
        rowstep=-1;
    }
    if(final_column>initial_column)
    {
        colstep=1;
    }
    else
    {
        colstep=-1;
    }
    int r=initial_row+rowstep;
    int c=initial_column+colstep;
    while(r!=final_row&&c!=final_column)
    {
        if(board[r][c]!=0)
        {
            return 0;
        }
        r+=rowstep;
        c+=colstep;
    }
    if(board[final_row][final_column]!=0)
    {
        int possible=piece*board[final_row][final_column];
        if(possible<0)
        {
            return 2;
        }
        return 0;
    }
    return 1;
}