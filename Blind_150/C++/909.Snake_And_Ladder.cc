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


class Solution {
	int bfs(vector<int> &grid, int target)
	{
		queue<pair<int, int>> Q;
		vector<bool> vis(target+1, false);
        Q.push({1, 0});
        vis[1] = true;
        while(!Q.empty())
        {
        	int move = Q.front().first;
        	int score = Q.front().second;
        	// cout << "{" << move << ", " << score << "}\n";
        	Q.pop();
        	if(move == target)
        		return score;
        	// if the node is not already visited
        	for(int i = 1; i <= 6; ++i)
        	{
        		int next = move+i;
        		if(next > target) continue;
        		if(grid[next] != -1) next = grid[next];
        		if(vis[next]) continue;
        		Q.push({next, score+1});
        		vis[next] = true;
        	}
        }
        return -1;
	}

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        int n = board.size();
        for(int i = 0; i < n; ++i)
       		if(i & 1)
       			reverse(board[i].begin(), board[i].end());
        int m = n;
        vector<int> gr(m*n+1, -1);
        int node = 1;
        for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
        {
            if(board[i][j] != -1) gr[node] = board[i][j];
            node += 1;
        }
     
        return bfs(gr, m*n);
    }

    vector<vector<int>> getTestCase(int id)
	{
		switch(id)
		{
		    case 1:
			    return {
			        {-1, -1, -1, -1, -1, -1},
			        {-1, -1, -1, -1, -1, -1},
			        {-1, -1, -1, -1, -1, -1},
			        {-1, 35, -1, -1, 13, -1},
			        {-1, -1, -1, -1, -1, -1},
			        {-1, 15, -1, -1, -1, -1}
			    };
			case 2:
				return {
			        {-1, -1},
			        {-1,  3}
			    };
			case 3:
				return {
			        { 1,  1, -1},
			        { 1,  1,  1},
			        {-1,  1,  1}
			    };
			case 4:
				return {
			        {-1, -1, 19, 10, -1},
			        { 2, -1, -1,  6, -1},
			        {-1, 17, -1, 19, -1},
			        {25, -1, 20, -1, -1},
			        {-1, -1, -1, -1, 15}
				};
		}
		return {{}};
	}

	void print(vector<vector<int>> &grid)
    {
    	cout << "*******************************\n";
    	for(vector<int> list: grid)
    	{
	        cout << "[ ";
	        for(int c: list)
	            cout << c << " ";
	        cout << "]\n";
	    }
    }

	void solve(int testCase)
	{
		vector<vector<int>> board = this->getTestCase(testCase);
		cout << "TestCase #" << testCase << " : " << this->snakesAndLadders(board) << endl;
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
        s->solve(t);        
    }
    return 0;
}

/*

Sample Input:


Sample Output:


*/
