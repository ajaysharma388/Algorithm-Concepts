#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

void printString(string *no,int n){
	if(n==0) return;
	int temp=n%10;
	printString(n/10,no);
	cout<<no[temp];
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	string num_name[]={
				"zero ",
				"one ",
				"two ",
				"three ",
				"four ",
				"five ",
				"six ",
				"seven ",
				"eight ",
				"nine "			
				};
	int n;
	cin>>n;
	printString(num_name,n);
	return 0;
}