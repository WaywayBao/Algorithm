// Max-Heap
#include<iostream>
using namespace std;

void Heapify(int arr[], int i, int n){
	for(int max = i;; i = max){
		int left = i<<1+1, right = i<<1+2;
		if(left < n && arr[left] > arr[max]) max = left;
		if(right< n && arr[right]> arr[max]) max = right;
		if(i == max)  break;
		swap(arr[i], arr[max]);
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

//Heap tree
/*
vector<int> arr;
void insert(int v){
    list.push_back(v);
    int n = list.size();
	while(n>1 && list[n-1] > list[n/2-1]){
		swap(list[n-1], list[n/2-1]);
		n /= 2;
	}
}

int delete(){
	if(list.empty()){
		cout<<"Empty list"<<endl;
		return -1;
	}
	int v = list[0];
    int n = list.size();
	swap(list[0], list[n-1]);
	list.pop();
	n = list.size();
	for(int i = 0, max = 0; i < n; i = max){
		int left = i*2 + 1, right = i*2 + 2;
		if(left < n && list[left] > list[max]) max = left;
		if(right < n && list[right] > list[max]) max = right;
		if(i == max) break;
		swap(list[i], list[max]);
	}
	return v;
}

void print_in_order(){
	int i=0, n = list.size();
	vector<int> s;
	while( i < n || !s.empty() ){
		// find the largest left child
		while(i < n){
			s.push_back(i);
			i = i*2 + 1;
		}
		i = s.back();
		cout<<list.at(i)<<" ";
		s.pop_back();
		// find the right child
		i = i*2 + 2;
	}
}
*/
