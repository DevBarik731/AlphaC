#include <vector>

using namespace std;

int validatePawnMove(Board &b,int initial_row,int initial_column,int final_row,int final_column)
{
    vector<vector<int>> board=b.board;
    int piece=board[initial_row][initial_column];
    // if(piece!=1||piece!=-1)
    // {
    //     return 0;
    // }  
    int direction;
    if(piece==1)
    {
        direction=-1;
    }
    else
    {
        direction=1;
    }
    // Forward step by 1
    if(final_column==initial_column&&final_row==(initial_row+direction))
    {
        if(board[final_row][final_column]==0)
        {
            return 1;
        }
    }
    // Forward step by 2
    if(final_column==initial_column&&final_row==(initial_row+2*direction))
    {
        bool isAtStart;
        if(piece==1)
        {
            if(initial_row==6)
            {
                isAtStart=true;
            }
            else
            {
                isAtStart=false;
            }
        }
        else
        {
            if(initial_row==1)
            {
                isAtStart=true;
            }
            else
            {
                isAtStart=false;
            }
        }
        if(isAtStart&&board[initial_row+direction][initial_column]==0&&board[final_row][final_column]==0)
        {
            return 1;
        }
    }
    // Eliminate 
    if(abs(final_column-initial_column)==1&&final_row==(initial_row+direction))
    {
        if(board[final_row][final_column]!=0&&(piece*board[final_row][final_column]<0))
        {
            return 2;
        }
    }
    return 0;
}