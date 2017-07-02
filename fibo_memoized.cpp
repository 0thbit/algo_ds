// nth fibonacci number

#include <iostream>

#define MAX 100

int *memo[MAX] = {};

int fib(int n){
    if(memo[n]!=0){
        return *memo[n];
    } else {
        *memo[n] = fib(n-1) + fib(n-2);
        return *memo[n];
    }
}

int main(){
    int x = fib(5);
    std::cout << x;
}
