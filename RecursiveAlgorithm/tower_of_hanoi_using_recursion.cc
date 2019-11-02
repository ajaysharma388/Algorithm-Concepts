#include <iostream>   
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void tower_of_hanio(int n,char s,char d,char h){
	if(n==0) return;
	tower_of_hanio(n-1,s,h,d);
	cout<<"Move "<<n<<" disk from "<<s<<" to "<<d<<endl;
	tower_of_hanio(n-1,h,d,s);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	tower_of_hanio(n,'A','C','B');
	return 0;
}