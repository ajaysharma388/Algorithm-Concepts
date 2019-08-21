#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// this method returns the pointer to the output array.
// as you can see in the signature of the function.

char* remove_duplicates_return(char *a,char *b,int i,int j){
	if(a[i]=='\0'){
		b[++j] = '\0';
		return b;
	}
	if(a[i]==b[j]) remove_duplicates_return(a,b,i+1,j);
	else{
		b[++j] = a[i];
		remove_duplicates_return(a,b,i+1,j);
	}
}


void remove_duplicates(char *a,char *b,int i,int j){
	if(a[i]=='\0'){
		b[++j] = '\0';
		cout<<b<<endl;
		return;
	}
	if(a[i]==b[j]) remove_duplicates(a,b,i+1,j);
	else{
		b[++j] = a[i];
		remove_duplicates(a,b,i+1,j);
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char in[1000],out[1000];
	cin>>in;
	out[0] = in[0];
	cout<<remove_duplicates_return(in,out,1,0)<<endl;
	remove_duplicates(in,out,1,0);
	return 0;
}