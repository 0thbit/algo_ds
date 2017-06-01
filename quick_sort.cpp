#include <iostream>

using namespace std;

int partition(int *arr, int lo, int hi){
    int pivot = arr[hi];
    int i = lo - 1;
    for(int j = lo; j<hi; j++){ //arr[lo..hi-1]
        if(arr[j]<=pivot){
            i++;
            swap(arr[j],arr[i]);//swap lower digits to lower indices
        }
    }
    //cout<<"___"<<i<<hi<<endl;
    swap(arr[i+1],arr[hi]);
    return i+1;
}

void display(int *arr, int lo, int hi){
    for(int i=lo; i<=hi; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void quick_sort(int *arr, int lo, int hi) {
    if(lo < hi){
        //display(arr,lo,hi);
        int pivot_indx = partition(arr,lo,hi);
        //cout<<pivot_indx<<":: "<<arr[pivot_indx]<<endl;
        //display(arr,lo,hi);
        //cout<<endl;
        quick_sort(arr, lo, pivot_indx-1);
        quick_sort(arr, pivot_indx+1, hi);
    }
}

int main(){
    int arr[] = {13,55,21,1,34,3,6,1,2,5,8,89};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr,0, n-1);
    display(arr,0,n-1);
    return 0;
}
