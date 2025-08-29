#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class MINHeap{
	vector<T> v;
	int lastIndex;
public:
	MINHeap(){
		lastIndex = 1;
        v.reserve(30);
        v[0] = INT_MIN;
	}
	T minData(){
		return v[1];
	}
	T getKth(int k){
		return v[k-1];
	}
	void pop(){
		swap(v[1],v[lastIndex-1]);
		lastIndex--;
		int cur = 1;
		while(2*cur+1<lastIndex && (v[cur]>v[2*cur] || v[cur]>v[2*cur+1])){
			if(v[cur]>v[2*cur]){
				swap(v[cur],v[2*cur]);
			}
			if(v[cur]>v[2*cur+1]){
				swap(v[cur],v[2*cur+1]);
			}
			cur*=2;					
		} 
	}
	void insert(const T data){
		v[lastIndex] = data;
		int cur = lastIndex;
		lastIndex++;
		while(cur && v[cur]<v[cur/2]){
			swap(v[cur],v[cur/2]);
			cur/=2;
		}
	}
	void printHeap(){
		for(int i=1;i<lastIndex;++i){
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
	MINHeap<int> heap;
	int n;
	cin >> n;
	while(n--){
		int data;
		cin >> data;
		heap.insert(data);
	}
	heap.printHeap();
	cout<<heap.minData()<<endl;
	heap.pop();
	cout<<heap.minData()<<endl;
	heap.pop();
	cout<<heap.minData()<<endl;
	heap.pop();
	cout<<heap.minData()<<endl;
	heap.printHeap();
	return 0;
}

// Input : 

// 10
// 1 3 6 8 10 5 4 9 2 7 

// Output :

// 1 2 4 3 7 6 5 9 8 10 
// 1
// 2
// 3
// 4
// 4 8 7 10 9 6 5 