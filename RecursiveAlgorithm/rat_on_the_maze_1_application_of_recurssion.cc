#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

static int possibleWays=0;

void printRoute(int a[][10],int m,int n){
	for(int i=0;i<=m;++i){
		for(int j=0;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

bool ratInMaze(char maze[][10],int soln[][10],
	int i,int j,
	int m,int n){
	// base case.
	if(i==m && j==n){
		soln[i][j]=1;
		possibleWays++;
		printRoute(soln,m,n);
		return true;
	}
	// checking if the rat went out of the board.
	if(i>m || j>n) return false;
	// here, checking if the route through the current 
	// position is possible or not.
	if(maze[i][j]=='X') return false;
	soln[i][j]=1;
	bool rightSuccess = ratInMaze(maze,soln,i,j+1,m,n);
	bool leftSuccess = ratInMaze(maze,soln,i+1,j,m,n);
	soln[i][j]=0;
	if(leftSuccess||rightSuccess) return true;
	return false;
}


int main(){
	char maze[10][10]={0};
	int soln[10][10]={0};
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int m,n;
	cin >> m >> n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>maze[i][j];
		}
	}
	bool ans = ratInMaze(maze,soln,0,0,m-1,n-1);
	if(!ans){
		cout<<"Route Doesn't exists."<<endl;
	}else{
		cout<<"Number of path's "<<possibleWays<<"."<<endl;
	}
	return 0;
}