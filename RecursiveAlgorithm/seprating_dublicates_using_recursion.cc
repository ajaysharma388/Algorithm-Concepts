#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void seprate_duplicates(char *a,int i){
	if(a[i+1]=='\0'){
		cout<<a[i];
		return;
	}
	if(a[i]==a[i+1]) cout<<a[i]<<"*";
	else cout<<a[i];
	seprate_duplicates(a,i+1);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char str[200];
	cin >> str;
	seprate_duplicates(str,0);
	return 0;
}