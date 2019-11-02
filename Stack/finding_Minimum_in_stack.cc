#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


template<typename T>
class Stack
{
	stack<T> s;
	T currentMin;
public:
	Stack(){
		currentMin = 0;
	}
	void push(const int data){
		if(s.empty()){
			s.push(data);
			currentMin = data;
		}else{
			if(currentMin>data){
				s.push(2*data-currentMin);
				currentMin = data;	
			}else{
				s.push(data);
			}
		}
	}
	void pop(){
		if(s.empty()) return;
		int y = s.top();
		if(currentMin<=y){
			s.pop();
		}else{
			currentMin = 2*currentMin-y;
			s.pop();
		}
		if(s.empty()) currentMin = 0;
	}
	int getMin(){
		return currentMin;
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
	Stack<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		s.push(data);
	}
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout<<s.getMin()<<endl;
	return 0;
}