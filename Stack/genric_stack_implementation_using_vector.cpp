#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

template<typename T>
class Stack{
private:
	vector<T> v;
public:
	void push(const T data){
		v.push_back(data);
	}
	bool isEmpty(){
		return v.size()==0;
	}
	void pop(){
		if(!isEmpty()){
			v.pop_back();
		}
	}
	T top(){
		return v[v.size()-1];
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
	Stack<char> s;
	for(int i=65;i<=75;++i){
		s.push(i);
	}	
   	// printing the top element after poping until stack is 
   	// empty.
	while(!s.isEmpty()){
		cout<<"current top : "<<s.top()<<endl;
		s.pop();
	}
	return 0;
}