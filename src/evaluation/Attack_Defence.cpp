#include "Attack_Defence.hpp"


// This function is similar to king_check function, it calculates immidiate attackers and defenders
// it returns a pair {#Attackers, #defenders}
vector<int> Attacker_Defender_Count(Board &v,int x,int y){
    int smallest_attacker=-1;
    int smallest_defender=-1;
    int Attack=0,defence=0;
    if(v.board[x][y]>0){
        for(int it=0;it<4;it++){
            int a=x+ver[it];
            int b=y+hor[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=ver[it];
                b+=hor[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                
                if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==1){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==-5 || v.board[a][b]==-2){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==1){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==5 || v.board[a][b]==2){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
            }
        }
        for(int it=0;it<4;it++){
            int a=x+dig_x[it];
            int b=y+dig_y[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=dig_x[it];
                b+=dig_y[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==2){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==-5 || v.board[a][b]==-4){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==-1 && (abs(x-a)+abs(y-b))==2 && x>a){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==2){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==5 || v.board[a][b]==4){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==1 && (abs(x-a)+abs(y-b))==2 && x<a){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
            }
        }

        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==-3){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==3){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
        }
    }

    else{
        for(int it=0;it<4;it++){
            int a=x+ver[it];
            int b=y+hor[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=ver[it];
                b+=hor[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
               if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==1){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==-5 || v.board[a][b]==-2){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==1){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==5 || v.board[a][b]==2){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
            }
        }
        for(int it=0;it<4;it++){
            int a=x+dig_x[it];
            int b=y+dig_y[it];
            while(a<8 && b<8 && a>=0 && b>=0){
                if(v.board[a][b]!=0) break;
                a+=dig_x[it];
                b+=dig_y[it];
            }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]!=0){
                if(v.board[a][b]==-6 && (abs(x-a)+abs(y-b))==2){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==-5 || v.board[a][b]==-4){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                };
                if(v.board[a][b]==-1 && (abs(x-a)+abs(y-b))==2 && x>a){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
                if(v.board[a][b]==6 && (abs(x-a)+abs(y-b))==2){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==5 || v.board[a][b]==4){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
                if(v.board[a][b]==1 && (abs(x-a)+abs(y-b))==2 && x<a){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
            }
        }
        for(size_t i=0;i<8;i++){
            int a=x+knight_x[i];
            int b=y+knight_y[i];
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==-3){
                    if(smallest_defender==-1) smallest_defender=victim_value[abs(v.board[a][b])];
                    else smallest_defender=min(smallest_defender,victim_value[abs(v.board[a][b])]);
                    defence++;
                }
            if(a<8 && b<8 && a>=0 && b>=0 && v.board[a][b]==3){
                    if(smallest_attacker==-1) smallest_attacker=victim_value[abs(v.board[a][b])];
                    else smallest_attacker=min(smallest_attacker,victim_value[abs(v.board[a][b])]);
                    Attack++;
                }
        }

    }

    return {Attack,defence,max(0,smallest_attacker),max(0,smallest_defender)};
}


//This function calculates pressure_value of a square using victim_value and attack and defence values 
pair<int,int> pressure_value(Board &v,int x,int y){
    if(!v.board[x][y]) return {0,0};
    int piece=abs(v.board[x][y]);
    vector<int> p=Attacker_Defender_Count(v,x,y);
    int attack=p[0];
    int defence=p[1];
    int press;
    if (attack==0) press=0;
    else if (defence==0) press=victim_value[piece];
    else press=victim_value[piece] * max(0, attack - defence);
    int threat=max(0,victim_value[piece]-p[2]-p[3]);
    if(attack==0) threat=0;
    if(defence==0) threat*=2;
    return {press,threat};
}

// this function basically sums the value of pressure values gives white-black;
pair<int,int> pressure(Board &v){
    int press=0;
    int threat=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            pair<int,int> p;
            if(v.board[i][j]>0){
                p=pressure_value(v,i,j);
                press+=p.first;
                threat+=p.second;
            }
            else if(v.board[i][j]<0){
                p=pressure_value(v,i,j);
                press-=p.first;
                threat-=p.second;
            } 

        } 
    }
    return {press,threat};
    
}

