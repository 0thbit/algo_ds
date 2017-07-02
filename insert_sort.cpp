#include <iostream>

using namespace std;

int partition(int *arr, int lo, int hi){
    int pivot = hi;
    int i = lo - 1;
    for(int j = lo; j<hi; j++){ //arr[lo..hi-1]
        if(arr[j]<=pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[hi]);
    return i+1;
}

void quick_sort(int *arr, int lo, int hi) {
    if(lo < hi){
        int pivot = partition(arr,lo,hi);
        quick_sort(arr, lo, pivot-1);
        quick_sort(arr, pivot+1, hi);
    }
}

int main(){
    int arr[] = {13,55,21,1,34,3,6,1,2,5,8,89};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr,0, n-1);
    for(int i =0; i < n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
