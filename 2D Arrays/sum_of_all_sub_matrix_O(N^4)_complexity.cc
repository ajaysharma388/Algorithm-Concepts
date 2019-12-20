#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int a[10][10];

int subMatrix(int s,int e,int u,int l){
	if(s>0&&u>0)	return a[e][l]+a[s-1][u-1]-a[e][u-1]-a[s-1][l];
	else if(u==0)	return a[l][e]-a[l][s-1];
	else if(s==0)	return a[l][e]-a[u-1][e];
	return 0;
}

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
	for(int i=0;i<m;++i){
		int sum=0;
		for(int j=0;j<n;++j){
			sum+=a[i][j];
			a[i][j] = sum;
		}
	}
	for(int j=0;j<m;++j){
		int sum=0;
		for(int i=0;i<n;++i){
			sum+=a[i][j];
			a[i][j] = sum;
		}
	}
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < m; ++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	ll sum=0;
	for(int u=0;u<m;++u){
		for(int l=u;l<m;++l){
			for(int s=0;s<n;++s){
				for(int e=s;e<n;++e){
					sum+=subMatrix(s,e,u,l);
				}	
			}
		}	
	}
	cout<<endl<<"Sum is : "<<sum<<endl;
	return 0;
}

// Question : We are supposed to find the sum of all the submatrix formed using
// a single matrix the above inpmlementation takes O(N^4) time for evaluating the 
// sum and the space requirement is O(1).

// Sample Input :

// 4 4
// 1 1 1 1 
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1

// Sample Output :

// 1 2 3 4 
// 2 4 6 8 
// 3 6 9 12 
// 4 8 12 16 

// Sum is : 400