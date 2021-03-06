#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int a[10][10];

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> a[i][j];
		}
	}	
	ll sum=0;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			sum+=a[i][j]*((i+1)*(j+1))*((m-i)*(n-j));
		}
	}
	cout<<"Sum is : "<<sum<<endl;
	return 0;
}

// Question : We are supposed to find the sum of all the submatrix formed using
// a single matrix the above inpmlementation takes O(N^2) time for evaluating the 
// sum and the space requirement is O(1).

// Sample Input :

// 4 4
// 1 1 1 1 
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1

// Sample Output :

// Sum is : 400