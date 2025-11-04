class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    int INF = 2147483647;
    vector<vector<bool>> visit;
    int ROWS, COLS;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || grid[r][c] == -1 || visit[r][c]) {
            return INF;
        }
        if (grid[r][c] == 0) {
            return 0;
        }
        visit[r][c] = true;
        int res = INF;
        for (auto& dir : directions) {
            int cur = dfs(grid, r + dir[0], c + dir[1]);
            if (cur != INF) {
                res = min(res, 1 + cur);
            }
        }
        visit[r][c] = false;
        return res;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == INF) {
                    grid[r][c] = dfs(grid, r, c);
                }
            }
        }
    }
};