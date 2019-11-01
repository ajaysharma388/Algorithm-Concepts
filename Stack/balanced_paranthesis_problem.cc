#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


bool check(string &exp){
	int n = exp.length();
	stack<char> s;
	for(int i=0;i<n;++i){
		if(exp[i]=='('){
			s.push(exp[i]);
		}
		else if(exp[i]==')' && !s.empty()){
			s.pop(); 
		}
	}
	return s.empty();
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string exp;
		cin >> exp;
		(check(exp))
			?cout<<"Yes"<<endl
			:cout<<"No"<<endl;
	}
	return 0;
}