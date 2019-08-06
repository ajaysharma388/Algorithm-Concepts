#include <iostream>
#include <iomanip>
using namespace std;
const int D = 10;
printBoard(int board [D][D] , int n){
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
    int board[D][D] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    int n; cin >> n;
    bool isSucces = solveSudoku(board,n,0,2);
    if(isSucces){
        printBoard(board,n);
    }else{
        cout<<"Bro! Solve it your self."<<endl;
    }
    return 0;
}
