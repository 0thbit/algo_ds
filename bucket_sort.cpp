// bucket sort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucket_sort(float *arr, int n, int norm){
    vector<float> b[n];
    for(int i = 0; i < n; i++){
        int bn = n*(arr[i]/norm);
        b[bn].push_back(arr[i]);
    }

    for(int i =0; i < n; i++){
        int bn = n*(arr[i]/norm);
        sort(b[bn].begin(),b[bn].end());
    }
    
    // joining all buckets
    int indx =0;
    for(int i =0; i < n; i++){
        for(int j=0; j < b[i].size(); j++){
            arr[indx++] = b[i][j];
        }
    }
}

int main(){
    float arr[] = {0.12, 1.23, 2.13, 4.51, 1.51, 0.04, 2, 4};
    int normalize = 10; // bring it in range 0 to 1
    int n = sizeof(arr)/sizeof(arr[0]);
    bucket_sort(arr, n, normalize);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
