#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void printPascalsTriangle(int n){
	int a[n][n]={0};
	int i=0;
	while(i<n){
		int j=0;
		while(j<=i){
			if(j==i || j==0){
				a[i][j] = 1;
			}else{
				a[i][j] = a[i-1][j-1]+a[i-1][j];
			}
			j++;
		}
		i++;
	}
	i=0;
	while(i<n){
		int j=0;
		while(j<=i){
			cout<<a[i][j]<<" ";
			j++;
		}
		cout<<endl;
		i++;
	}

}

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
	printPascalsTriangle(n);	
	return 0;
}