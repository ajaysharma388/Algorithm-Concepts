#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void printStack(stack<int>& s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}


void insert(stack<int>& s,int data){
	if(s.empty()){
		s.push(data);
		return;
	}
	int t = s.top();
	s.pop();
	insert(s,data);
	s.push(t);
}

void reverseRecursive(stack<int>& s){
	if(s.empty()) return;
	int current = s.top();
	s.pop();
	reverseRecursive(s);
	insert(s,current);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		s.push(data);
	}
	reverseRecursive(s);
	printStack(s);
	return 0;
}