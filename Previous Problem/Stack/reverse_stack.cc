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

void transfer(stack<int>& s,stack<int>& d,int e){
	for(int i=0;i<e;++i){
		int temp = s.top();
		d.push(temp);
		s.pop();
	}
}

void reverse(stack<int>& s1){
	stack<int> s2;
	int n = s1.size();
	for(int i=0;i<n;++i){
		int curr = s1.top();
		s1.pop();
		int nVacant = n-i-1;
		transfer(s1,s2,nVacant);
		s1.push(curr);
		transfer(s2,s1,nVacant);
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
	stack<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		int data;
		cin >> data;
		s.push(data);
	}
	reverse(s);
	printStack(s);
	return 0;
}