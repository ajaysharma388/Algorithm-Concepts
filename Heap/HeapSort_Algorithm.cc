#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void downHeapifyHelper(vector<int> &heap,int idx,int heapSize){
	int leftIdx = 2*idx + 1;
	int rightIdx = 2*idx + 2;
	if(leftIdx >= heapSize and rightIdx >= heapSize){
		return;
	}
	int maxIdx = idx;
	if(leftIdx < heapSize and heap[leftIdx] > heap[maxIdx]){
		maxIdx = leftIdx;
	}
	if(rightIdx < heapSize and heap[rightIdx] > heap[maxIdx]){
		maxIdx = rightIdx;
	}
	if(idx == maxIdx) return;
	swap(heap[idx],heap[maxIdx]);
	downHeapifyHelper(heap,maxIdx,heapSize);
}

void display(vector<int> &heap){
	for(int i=0; i<heap.size(); ++i){
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}

void heapsort(vector<int> &heap){
	int heap_size = heap.size()-1;
	int n = heap.size()-1;
	for(int i=n;i>0;--i){
		swap(heap[0],heap[i]);
		heap_size--;
		downHeapifyHelper(heap,0,heap_size);
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

void buildHeapOptimised(vector<int> &heap){
	for(int i=heap.size()-1; i>=0; --i){
		downHeapify(heap,i);
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
		cin >> heap[i];
	}
	buildHeapOptimised(heap);
	cout<<"Heap Data : ";
	display(heap);
	heapsort(heap);
	cout<<"After Sorting : ";
	display(heap);
	return 0;
}

// Sample Input : 

// 11
// 40 43 2 9 100 35 5 20 10 38 45

// Sample Output : 

// Heap Data : 100 45 35 20 43 2 5 9 10 38 40 
// After Sorting : 2 5 9 10 20 35 38 40 43 45 100  