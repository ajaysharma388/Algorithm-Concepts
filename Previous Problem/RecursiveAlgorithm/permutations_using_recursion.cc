#include<bits/stdc++.h>
using namespace std;

void permute(char *a,int i,int n){
	if(i==(n-1)){
		cout<<a<<endl;
		return;
	}
	for(int k=i;k<n;++k){
		swap(a[i],a[k]);
		permute(a,i+1,n);
		swap(a[i],a[k]);
	}
	return;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	char a[100];
	cin>>a;
	int l = strlen(a);
	permute(a,0,l);
	return 0;
}