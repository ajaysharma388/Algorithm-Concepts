#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

using namespace std;
int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,a,b,c1,c2;
	cin>>n;
	if(n==1||n==2){
		cout<<"-1"<<endl;
	}else{
        if(n%2==0){
			a=n/2;
			b=1;
			cout<<pow(a,2)-1<<" "<<pow(a,2)+1;
		}else{
			a=(n+1)/2;
			b=(n-1)/2;
			cout<<2*a*b<<" "<<pow(a,2)+pow(b,2);
		}
    }
    return 0;
}