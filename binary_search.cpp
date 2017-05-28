#include <iostream>

using namespace std;

int binary_search(const int *arr, const int l, const int r, const int val){
	if(r >= l) {
		int mid = l + (r - l)/2;
		if (arr[mid] == val) {
			return mid;
		}
		else if (arr[mid] > val) {
			binary_search(arr, l, mid - 1, val); // search on left array [l, mid - 1]
		}
		else if (arr[mid] < val) {
			binary_search(arr, mid + 1, r, val); // search on right array [mid + 1, r]
		}
	}
	else{
		return -1;
	}
}

int main() {
	int sorted_arr[9] = {-7, 2, 5, 7, 9, 13, 15, 16, 20};
	int indx = binary_search(sorted_arr, 0, 8, 7);
	if (indx != -1) {
		cout << "Element at indx: " << indx;
	} else {
		cout << "Element not found";
	}
	return 0;
}
