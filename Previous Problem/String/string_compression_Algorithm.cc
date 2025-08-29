#include <iostream>
#define endl "\n"
using namespace std;

void compressString(string s,int n){
	int l=0,count=0,r=l;
	while(l<n){
		if(s[r]==s[l]){
			count++;
			r++;
		}else{
			cout<<s[l]<<count;
			l=r;
			count=0;
		}
	}
}
int main(){
	string s;
	cin>>s;
	int l = s.length();
	if(l>=1 && l<=100)
		compressString(s,l);
	return 0;
}