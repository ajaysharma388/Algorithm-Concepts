#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int li[11] = {0,0,0,0,0,0,0,0,0,0,0};
string searchIn [] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
string keys[] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int findMax(){
	int m=0;
	for(int i=0;i<11;++i) m=max(m,li[i]);
	return m;
}
void advanceKey(string str,int i){
	if(str.length()==i){
		int m=findMax();
		for(int i=10;i>=0;--i)
			if(li[i]==m) 
				cout<<searchIn[i]<<endl;
			return;
	}
	string s=keys[str[i]-'0'];
	for(int k=0;k<11;++k){
		bool flag=false;
		for(int j=0;s[j]!='\0';++j){
			if(searchIn[k].find(s[j]) != string::npos)
				flag=true;
		}
		if(flag) li[k]++;
	}
	advanceKey(str,i+1);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	string s;
	cin >> s;
	advanceKey(s,0);
	return 0;
}

