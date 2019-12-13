// Question : Find the pair with zero sum.
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
	int n;
	cin >> n;
	int *a = new int[n];
	unordered_map<int,int> table;
	for(int i=0;i<n;++i){
		cin >> a[i];
		if(table.count(-1*a[i])==1){
			cout<<"index => "<<table[-1*a[i]]<<" , "<<i<<endl;
		}
		table[a[i]] = i;
	}	
	return 0;
}

// Input : 

// 10
// 1 2 -1 1 1 -3 -2 7 7 5

// Output :

// index => 0 , 2
// index => 2 , 3
// index => 2 , 4
// index => 1 , 6