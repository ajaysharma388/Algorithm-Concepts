class Solution {
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    void dfs(int i, int j, int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        if(i < 0 or i >= r or j < 0 or j >= c) return;
        else if (vis[i][j] or grid[i][j] != '1') return;
        vis[i][j] = true;
        for(int k = 0; k < 4; ++k)
            dfs( i+directions[k][0], j+directions[k][1], r, c, grid, vis);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        if(grid[i][j] == '1' and !vis[i][j])
        {
            cnt += 1;
            dfs(i, j, m, n, grid, vis);
        }
        return cnt;
    }
};