#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string redundantParathesis(string s){
	stack<char> pile;
	bool redundant_flag = false;
	for(int i=0;i<s.length();++i){
		if(s[i]==')'){
			// if we have extra paraenthesis the we say 
			if(pile.top()=='(')	redundant_flag = !redundant_flag;
			// if not then we had expression here.
			while(!pile.empty() and pile.top()!='('){
				pile.pop();
			}
			// remove the starting parenthesis of expression.
			if(!pile.empty()) pile.pop();
		}else{
			// else we have either oprator or oprand to take care off.
			pile.push(s[i]);
		}
	}
	return (redundant_flag)?"Duplicate":"Not Duplicates";
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
	string expression;
	while(t--){
		cin >> expression;
		cout << redundantParathesis(expression) << endl;
	}
	return 0;
}