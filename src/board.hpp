#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Board{
    public:
    vector<vector<int>> board;
    pair<int,int> whiteKingPos;
    pair<int,int> blackKingPos;
    Board();
    void display();
};