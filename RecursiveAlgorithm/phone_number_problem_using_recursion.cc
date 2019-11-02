#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

char alpha[10][5]={
				"",
				"",
				"ABC",
				"DEF",
				"GHI",
				"JKL",
				"MNO",
				"PQRS",
				"TUV",
				"WXYZ"
			};

void genrate_names(char* n,char* name,int k){
	if(n[0]=='\0'){
		name[k]='\0';
		cout<<name<<endl;
		return;
	}
	int t=n[0]-'0';
	if(t==0||t==1) genrate_names(n+1,name,k); 
	for(int i=0;alpha[t][i]!='\0';++i){
		name[k++]=alpha[t][i];
		genrate_names(n+1,name,k);
		k--;
	}
	return;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char num[20],out[20];
	cin >> num;
	genrate_names(num,out,0);
	return 0;
}