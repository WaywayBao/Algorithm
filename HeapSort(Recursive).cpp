// Max-Heap
#include<iostream>
using namespace std;

void Heapify(int arr[], int i, int n){
    int max = i, left = (i<<1) + 1, right = (i<<1) + 2;
    if (left < n && arr[left] > arr[max])	max = left;
    if (right< n && arr[right]> arr[max])	max = right;
    if (max != i){
        swap(arr[i], arr[max]);
        Heapify(arr, max, n);
    }
}

void HeapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; --i)
        Heapify(arr, i, n);
    for(int i=n-1; i>=0; --i){
		//cout<<arr[0]<<" ";
        swap(arr[0], arr[i]);
        Heapify(arr, 0, i);
    }
}

int main(){
	int n = 8;
	int arr[] = {5, 2, 1, 8, 4, 3, 6, 7};
	HeapSort(arr, n);
	cout<<endl;
	return 0;
}
