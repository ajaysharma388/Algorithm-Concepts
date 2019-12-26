#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void generateParenthesis(char *out,int n,int open=0,int close=0,int i=0){
	if(i == 2*n){
		out[i] = '\0';
		cout<<out<<endl;
	}
	if(close<open){
		out[i] = ')';
		generateParenthesis(out,n,open,close+1,i+1);
	}
	if(open<n){
		out[i] = '(';
		generateParenthesis(out,n,open+1,close,i+1);
	}
	return;
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
	char out[2*n]={};	
	generateParenthesis(out,n,0,0,0);
	return 0;
}