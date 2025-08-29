#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define s string

s move_x(s s0,s s1,s s2,int i){
	if(s0.length()==i){
		s1.append(s2);
		return s1;
	}
	if(s0[i]=='x'){
		s2+='x';
	}else{
		s1+=s0[i];
	}
	return move_x(s0,s1,s2,i+1);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	s que;
	cin >> que;
	cout << move_x(que,"","",0) <<endl;
	return 0;
}