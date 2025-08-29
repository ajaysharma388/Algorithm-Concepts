#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void sub_seq(char* a,char *b,int i){
	if(a[0]=='\0'){
		b[i]='\0';
		cout<<b<<endl;
		return;
	}
	b[i]=a[0];
	sub_seq(a+1,b,i+1);
	sub_seq(a+1,b,i);
}

void subsequences(char* in,char *out,int i,int j){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	out[j]=in[i];
	subsequences(in,out,i+1,j+1);
	subsequences(in,out,i+1,j);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char a[100],b[100];
	b[0]='\0';
	cin >> a;
	subsequences(a,b,0,0);
	return 0;
}