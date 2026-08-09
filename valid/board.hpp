#pragma once
#include<vector>
#include<iostream>
using namespace std;
class Board{
    public:
    vector<vector<int>> board;
    Board();
    void display();
};