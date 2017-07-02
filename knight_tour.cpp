#include <iostream>

#define N 8

void print_board(int sol[N][N]){
    for(int row = 0; row < N; row++){
        for(int col =0; col < N; col++){
            std::cout<<sol[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool isValid(int x, int y, int sol[N][N]){
    //std::cout<<"\nChecking validity of:"<<x<<" "<<y<<"\n";
    if(x >= N || y >= N || x < 0 || y < 0){
        return false;
    } else if(sol[x][y] == -1){ // square visited
        return true;
    } else{
        return false;
    }
}

bool solvekt(int sol[N][N], int curr_x, int curr_y, int move){
    print_board(sol);
    if(move == N*N) {
        return true;
    } else {
        int x_next[8] = { 2, 1, 2, 1,-2,-1,-2,-1};
        int y_next[8] = { 1, 2,-1,-2, 1, 2,-1,-2};
        
        for(int i = 0; i < 8; i++){
            int next_x = curr_x + x_next[i];
            int next_y = curr_y + y_next[i];
            if(isValid(next_x,next_y,sol) == true){
                sol[next_x][next_y] = move;
                if(solvekt(sol,next_x,next_y,move+1) == true){
                    print_board(sol);
                    return true;
                } else {
                    sol[next_x][next_y] = -1; //backtrack
                }
            }
        }
        return false;
    }
}

int main(){
    int sol[N][N];
    //
    for(int row = 0; row < N; row++){
        for(int col =0; col < N; col++){
            sol[row][col] = -1;
        }
    }
    print_board(sol);
    sol[0][0] = 0;
    if(solvekt(sol,0,0,1) == true){
        print_board(sol);
    } else {
        std::cout<<"Soln does not exist";
    }

    return 0;
}
