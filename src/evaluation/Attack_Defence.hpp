#pragma once
#include "../validate.hpp"
using namespace std;
#include "../board.hpp"
const int hor[4]={0,0,1,-1};
const int ver[4]={1,-1,0,0};
const int dig_x[4]={1,1,-1,-1};
const int dig_y[4]={1,-1,1,-1};
const int knight_x[8]={1,1,-1,-1,2,2,-2,-2};
const int knight_y[8]={-2,2,-2,2,1,-1,1,-1};
const int victim_value[6]={0,10,50,30,30,90};
pair<int,int> pressure_value(Board &v,int x,int y);
vector<int> Attacker_Defender_Count(Board &v,int x,int y);
pair<int,int> pressure(Board &v);