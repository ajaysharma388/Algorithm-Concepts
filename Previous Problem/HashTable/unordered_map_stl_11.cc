#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool checkIfSubarrayWithSumZero(int *arr,int n){
	unordered_set<int> s;
	int pre=0;
	for(int i=0;i<n;++i){
		pre+=arr[i];
		if(pre==0 or s.find(pre)!=s.end()){
			return true;
		}
		s.insert(pre);
	}
	return false;
}

int main(int argc,char const *argv[]){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int caseno=1;caseno<=t;++caseno){
		cout<<"Case No : "<<caseno<<endl;
		int n;
		cin >> n;
		int *arr = new int[n];
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}	
		bool result = checkIfSubarrayWithSumZero(arr,n);
		if(result){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		delete []arr;
	}
	return 0;
}

// Sample Input : 

// 2
// 5
// 6 -1 2 1 1
// 7
// 4 3 -4 1 2 1 -3

// Sample Output : 

// Case No : 1
// No
// Case No : 2
// Yes