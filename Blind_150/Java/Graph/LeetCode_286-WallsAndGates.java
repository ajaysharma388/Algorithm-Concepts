public class Solution {
    private int[][] directions = {{1, 0}, {-1, 0},
                                  {0, 1}, {0, -1}};
    private int INF = 2147483647;
    private boolean[][] visit;
    private int ROWS, COLS;

    private int dfs(int[][] grid, int r, int c) {
        if (r < 0 || c < 0 || r >= ROWS ||
            c >= COLS || grid[r][c] == -1 || visit[r][c]) {
            return INF;
        }
        if (grid[r][c] == 0) {
            return 0;
        }
        visit[r][c] = true;
        int res = INF;
        for (int[] dir : directions) {
            int cur = dfs(grid, r + dir[0], c + dir[1]);
            if (cur != INF) {
                res = Math.min(res, 1 + cur);
            }
        }
        visit[r][c] = false;
        return res;
    }

    public void islandsAndTreasure(int[][] grid) {
        ROWS = grid.length;
        COLS = grid[0].length;
        visit = new boolean[ROWS][COLS];

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == INF) {
                    grid[r][c] = dfs(grid, r, c);
                }
            }
        }
    }
}