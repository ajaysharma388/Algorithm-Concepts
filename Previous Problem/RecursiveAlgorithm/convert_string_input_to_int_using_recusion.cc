#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

int fastPower(int a,int b){
	return (b==1)
		?a
		:fastPower(a,b/2)*fastPower(a,b-b/2);
}
int toIntFromString(char *a,int n){
	return (a[1]=='\0')
		? a[0]-'0'
		: (a[0]-'0')*fastPower(10,n)+toIntFromString(a+1,n-1);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	char a[100]={};
	cin>>a;	
	int i=0;
	while(a[i]!='\0'){i++;}
	int num = toIntFromString(a,i-1);
	cout<<num<<endl;
	return 0;
}