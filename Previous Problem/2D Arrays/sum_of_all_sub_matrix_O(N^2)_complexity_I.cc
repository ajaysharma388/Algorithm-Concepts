#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// prototype declaration of function.
ll sumOfSubMatrix(int**,int,int);

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin >> m >> n;
	int **a = new int*[m];
	for(int i=0;i<m;++i){
		a[i] = new int[n];
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> a[i][j];
		}
	}	
	// Function call.
	cout<<"Sum is : "<<sumOfSubMatrix(a,m,n)<<endl;
	for(int i=0;i<m;++i){
		delete []a[i];
	}
	delete []a;
	return 0;
}

// Function Defination.
ll sumOfSubMatrix(int **a,int m,int n){
	ll sum=0;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			sum+=a[i][j]*((i+1)*(j+1))*((m-i)*(n-j));
		}
	}
	return sum;
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

// 4 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// Sample Output :

// Sum is : 400

// Sum is : 3400