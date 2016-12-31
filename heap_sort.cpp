#include <iostream>

using namespace std;

void maxheapify(int* arr, int n , int i){
  int largest =i;
  int l=2*i+1;
  int r=2*i+2;
  
  if(l<n && arr[l]>arr[largest]){
    largest=l;
  }
  
  if(r<n && arr[r]>arr[largest]){
    largest=r;
  }
  
  if(largest!=i){
    swap(arr[i],arr[largest]);
    maxheapify(arr,n,largest);//recursively heapify sub-heap
  }
}

void heapsort(int* arr, int n){
 
  for(int i=n/2-1; i>=0; i--){//only lower n/2 -1 nodes have childeren
    maxheapify(arr,n,i);
  }
  
  for(int j=n-1;j>=0;j--){
      swap(arr[0],arr[j]);
      maxheapify(arr,j,0);// notice size of arr as j
  }
  
}

int main(){
        int i;
	int arr[9]={8,3,4,0,1,7,9,4,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	for(i=0;i<n;i++){
	  cout<<arr[i]<<" ";
	}
	cout<<endl;
	heapsort(arr,n);
	//cout<<n;
	for(i=0;i<n;i++){
	  cout<<arr[i]<<" ";
	}
	return 0;
}
