#pragma once
#include "../validate.hpp"
using namespace std;
#include "../board.hpp"
const int victim_value[6]={0,10,50,30,30,90};
pair<int,int> pressure_value(Board &v,int x,int y);
vector<int> Attacker_Defender_Count(Board &v,int x,int y);
pair<int,int> pressure(Board &v);