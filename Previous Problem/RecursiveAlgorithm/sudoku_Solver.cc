#include <bits/stdc++.h>
using namespace std;
const int D = 10;

void printBoard(int board [D][D] , int n){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ;++j){
            cout<<setw(2)<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool canPlace(int board[D][D],int n,int row,int col,int currNum){
    if(board[row][col] != 0) return false;
    for(int i = 0 ; i < n ;++i){
        if(board[row][i] == currNum) return false; // as row already contained that number.
        if(board[i][col] == currNum) return false; // as col already contained that number.
    }
    int r = row,c = col;
    while(r%3!=0){
        r--;
    }
    while(c%3!=0){
        c--;
    }
    for(int i = r ; i < r+3 ; ++i){
        for(int j = c ; j < c+3 ; ++j){
            if(board[i][j] == currNum)
                return false;  // as number is already in the small box.
        }
    }
    return true;
}

bool solveSudoku(int board[D][D] , int n , int row , int col){
    if(row == n){
        return true;
    }
    if(col == n){
        return solveSudoku(board,n,row+1,0);
    }
    if(board[row][col]!=0){
		//Skip the blue cell
		return solveSudoku(board,n,row,col+1);
	}
    //int rootn = sqrt(n);
    for(int currNum = 1 ; currNum <= n;++currNum){
        if(canPlace(board,n,row,col,currNum)){
            board[row][col] = currNum;
            bool success = solveSudoku(board,n,row,col+1);
            if(success) return true;
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,grid[D][D];
    cin >> n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> grid[i][j];
        }
    }
    bool isSuccess = solveSudoku(grid,n,0,0);
    printBoard(grid,n);
    return 0;
}
