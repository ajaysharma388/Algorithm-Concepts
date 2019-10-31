#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class stack_using_queues_II
{
	queue<T> *q1,*q2;
public:
	stack_using_queues_II(){
		q1 = new queue<T>();
		q2 = new queue<T>();
	}

	void push(const T data){
		// pushing data on the front of empty queue q2.
		q2->push(data);
		// getting the size of q1 queue.
		int n = q1->size(); 
		// pushing element one by one from queue q1 to q2.
		for(int i=0;i<n;++i){
			q2->push(q1->front());
			q1->pop();
		}
		// swapping the addresses of q1 & q2.
		if(q1->empty()){
			swap(q1,q2);
		}
	}

	void pop(){
		q1->pop(); // O(1) time complexity for pop operation.
	}

	T top(){
		return q1->front(); // O(1) time complexity to get top. 
	}
	
	~stack_using_queues_II(){
		delete q1;
		delete q2;
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
	stack_using_queues_II<int> Stack;
	for(int i=1;i<=10;++i){
		Stack.push(i*i);
	}
	cout<<Stack.top()<<" ";
	Stack.pop();
	cout<<Stack.top()<<" ";
	Stack.pop();
	cout<<Stack.top()<<" ";
	Stack.pop();
	cout<<Stack.top()<<" ";
	Stack.pop();
	cout<<Stack.top()<<" ";
	return 0;
}