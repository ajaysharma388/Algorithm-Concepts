#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void convert_to_integer(char *a,int i){
	if(a[i]=='\0') return;
	cout<<a[i]-'0';
	convert_to_integer(a,i+1);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char str[200];
	cin>>str;
	convert_to_integer(str,0);
	return 0;
}