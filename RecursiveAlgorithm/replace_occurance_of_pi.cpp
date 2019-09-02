#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void replace_pi(string a,char *b,int i,int j){
	if(a[i]=='\0'){
		b[j]='\0';
		cout<<b<<endl;
		return;
	}
	if(a[i]=='p'&&a[i+1]=='i'){
		b[j++]='3';
		b[j++]='.';
		b[j++]='1';
		b[j++]='4';
		i+=2;
	}else{
		b[j++]=a[i++];
	}
	replace_pi(a,b,i,j);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	while(n--){
		string s;
		char ans[100];
		cin >> s;
		replace_pi(s,ans,0,0);
	}
	return 0;
}