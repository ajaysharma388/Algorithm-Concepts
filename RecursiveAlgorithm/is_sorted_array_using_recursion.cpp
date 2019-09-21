#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)


bool is_sorted_array(int *a,int i){
	if(i==1 && a[i]>a[i-1])	return true;
	else if(i>1 && a[i]>a[i-1]) is_sorted_array(a,i-1);
	else return false; 
}

bool check(int *a,int s,int e){
	if(s==e) return true;
	if(a[s]<a[s+1] && check(a,s+1,e)) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	int n;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;++i) cin>>a[i];
	(is_sorted_array(a,n-1))
		?cout<<"Sorted!"<<endl
		:cout<<"Not Sorted!"<<endl;
	return 0;
}