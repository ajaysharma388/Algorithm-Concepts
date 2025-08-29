#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> module;
	int Q;
	cin >> Q;
	while(Q--){
		int o;
		cin >> o;
		if(o==1 && !module.empty()){
			cout<<module.top()<<endl;
			module.pop();
		}else if(o==2){
			int cost;
			cin >> cost;
			module.push(cost);
		}else{
			cout<<"No Code"<<endl;
		}
	}
	return 0;
}