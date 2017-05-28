//Jump search

#include <iostream>
#include <math.h>

using namespace std;

int jumpsearch(const int *arr, const int n, int val) {
    int step = int(sqrt(n));
    int prev = 0;
    for (int i = step; i < n; i+=step){
        if (arr[i] == val){ // found val
        } else if (arr[i] > val) { // val is possibly between arr[prev, i]
            for(int j = prev; j < i; j++){
                if (arr[j] == val) {
                    return j;
                }
            }
        } else { // keep searching
            prev = i + 1;
        }
    }
    // last interval arr[x*step...n-1]
    if(prev < n){
        for(int i = prev; i < n; i++){
            if (arr[i] == val) {
                return i;
            }
        }
    }
    return -1;
}

int main(){
    int sorted_arr[] = {1,1,2,3,5,8,13,21,34,55,89};
    int n = sizeof(sorted_arr)/sizeof(int);
    int indx = jumpsearch(sorted_arr, n , 89);
    (indx == -1)?(cout << "Element not found") : (cout << "Element at indx: " << indx);
    return 0;
}
