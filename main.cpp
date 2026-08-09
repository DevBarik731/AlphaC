#include<iostream>
#include<vector>
#include "board.h"
#include "knight.h"
#include "king.h"
#include "rook.h"
using namespace std;

int main(){
    Board a=Board();
    a.display();
    cout<<"\n";

    cout<<King_validate(a,7,4,6,4)<<endl;
    cout<<Knight_validate(a,7,1,5,0)<<endl;
    cout<<Rook_validate(a,7,0,7,5)<<endl;

}