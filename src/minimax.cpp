#include "minimax.hpp"
#include "evaluation/evaluate.hpp"
void rook_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    for(int i=0;i<4;i++){
        int a=x;
        int b=y;
        while(true){
            a+=hor[i];
            b+=ver[i];
            if(a>=0 && b>=0 && a<8 && b<8){
                if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
                if(v.board[a][b]) break;
            }
            else break;
        }
    }
}
void bishop_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    for(int i=0;i<4;i++){
        int a=x;
        int b=y;
        while(true){
            a+=dig_x[i];
            b+=dig_y[i];
            if(a>=0 && b>=0 && a<8 && b<8){
                if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
                if(v.board[a][b]) break;
            }
            else break;
        }
    }
}
void queen_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    bishop_moves(v,x_king,y_king,x,y,ds);
    rook_moves(v,x_king,y_king,x,y,ds);
}
void knight_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    for(int i=0;i<8;i++){
        int a=x+knight_x[i];
        int b=y+knight_y[i];
        if(a>=0 && b>=0 && a<8 && b<8){
            if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
        }
    }
}
void king_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    for(int i=0;i<4;i++){
        int a=x+hor[i];
        int b=y+ver[i];
        if(a>=0 && b>=0 && a<8 && b<8){
            if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
        }
    }
    for(int i=0;i<4;i++){
        int a=x+dig_x[i];
        int b=y+dig_y[i];
        if(a>=0 && b>=0 && a<8 && b<8){
            if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
        }
    }
}
void pawn_moves(Board &v,int x_king,int y_king,int x,int y,vector<vector<int>> &ds){
    int step;
    if(v.board[x_king][y_king]>0) step=-1;
    else step=1;
    int a;
    int b;
    a=x+step;
    b=y;
    if(a>=0 && b>=0 && a<8 && b<8){
        if(validate(v,x,y,a,b,x_king,y_king)) ds.push_back({x,y,a,b});
    }
    a=x+2*step;
    b=y;
    if(a>=0 && b>=0 && a<8 && b<8){
        if(validate(v,x,y,a,b,x_king,y_king))ds.push_back({x,y,a,b});
    }
    a=x+step;
    b=y-1;
    if(a>=0 && b>=0 && a<8 && b<8){
        if(validate(v,x,y,a,b,x_king,y_king))ds.push_back({x,y,a,b});
    }
    a=x+step;
    b=y+1;
    if(a>=0 && b>=0 && a<8 && b<8){
        if(validate(v,x,y,a,b,x_king,y_king))ds.push_back({x,y,a,b});
    }
}


//function to generate all legal moves
// flag=1 white
// flag=-1 black
vector<vector<int>> generateMoves(Board &v,int x_king,int y_king){
    vector<vector<int>> moves;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(v.board[i][j]*v.board[x_king][y_king]>0){
                int tp=abs(v.board[i][j]);
                if(tp==1) pawn_moves(v,x_king,y_king,i,j,moves);
                else if(tp==2) rook_moves(v,x_king,y_king,i,j,moves);
                else if(tp==3) knight_moves(v,x_king,y_king,i,j,moves);
                else if(tp==4) bishop_moves(v,x_king,y_king,i,j,moves);
                else if(tp==5) queen_moves(v,x_king,y_king,i,j,moves);
                else if(tp==6) king_moves(v,x_king,y_king,i,j,moves);
            }
        }
    }
    return moves;
}

int minimax(Board &v,int depth,int alpha,int beta,int player)
{   
    int white_king_x = -1, white_king_y = -1;
    int black_king_x = -1, black_king_y = -1;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(v.board[i][j] == 6) {
                white_king_x = i;
                white_king_y = j;
            }
            else if(v.board[i][j] == -6) {
                black_king_x = i;
                black_king_y = j;
            }
        }
    }

    if (white_king_x == -1) return -100000000;
    if (black_king_x == -1) return 100000000; 
    
    if(depth==0)
        return evaluate(v);

    vector<vector<int>> moves;
    if(player==1) moves=generateMoves(v,white_king_x,white_king_y);
    if(player==-1) moves=generateMoves(v,black_king_x,black_king_y);

    if(moves.empty())
        return evaluate(v);

    if(player==1)
    {
        // WHITE -> MAX
        int best=-1000000000;

        for(auto &move:moves)
        {
            int a=v.board[move[0]][move[1]];
            int b=v.board[move[2]][move[3]];

            v.board[move[2]][move[3]]=a;
            v.board[move[0]][move[1]]=0;

            if(abs(a)==1)
                promote_pawn(v,move[2],move[3]);

            int score=minimax(v,depth-1,alpha,beta,-player);

            v.board[move[2]][move[3]]=b;
            v.board[move[0]][move[1]]=a;

            best=max(best,score);

            alpha=max(alpha,best);
            if(beta<=alpha) break;
        }

        return best;
    }
    else
    {
        // BLACK -> MIN
        int best=1000000000;

        for(auto &move:moves)
        {
            int a=v.board[move[0]][move[1]];
            int b=v.board[move[2]][move[3]];

            v.board[move[2]][move[3]]=a;
            v.board[move[0]][move[1]]=0;

            if(abs(a)==1)
                promote_pawn(v,move[2],move[3]);

            int score=minimax(v,depth-1,alpha,beta,-player);

            v.board[move[2]][move[3]]=b;
            v.board[move[0]][move[1]]=a;

            best=min(best,score);

            beta=min(beta,best);

            if(beta<=alpha) break;
        }

        return best;
    }
}

vector<int> best_move(Board &v,int x_king,int y_king)
{
    cout << "AI: generating moves..." << endl;

    vector<vector<int>> moves=generateMoves(v,x_king,y_king);

    cout << "AI: moves = " << moves.size() << endl;

    if(moves.empty())
        return {};

    vector<int> bestMove=moves[0];
    int bestScore=1000000000;
    int alpha=-1000000000;
    int beta=1000000000;
    int cnt=0;

    for(auto &move:moves)
    {
        cout << "AI: testing move " << ++cnt << "/" << moves.size() << endl;

        int a=v.board[move[0]][move[1]];
        int b=v.board[move[2]][move[3]];

        v.board[move[2]][move[3]]=a;
        v.board[move[0]][move[1]]=0;

        if(abs(a)==1)
            promote_pawn(v,move[2],move[3]);

        int score=minimax(v,3,alpha,beta,1);

        cout << "    score = " << score << endl;

        v.board[move[2]][move[3]]=b;
        v.board[move[0]][move[1]]=a;

        if(score<bestScore)
        {
            bestScore=score;
            bestMove=move;
        }

        beta = min(beta, bestScore);
    }

    cout << "AI: selected move, score = " << bestScore << endl;

    return bestMove;
}