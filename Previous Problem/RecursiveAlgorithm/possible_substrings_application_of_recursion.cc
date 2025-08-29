#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void findSubStrings(char *a,char *b,int i,int j){
	if(a[i]=='\0'){
		b[j] = '\0';
		cout << b << " ";
		return;
	}
	findSubStrings(a,b,i+1,j);
	b[j++] = a[i++];
	findSubStrings(a,b,i,j);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	char ques[100],ans[100];
	cin>>ques;
	int l=strlen(ques);
	findSubStrings(ques,ans,0,0);
	cout<<pow(2,l)<<endl;
	return 0;
}