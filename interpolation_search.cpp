// Interpolation search; O(log log(n) )
#include <iostream>

int interpolation_search(const int *arr, const int lo, const int hi, int val) {
    if (hi >= lo) {
        int pos = lo + ((val - arr[lo]) * (hi-lo) / (arr[hi]-arr[lo]));
        if (val == arr[pos]){
            return pos;
        } else if(val < arr[pos]) { // left sub array[lo, pos-1]
            return interpolation_search(arr, lo, pos - 1, val);
        } else {
            return interpolation_search(arr, pos + 1, hi, val);
        }
    }
    return -1;
}

int main(){
    int sorted_arr[] = {1, 3, 6, 9, 13, 15, 16, 18, 20, 21};
    int lo = 0;
    int hi = (sizeof(sorted_arr)/sizeof(int)) - 1;
    int val;
    std::cout << "Enter value to be searched: ";
    std::cin >> val;
    int indx = interpolation_search(sorted_arr, lo, hi, val);
    (indx == -1) ? std::cout << "Element not found" << std::endl : 
                   std::cout << "Element at index: " << indx << std::endl;
    return 0;
}
