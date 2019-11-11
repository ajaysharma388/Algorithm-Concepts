#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void transfer(stack<int> &sa,stack<int> &sb){	
	while(!sa.empty()){
		sb.push(sa.top());
		sa.pop();
	}
	return;
}

void reverse(stack<int> &sa){
	if(sa.empty()){
		return;
	}
	int x = sa.top();
	sa.pop();
	stack<int> sb;
	transfer(sa,sb);
	sa.push(x);
	reverse(sb);
	transfer(sb,sa);
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
	stack<int> s;
	for(int i=0;i<n;++i){
		int data;
		cin>>data;
		s.push(data);
	}
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}