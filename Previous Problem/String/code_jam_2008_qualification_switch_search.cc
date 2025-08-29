#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void data(string e[],int s,int q){
	cout << q << " " << s <<endl; 
	for(int i=0;i<s;++i) 
		cout << e[i] << endl;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	while(n--){
		int s,q;
		cin >> s;
		string engine[s],c_que;
		for(int j=0;j<s;j++) getline(cin,engine[j]);
		cin >> q;
		for(int j=0;j<q;j++){
			getline(cin,c_que);
		}
		data(engine,s,q);
	}
	return 0;
}