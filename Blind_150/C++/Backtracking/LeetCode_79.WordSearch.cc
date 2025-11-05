#include <bits/stdc++.h>
using namespace std;

void fastio(bool read = false) 
{
    if(read) 
    {
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

class Solution 
{
    int row, col, len;
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    string pattern;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = { 0, 1, 0,-1};
    vector<pair<int, int>> cords;

    bool dfs(int i, int r, int c)
    {
        // base case.
        // we found the solution.
        if(i >= len) return true;
        if(r < 0 or r >= row or c < 0 or c >= col or vis[r][c]) return false;
        // if we see the current character is not equal to char at r,c 
        // then we should not continue this path.
        if(grid[r][c] != pattern[i]) return false;
        vis[r][c] = true;
        cords.push_back({r, c});
        for(int x = 0; x < 4; ++x)
        {
            int _r = r+dx[x];
            int _c = c+dy[x];
            if(dfs(i+1, _r, _c)) return true;
        }
        vis[r][c] = false;
        cords.pop_back();
        return false;
    }

public:
    Solution() {}

    void validate() const {
        std::cout << "Row count: " << row << "\n";
        std::cout << "Column count: " << col << "\n";
        std::cout << "Pattern length: " << len << "\n";
        std::cout << "Pattern: " << pattern << "\n";

        std::cout << "Grid:\n";
        for (const auto& rowVec : grid) {
            for (char ch : rowVec) {
                std::cout << ch << " ";
            }
            std::cout << "\n";
        }

        std::cout << "Visited Matrix (vis):\n";
        for (const auto& rowVis : vis) {
            for (bool b : rowVis) {
                std::cout << (b ? "1" : "0") << " ";
            }
            std::cout << "\n";
        }
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        this->row = board.size();
        this->col = board[0].size();
        this->len = word.length();
        this->pattern = word;
        this->grid = board;
        this->vis = vector(row, vector<bool>(col, false));
        // validate();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                bool isFound = dfs(0, i, j);
                if(isFound) return true;
            }
        }
        return false;
    }

    void print(vector<char> &list)
    {
        cout << "[ ";
        for(char c: list)
            cout << c << " ";
        cout << "]\n";
    }

    void solve()
    {
        int r, c;
        string pattern;
        cin >> r >> c >> pattern;
        vector<vector<char>> board(r, vector<char>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                cin >> board[i][j];
        bool isFound = exist(board, pattern); 
        if(isFound)
        {
            cout << "We found the Pattern at ";
            for(auto data: cords)
            {
                cout << "[" << data.first << ", " << data.second << "] ";
            }
            cout << endl;
        }
        else
        {
            cout << "Unable to find the pattern in the grid" << endl;
        }
        return;
    }
};

int main() 
{
    fastio(true);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t) 
    {    
        Solution *s = new Solution();
        cout << "TestCase #" << t << " : ";
        s->solve();        
    }
    return 0;
}

/*
Sample Input:

5
3 3 AAB
C A A
A A A
B C D
3 4 CAT
A B C D
S A A T
A C A E
1 1 a
a
3 4 BAT
A B C D
S A A T
A C A E
3 4 ABCB
A B C D
S A A T
A C A E

Sample Output:

TestCase #1 : We found the Pattern at [1, 1] [1, 0] [2, 0] 
TestCase #2 : We found the Pattern at [0, 2] [1, 2] [1, 3] 
TestCase #3 : We found the Pattern at [0, 0] 
TestCase #4 : Unable to find the pattern in the grid
TestCase #5 : Unable to find the pattern in the grid

*/