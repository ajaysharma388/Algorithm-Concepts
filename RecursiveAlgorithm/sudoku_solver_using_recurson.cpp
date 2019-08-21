#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void printGrid(int grid[9][9]){
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}

bool check(int grid[9][9],int i,int j,int num){
	for(int k=0;k<9;++k){
		if(grid[i][k]==num) 
			return false;
		if(grid[k][j]==num)
			return false;
	}	
	int x = i/3,y = j/3;
	for(int m = x*3;m<=(x*3+2);++m)
		for(int n = y*3;n<=(y*3+2);++n)
			if(grid[m][n]==num) 
				return false;
	return true;
}

bool solveSudoku(int board[9][9],int row,int col){
    if(row == 9){
    	printGrid(board);
    	cout<<endl<<endl;
        return false;
    }
    if(col == 9){
        return solveSudoku(board,row+1,0);
    }
    if(board[row][col]!=0){
		//Skip the blue cell
		return solveSudoku(board,row,col+1);
	}
    for(int currNum = 1 ; currNum <= 9;++currNum){
        if(check(board,row,col,currNum)){
            board[row][col] = currNum;
            bool success = solveSudoku(board,row,col+1);
            if(success) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif
	int sudoku[9][9];
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			cin>>sudoku[i][j];
		}
	}	
	solveSudoku(sudoku,0,0);
	//printGrid(sudoku);
	return 0;
}

// Default puzzle.

// 7 0 1 0 2 0 8 0 6
// 0 6 0 0 8 0 0 9 0
// 5 0 2 6 0 9 0 1 0
// 9 0 0 2 0 0 7 0 5
// 0 4 5 0 7 6 0 2 0
// 2 0 0 0 5 0 0 0 4
// 1 5 0 4 0 0 0 7 0
// 0 0 8 0 1 0 2 0 0
// 4 0 0 7 0 8 0 5 3
