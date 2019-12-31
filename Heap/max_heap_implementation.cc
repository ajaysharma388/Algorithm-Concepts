#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void upHeapify(vector<int> &heap,int idx){
	if(idx == 0){
		return;
	}
	int parentIdx = (idx - 1)/2;
	if(heap[parentIdx]<heap[idx]){
		swap(heap[parentIdx],heap[idx]);
		upHeapify(heap,parentIdx);
	}else{
		return;
	}
}

void downHeapify(vector<int> &heap,int idx){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heap.size() and rightIdx >= heap.size()){
		return;
	}
	int maxIdx = idx;
	if(leftIdx < heap.size() and heap[leftIdx] > heap[maxIdx]){
		maxIdx = leftIdx;
	}
	if(rightIdx < heap.size() and heap[rightIdx] > heap[maxIdx]){
		maxIdx = rightIdx;
	}
	if(idx == maxIdx) return;
	swap(heap[idx],heap[maxIdx]);
	downHeapify(heap,maxIdx);
}

// Order of complexity of inserting the element into the heap is O(logn).

void insert(vector<int> &heap,int key){
	heap.push_back(key);
	upHeapify(heap,heap.size()-1);
}

// Order of complexity to delete the element from heap is O(logn)

void deletePeak(vector<int> &heap){
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	downHeapify(heap,0);
}

void display(vector<int> &heap){
	for(int i=0; i<heap.size(); ++i){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

// Order of complexity is O(nlogn) to convert the random array into 
// max heap.

void buildHeap(vector<int> &heap){
	for(int i=0; i<heap.size(); ++i){
		upHeapify(heap,i);
	}
}

// Order of complexity is O(n) to convert the random array into 
// max heap.

void buildHeapOptimised(vector<int> &heap){
	for(int i=heap.size()-1; i>=0; --i){
		downHeapify(heap,i);
		display(heap);
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;	
	cin >> n;
	vector<int> heap(n);
	for(int i=0; i<n; ++i){
		// int x;
		cin >> heap[i];
		// insert(heap,x);
	}
	display(heap);
	buildHeapOptimised(heap);
	display(heap);
	return 0;
}

// Sample Input : 

// 11
// 100 40 43 35 5 2 9 20 10 38 45

// Sample Output : 

// 100 40 43 35 5 2 9 20 10 38 45 
// 100 45 43 35 40 2 9 20 10 38 5 