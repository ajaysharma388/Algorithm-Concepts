#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int find_unit_digit(int a,int b){
	if(a==0) return 0;
	if(a==1) return 1;
	if(b==1) return a;
	int res;
	res = find_unit_digit(a,b/2)%10;
	return (b&1)? (res*res*a)%10 : (res*res)%10;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int x,y;
	cin >> x >> y;
	cout<< find_unit_digit(x%10,y) << endl;
	return 0;
}