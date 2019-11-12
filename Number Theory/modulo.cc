#include <iostream>

using namespace std;
#define ll long long
int main(){
	int n;
	cin>>n;
	ll A[n],ans=1,m=1000000007;
	for(int i=0;i<n;++i){
		cin>>A[i];
		ans=(ans*A[i])%m;
	}
	cout<<ans<<endl;
	return 0;
}
