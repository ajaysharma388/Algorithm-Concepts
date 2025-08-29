#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

std::map<string, bool> mp;

void trickyPermutation(char *s,int l,int r){
	if(l==r){
		string res(s);
		mp[res] = true;
		return;
	}
	for(int i=l;i<=r;++i){
		swap(s[l],s[i]);
		trickyPermutation(s,l+1,r);
		swap(s[l],s[i]);
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
	int t;
	cin >> t;
	while(t--){
		char s[100];
		cin >> s;
		int len = strlen(s);
		sort(s,s+len);
		trickyPermutation(s,0,len-1);
		// for (int i = 0; i < vec.size(); ++i){
		// 	cout << vec[i] << endl;
		// }
		for(auto node:mp){
			cout<<node.first<<endl;
		}
		mp.clear();
		cout << endl;
	}
	return 0;
}