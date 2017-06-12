#include <iostream>
#include <limits.h>

#define R 3
#define C 3

using namespace std;

int memo[R][C] = {};

int min(int x, int y, int z){
    if(x<y){
        if(x<z){
            return x;
        } else {
            return z;
        }
    } else{
        if(y<z){
            return y;
        } else{
            return z;
        }
    }
}

int min_path_cost(int cost[R][C], int m, int n){
    if(memo[m][n]!=0){
        return memo[m][n];
    } else if(m<0 || n<0){
        return INT_MAX;
    } else if(m==0 && n==0){
        return cost[0][0];
    } else{
        memo[m][n] = cost[m][n] + min( min_path_cost(cost,m-1,n),
                                       min_path_cost(cost,m,n-1),
                                       min_path_cost(cost,m-1,n-1)
                                );
        return memo[m][n];
    }
}

int main(){
    int arr[R][C]={{1, 2, 3},
                   {4, 8, 2},
                   {1, 5, 3} };
    cout << min_path_cost(arr,2,1);
    
    return 0;
}
