// Question target sum using hasing.
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
	int m;
	cin >> m;
	int *a = new int[m];
	for(int i=0;i<m;++i){
		cin >> a[i];
	}
	int target;
	cin >> target;
	unordered_map<int,int> table;
	for(int i=0;i<m;++i){
		if(table.count(a[i])==1){
			cout<<"("<<target-a[i]<<" , "<<a[i]<<")"<<endl;
		}
		table[target-a[i]] = 1;
	} 
	delete []a;
	return 0;
}