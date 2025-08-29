#include <iostream>

using namespace std;

int main(){
	string s;
	cin>>s;
	int l=s.length(),i=0;
	for(;i<l/2;++i){
		if(s[i]!=s[l-1-i]){
			cout<<"NO\n";
			break;
		}
	}
	if(i>=l/2){cout<<"YES\n";}
	return 0;
}