#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Heap
{
	vector<T> v;
	bool isMinHeap;	
	bool compare(T a,T b){
		return (isMinHeap)? a<b : a>b ;
	}
	void heapify(const int index){
		int leftIndex = 2*index;
		int rightIndex = 2*index+1;
		// consider current as the min.
		int minIndex = index;
		// checking if the left has min data.
		if(leftIndex<v.size() && compare(v[leftIndex],v[minIndex])){
			minIndex = leftIndex;
		}
		// checking if the right has min data.
		if(rightIndex<v.size() && compare(v[rightIndex],v[minIndex])){
			minIndex = rightIndex;
		}
		// if current element is not minimum then we should do swap.
		if(minIndex!=index){
			swap(v[index],v[minIndex]);
			heapify(minIndex);
		}
	}
public:
	Heap(const bool type = true){
		isMinHeap = type;
		v.push_back(-1);
	}
	void push(const T data){
		// inserting data at the back.
		v.push_back(data);
		// now we are placing elment at it's appropriate location.
		// that simply means heapify.
		int index = v.size()-1;
		int parent = index/2;
		while(index>1 && compare(v[index],v[parent])){
			swap(v[index],v[parent]);
			index = parent;
			parent/=2;
		}
	}
	// we shall remove the element at top.
	void pop(){
		// getting the last element.
		int last = v.size()-1;
		// swapping the first and the last element.
		swap(v[1],v[last]);
		// removing the last element.
		v.pop_back();
		// retainning the heap property.
		heapify(1);
	}
	// returning the topmost element.
	T top(){
		return v[1];
	}
	// checking whether heap is empty or not.
	bool isEmpty(){
		return v.size()==1;
	}
	// printing the data of the heap.
	void printHeap(){
		for(int i=1;i<v.size();++i){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Heap<int> hmin(true); // min heap.
	Heap<int> hmax(false); // max heap. 
	int n;
	cin >> n;
	while(n--){
		int data;
		cin >> data;
		hmin.push(data);
		hmax.push(data);
	}
	cout<<"Min Heap : ";
	hmin.printHeap();
	cout<<"Max Heap : ";
	hmax.printHeap();
	return 0;
}


// Input : 

// 10
// 1 3 6 8 10 5 4 9 2 7 

// Output : 

// Min Heap : 1 2 4 3 7 6 5 9 8 10 
// Max Heap : 10 9 5 8 7 3 4 1 2 6 