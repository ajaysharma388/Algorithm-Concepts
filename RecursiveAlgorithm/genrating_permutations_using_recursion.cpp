#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void permutations(char *in,int j){
	if(in[j]=='\0'){
		cout<<in<<endl;
		return;
	}
	for(int i=j;in[i]!='\0';++i){
		swap(in[i],in[j]);
		permutations(in,j+1);
		// step for the backtracking.
		swap(in[j],in[i]);
	}
	return;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char in[20];
	cin >> in;
	permutations(in,0);
	return 0;
}