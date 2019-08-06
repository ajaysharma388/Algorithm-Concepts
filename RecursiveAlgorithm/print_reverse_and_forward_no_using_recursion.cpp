#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)


void reverse(int n){
	cout<<n<<" ";
	if(n==1) return;
	reverse(n-1);
}

void forward(int n){
	if(n==1){
		cout<<n<<" ";
		return;
	}
	forward(n-1);
	cout<<n<<" ";
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin>>n;
	reverse(n);
	cout<<endl;
	forward(n);
	return 0;
}