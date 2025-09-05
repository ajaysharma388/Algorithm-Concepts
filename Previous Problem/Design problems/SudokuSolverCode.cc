#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class SudokuSolver 
{
    bool canPlace(vector<vector<int>> &sudoku, int row, int col, int curNum)
    {
        if(sudoku[row][col] != 0) return false;
        // check in the column. 
        for(int i = 0; i < 9; ++i)
            if(sudoku[i][col] == curNum or sudoku[row][i] == curNum)
                return false;
        row = row/3*3;
        col = col/3*3;
        // check in the block.
        for(int x = row; x < row+3; ++x)
            for(int y = col; y < col+3; ++y)
                if(sudoku[x][y] == curNum) return false;
            
        return true;
    }

    bool helperDFS(vector<vector<int>> &sudoku, int x, int y)
    {
        if(x == 9) return true;
        if(y == 9) return helperDFS(sudoku, x+1, 0);
        if(sudoku[x][y] != 0) return helperDFS(sudoku, x, y+1);
        for(int num = 1; num <= 9; ++num)
        {
            if(canPlace(sudoku, x, y, num))
            {
                sudoku[x][y] = num;
                bool isSolved = helperDFS(sudoku, x, y+1);
                if(isSolved) return true;
                sudoku[x][y] = 0;
            }
        }
        return false;
    }

public:
    bool solveSudoku(vector<vector<int>>& board)
    {
        return helperDFS(board, 0, 0);
    }
};

int main() {
    fastio();
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; ++i)
    {
        vector<vector<int>> board(9, vector<int>(9, 0)); 
        for(int i = 0; i < 9; i++) 
        {
            for(int j = 0; j < 9; j++) 
            {
                cin >> board[i][j];
            }
        }   
        SudokuSolver *sudoku = new SudokuSolver();
        bool isSolved = sudoku->solveSudoku(board);
        cout << "TestCase #" << i << " : \n";
        if( isSolved ) 
        {
            for(int i = 0; i < 9; i++) 
            {
                for(int j = 0; j < 9; j++) 
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            } 
        }
        else
        {
            cout << "Invalid Sudoku" << endl;
        }
    }
    return 0;
}   

/*

Sample Input:

1
0 0 0 0 0 0 0 0 0
0 7 4 2 0 6 0 0 0
0 5 0 0 4 0 2 0 3
0 4 0 0 0 0 5 7 0
0 0 5 0 0 0 0 0 2
0 6 0 0 0 7 3 8 0
0 0 1 3 0 9 0 0 0
0 0 0 6 0 2 0 0 0
0 0 9 0 8 0 0 0 0

Sample Output:

TestCase #1 : 
2 9 8 1 3 5 7 6 4 
3 7 4 2 9 6 8 1 5 
1 5 6 7 4 8 2 9 3 
8 4 3 9 2 1 5 7 6 
7 1 5 8 6 3 9 4 2 
9 6 2 4 5 7 3 8 1 
4 2 1 3 7 9 6 5 8 
5 8 7 6 1 2 4 3 9 
6 3 9 5 8 4 1 2 7 
*/