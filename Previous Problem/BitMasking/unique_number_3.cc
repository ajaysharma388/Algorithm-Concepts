#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define r(n) scanf("%d",&n)
#define w(n) printf("%d ",n)
#define rep(i,n) for(int i=0;i<n;++i)
#define s string

int findUniqueNumber(int *a,int n){
	int num[64]={0};
	for(int i=0;i<n;++i){
		int cur_num = a[i];
		int j=0;
		while(cur_num>0){
			num[j]+=cur_num&1;
			j++;
			cur_num = cur_num>>1;
		}
	}
	int ans=0;
	int p=1;
	for(int i=0;i<64;++i){
		num[i]%=3;
		ans+=num[i]*p;
		p<<=1;
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	r(n);
	int a[n];
	rep(i,n) r(a[i]);
	//rep(i,n) w(a[i]);
	cout<<findUniqueNumber(a,n)<<endl;
	return 0;
}