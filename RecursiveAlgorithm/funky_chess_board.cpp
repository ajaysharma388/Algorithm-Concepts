#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

const int row[] = {-2,-2,-1,1,2,2,1,-1};
const int col[] = {1,-1,2,2,1,-1,-2,-2};
const int D = 10;
bool board[D][D] = {};
int high;

void moveKnight(int i,int j,int count){
	if(i<0 || i>=D || j<0 || j>=D || board[i][j]==0) return;
	board[i][j] = 0;
	high = max(high,count+1);
	for(int k=0;k<8;++k){
		moveKnight(i+row[k],j+col[k],count+1);
	}
	board[i][j] = 1;
	return;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int set = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin >> board[i][j];
			set+=(board[i][j])?1:0;
		}
	}	
	high = 0;	
	moveKnight(0,0,0);
	cout<<set-high<<endl;
	return 0;
}