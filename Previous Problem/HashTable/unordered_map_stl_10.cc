#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


void printSubArray(int *a,int s,int e){
	while(s<=e){
		cout<<a[s]<<" ";
		s++;
	}
	cout<<endl;
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
	for(int caseno=1;caseno<=t;++caseno){
		cout<<"Case No : "<<caseno<<endl;
		unordered_map<int,vector<int>> table;
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		int pre = 0;
		for(int i=0;i<n;++i){
			pre+=a[i];
			if(table.count(pre)==1){
				for(int k=0;k<table[pre].size();++k){
					printSubArray(a,table[pre][k]+1,i);
				}
			}
			table[pre].push_back(i);
		}
		delete []a;
	}	
	return 0;
}

// Sample Input : 

// 2
// 5
// 6 -1 2 -1 1
// 7
// 4 3 -4 1 2 1 -3

// Sample Output : 

// Case No : 1
// -1 2 -1 
// -1 1 
// Case No : 2
// 3 -4 1 
// -4 1 2 1 
// 3 -4 1 2 1 -3 
// 2 1 -3 