#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Queue
{
	stack<T> A;
	stack<T> B;
public:
	Queue(){}
	void enQueue(const T data){
		if(A.empty()){
			A.push(data);
		}else{
			while(!A.empty()){
				B.push(A.top());
				A.pop();
			}
			A.push(data);
			while(!B.empty()){
				A.push(B.top());
				B.pop();
			}
		}
	}
	bool isEmpty(){
		return A.empty();
	}
	void deQueue(){
		A.pop();
	}	
	T front(){
		return A.top();
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
	int n;
	Queue<int> Q;
	cin >> n;
	for(int i=0;i<n;++i){
		Q.enQueue(i);
	}
	while(!Q.isEmpty()){
		cout<<Q.front()<<" ";
		Q.deQueue();
	}
	return 0;
}