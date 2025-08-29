#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define endl "\n"
#define r(n) scanf("%lld",&n)
#define w(n) printf("%lld ",n)

int mul(int a,int b){
	if(b==1) return a;
	if(b==-1) return -1*a;
	return mul(a,b/2)+mul(a,b-b/2);
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
	// int n;
	// r(n);
	// int a[n]={};
	// for(int i=0;i<n;++i) r(a[i]);
	// (isSorted(a,n))
	// 	?cout<<"Sorted!\n"
	// 	:cout<<"Not Sorted!";
	// char a[100];
	// cin >> a;
	// int i=0;
	// while(a[i]!='\0') i++;
	// int num = toIntFromString(a,i-1);
	// cout<<num<<endl;
	string num_name[]={
				"zero ",
				"one ",
				"two ",
				"three ",
				"four ",
				"five ",
				"six ",
				"seven ",
				"eight ",
				"nine "			
				};
	int n;
	cin>>n;
	printString(num_name,n);
	return 0;
}