#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

static int possibleWays=0;
void printTable(char a[][10],int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

bool findWay(char a[][10],int r,int c,int n){
	bool flag;
	for(int i=c;i<n;++i){
		if(a[r][i]=='X') return false; 
		a[r][i]='*';
		if(a[r+1][i]!='X' && r<n-1){
			flag=findWay(a,r+1,i,n);
			if(flag) return true;
			a[r+1][i]='0';
		}
		if(r==n-1 && i==n-1){
			possibleWays++;
			printTable(a,n);
			return false;
		}
	}
	return false;
}


int main(){
	char a[10][10]={};
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>a[i][j];
		}
	}
	findWay(a,0,0,n);
	cout<<"Number of path's "<<possibleWays<<"."<<endl;
	return 0;
}