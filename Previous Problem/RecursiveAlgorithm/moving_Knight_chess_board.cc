#include <iostream>
#include <iomanip>
using namespace std;
const int D = 8;
int row[] = {-2,-1,1,2,2,1,-1,-2};
int col[] = {1,2,2,1,-1,-2,-2,-1};

bool canPlace(int board[D][D] , int n , int row ,int col){
    //if((row > -1 && row < n) && (col > -1 && col < n) && board[row][col] == 0)
    //    return true;
    //return false;
    return row >= 0 && row < n &&
           col >= 0 && col < n &&
           board[row][col] == 0;
}
bool solveKnight(int board[D][D],int n,int move_no,int currRow,int currCol){
    if(move_no == n*n)
        return true;
    for(int currDir = 0 ; currDir < 8 ;++currDir){
        int nextRow = currRow+row[currDir];
        int nextCol = currCol+col[currDir];
        if(canPlace(board,n,nextRow,nextCol)){
            board[nextRow][nextCol] = move_no+1;//place the knight
            bool isSucces = solveKnight(board,n,move_no+1,nextRow,nextCol);
            if(isSucces)
                return true;
            board[nextRow][nextCol] = 0;// erase the knight
        }
    }
    return false;
}
void printBoard(int board[D][D],int n){
    for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                cout<< setw(3)<< board[i][j] <<" ";
            }
            cout<<endl;
        }
}
int main()
{
    int Board[D][D] = {0};
    int n;
    cin>>n;
    Board[0][0] = 1;
    bool ans = solveKnight(Board,n,1,0,0);
    if(ans){
        printBoard(Board,n);
    }else{
        cout<<"Sorry Man Can't visit your board!"<<endl;
    }
    return 0;
}

