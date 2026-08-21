#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Board{
    public:
    vector<vector<int>> board;
    pair<int,int> whiteKingPos;
    pair<int,int> blackKingPos;
    bool whiteKingMoved;
    bool blackKingMoved;
    bool whiteLeftRook;
    bool blackLeftRook;
    bool whiteRightRook;
    bool blackRightRook;
    Board();
    void display();
};