#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
static int possible=0;

bool isValidMove(int a[][10],int i,int j,int n){
	int x=i,y=j;
	while(x>=0){
		if(a[x][y]==1) return false;
		x--;
	}
	x=i;
	while(x>=0 && y<n){ // checking on the right diagonal.
		if(a[x][y]==1) return false;
		x--;y++;
	}
	x=i,y=j;
	while(x>=0 && y>=0){ // checking on the left diagonal.
		if(a[x][y]==1) return false;
		x--;y--;
	}
	return true;
}

void printBoard(int a[][10],int n){
	cout<<"\n****************\n\n";
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i][j]==1) cout<<"Q ";
			else cout<<"_ ";
		}
		cout<<endl; 
	}
	cout<<"\n****************\n";
}

bool placeQueen(int a[][10],int i,int n){
	// that will be possible if we have already 
	// filled the board with the n Queens.
	if(n==i){
		//printBoard(a,n); 
		// uncomment the above line to print all the possible 
		// arrangement's for the N-Queen Problem.
		possible++;	
	 	return false;
	}	
	bool flag=false;
	for(int j=0;j<n;++j){
		if(isValidMove(a,i,j,n)){
			a[i][j]=1;
			flag=placeQueen(a,i+1,n);
			if(flag) return true;	
			a[i][j]=0;
		}
	}
	return flag;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,a[10][10]={};
	cin >> n;
	placeQueen(a,0,n);
	cout<<possible<<endl;
	return 0;
}